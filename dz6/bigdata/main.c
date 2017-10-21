/*
* Dmitry Panfilov
* HomeWork 6 - BigData
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Для создания уникального id группы
unsigned int crc(char* str) {
	unsigned int c = 0;
	while (*str != '\0')
		c += *str++;
	return c;
}

////////// База данных ///////////
typedef struct {
	char firstName[64];
	char secondName[64];
	char univercity[64];
	char faculty[64];
	char department[64];
	int age;
	int course;
	int group;
	char city[64];
} Student; // Запись о студенте

typedef struct NodeStudent {
	struct NodeStudent* next;
	Student* data;
} NodeStudent; // Элемент списка студентов

typedef struct {
	NodeStudent* head;
	int size;
} StackStudents; // Стек Студентов

typedef struct TreeNode {
	NodeStudent* data;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
} TreeNode; // Элемент дерева студентов

// Создание нового узла дерева
TreeNode* getNewTreeNodeStudent(NodeStudent *value, TreeNode* parent) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	if (tmp == NULL) {
		printf("Stack Overflow");
		return NULL;
	}
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// id группы
long long getCRC(Student *s)
{
	return crc(s->univercity) * 1000 + crc(s->faculty) * 100 + crc(s->department) * 10 + s->course;
}

// Создание нового элемента списка
NodeStudent* getNewNodeStudent(NodeStudent* head, Student* data) {
	NodeStudent* tmp = (NodeStudent*)malloc(sizeof(NodeStudent));
	if (tmp == NULL) {
		printf("Stack Overflow");
		return NULL;
	}
	tmp->data = data;
	tmp->next = head;
	return tmp;

}
// Вставка узла
// Одинаковые значения объединяются в список на одном узле
void insertNodeStudent(TreeNode **head, Student* value, int isGroup) {
	int isRight = 0;
	if (*head == NULL) {
		*head = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), NULL);
		return;
	}

	if (isGroup)
	{
		long long crc1 = getCRC(value);
		long long crc2 = getCRC((*head)->data->data);
		if (crc1 == crc2) {
			(*head)->data = getNewNodeStudent((*head)->data, value);
			return;
		}
		isRight = (crc1 > crc2);
	}
	else
	{
		isRight = strcmp(value->secondName, (*head)->data->data->secondName);
		if (isRight == 0) {
			(*head)->data = getNewNodeStudent((*head)->data, value);
			return;
		}
		isRight = (isRight > 0);
	}

	if (isRight) {
		if ((*head)->right)
			insertNodeStudent(&(*head)->right, value, isGroup);
		else
			(*head)->right = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), *head);
	}
	else {
		if ((*head)->left)
			insertNodeStudent(&(*head)->left, value, isGroup);
		else
			(*head)->left = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), *head);
	}
}

// Генерация дерева поиска, по фамилии или по группе
TreeNode* getSearchTree(NodeStudent* head, int isGroup) {
	TreeNode* tree = NULL;
	while (head) {
		insertNodeStudent(&tree, head->data, isGroup);
		head = head->next;
	}
	return tree;
}

// Добавление студентов в стек
void pushStack(StackStudents* stack, Student* value) {
	stack->head = getNewNodeStudent(stack->head, value);
	stack->size++;
}

// Возвращает число нод в дереве
int getTreeSize(TreeNode* tree)
{
	if (tree)
		return 1 + getTreeSize(tree->left) + getTreeSize(tree->right);
	else
		return 0;
}

// Чтение данных из файла
Student* readCSV(FILE* f) {
	Student* s = (Student*)malloc(sizeof(Student));
	if (0 < fscanf(f, "%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%[^;];\r\n", &s->firstName, &s->secondName, &s->univercity,
		&s->faculty, &s->department, &s->age, &s->course, &s->group, &s->city))
	{
		//printf("%s\n", &s->firstName);
		return s;
	}
	else
	{
		free(s);
		return NULL;
	}
}
// Вывод студентов а файл
void printStudents(NodeStudent* node, FILE *f) {
	if (node) {
		fprintf(f, "%s %s\n", node->data->secondName, node->data->firstName);
		printStudents(node->next, f);
	}
}

// Вывод списка студентов
void printTreeStudents(TreeNode* root, FILE *f) {
	if (root) {
		printTreeStudents(root->left, f);
		printStudents(root->data, f);
		printTreeStudents(root->right, f);
	}
}

// Заполняем хэштаблицу
void fillHashTable(NodeStudent* node, StackStudents* hash)
{
	if (node) {
		pushStack((hash + (node->data->course - 1)), node->data);
		fillHashTable(node->next, hash);
	}
}

// Выбираем файл для загрузки
void getFile(FILE **f)
{
	int i;
	do {
		printf("1. students_1.csv\n");
		printf("2. students_2.csv\n");
		printf("3. students_3.csv\n");
		printf("4. students_4.csv\n");
		printf("5. students_5.csv\n");
		printf("6. students_6.csv\n");
		scanf("%i", &i);
	} while (i < 1 || i>6);
	switch (i) {
	case 1:
		*f = fopen("students_1.csv", "r");
		break;
	case 2:
		*f = fopen("students_2.csv", "r");
		break;
	case 3:
		*f = fopen("students_3.csv", "r");
		break;
	case 4:
		*f = fopen("students_4.csv", "r");
		break;
	case 5:
		*f = fopen("students_5.csv", "r");
		break;
	case 6:
		*f = fopen("students_6.csv", "r");
		break;
	}
	printf("Загружаем файл... ");
}
/*
 * Main function
 */
int main(int argc, char* argv[]) {
	FILE *f;
	StackStudents students; // Стек студентов, сюда будут загружаться данные из файла.
	Student *s;
	TreeNode* searchTreeName = NULL; // Дерево для поиска по фамилии
	TreeNode* searchTreeGroup = NULL; // Дерево для поиска по номеру группы
	StackStudents* HashTableCources;
	char line[100];
	clock_t t1, t2;
	students.head = NULL;
	students.size = 0;
	int mag = 0, bak = 0;

	setlocale(LC_ALL, "Russian");
	printf("Dmitry Panfilov Домашняя работа №6 - BigData\n");

	// Инициализируем хэш таблицу для курсов
	HashTableCources = (StackStudents*)calloc(6, sizeof(StackStudents));

	// Открываем базу студентов
	getFile(&f);
	if (f == NULL)
		exit(EXIT_FAILURE);
	
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// Считываем первую строку с заголовком
	fgets(line, 100, f);
	// Считываем студентов из файла и помещаем в стек
	while (s = readCSV(f)) {
		pushStack(&students, s);
		if (s->course > 4)
			++mag;
		else
			++bak;
	}
	fclose(f);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));
	printf("\nЧисло студентов: %d\nБакалавров: %d\nМагистров: %d\n\n", students.size, bak, mag);

	printf("Строим дерево поиска по фамилии... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// Создаем деревья поиска
	searchTreeName = getSearchTree(students.head, 0);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("Строим дерево поиска групп... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// Создаем деревья поиска
	searchTreeGroup = getSearchTree(students.head, 1);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("\nЧисло групп: %d\n\n", getTreeSize(searchTreeGroup));

	// Строим хэштаблицу
	printf("Строим хэштаблицу студентов по курсам... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// Заполняем хэштаблицу студентами по курсам
	fillHashTable(students.head, HashTableCources);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	for(int i = 0; i< 6; i++)
		printf("\n%d курс: %d студентов", i+1, (HashTableCources + i)->size);


	printf("\n\nstudents.txt - Сохраняем студентов в алфавитном порядке... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// Создаем список студентов в алфавитном порядке (по фамилии, Только Фамилия и имя)
	f = fopen("students.txt", "w");
	if (f == NULL)
		exit(EXIT_FAILURE);

	// Выводим в файл
	printTreeStudents(searchTreeName, f);
	fclose(f);

	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("end");

	getch();
	return 0;
}