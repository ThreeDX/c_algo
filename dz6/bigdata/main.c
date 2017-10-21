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

// ��� �������� ����������� id ������
unsigned int crc(char* str) {
	unsigned int c = 0;
	while (*str != '\0')
		c += *str++;
	return c;
}

////////// ���� ������ ///////////
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
} Student; // ������ � ��������

typedef struct NodeStudent {
	struct NodeStudent* next;
	Student* data;
} NodeStudent; // ������� ������ ���������

typedef struct {
	NodeStudent* head;
	int size;
} StackStudents; // ���� ���������

typedef struct TreeNode {
	NodeStudent* data;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
} TreeNode; // ������� ������ ���������

// �������� ������ ���� ������
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

// id ������
long long getCRC(Student *s)
{
	return crc(s->univercity) * 1000 + crc(s->faculty) * 100 + crc(s->department) * 10 + s->course;
}

// �������� ������ �������� ������
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
// ������� ����
// ���������� �������� ������������ � ������ �� ����� ����
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

// ��������� ������ ������, �� ������� ��� �� ������
TreeNode* getSearchTree(NodeStudent* head, int isGroup) {
	TreeNode* tree = NULL;
	while (head) {
		insertNodeStudent(&tree, head->data, isGroup);
		head = head->next;
	}
	return tree;
}

// ���������� ��������� � ����
void pushStack(StackStudents* stack, Student* value) {
	stack->head = getNewNodeStudent(stack->head, value);
	stack->size++;
}

// ���������� ����� ��� � ������
int getTreeSize(TreeNode* tree)
{
	if (tree)
		return 1 + getTreeSize(tree->left) + getTreeSize(tree->right);
	else
		return 0;
}

// ������ ������ �� �����
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
// ����� ��������� � ����
void printStudents(NodeStudent* node, FILE *f) {
	if (node) {
		fprintf(f, "%s %s\n", node->data->secondName, node->data->firstName);
		printStudents(node->next, f);
	}
}

// ����� ������ ���������
void printTreeStudents(TreeNode* root, FILE *f) {
	if (root) {
		printTreeStudents(root->left, f);
		printStudents(root->data, f);
		printTreeStudents(root->right, f);
	}
}

// ��������� ����������
void fillHashTable(NodeStudent* node, StackStudents* hash)
{
	if (node) {
		pushStack((hash + (node->data->course - 1)), node->data);
		fillHashTable(node->next, hash);
	}
}

// �������� ���� ��� ��������
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
	printf("��������� ����... ");
}
/*
 * Main function
 */
int main(int argc, char* argv[]) {
	FILE *f;
	StackStudents students; // ���� ���������, ���� ����� ����������� ������ �� �����.
	Student *s;
	TreeNode* searchTreeName = NULL; // ������ ��� ������ �� �������
	TreeNode* searchTreeGroup = NULL; // ������ ��� ������ �� ������ ������
	StackStudents* HashTableCources;
	char line[100];
	clock_t t1, t2;
	students.head = NULL;
	students.size = 0;
	int mag = 0, bak = 0;

	setlocale(LC_ALL, "Russian");
	printf("Dmitry Panfilov �������� ������ �6 - BigData\n");

	// �������������� ��� ������� ��� ������
	HashTableCources = (StackStudents*)calloc(6, sizeof(StackStudents));

	// ��������� ���� ���������
	getFile(&f);
	if (f == NULL)
		exit(EXIT_FAILURE);
	
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// ��������� ������ ������ � ����������
	fgets(line, 100, f);
	// ��������� ��������� �� ����� � �������� � ����
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
	printf("\n����� ���������: %d\n����������: %d\n���������: %d\n\n", students.size, bak, mag);

	printf("������ ������ ������ �� �������... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// ������� ������� ������
	searchTreeName = getSearchTree(students.head, 0);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("������ ������ ������ �����... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// ������� ������� ������
	searchTreeGroup = getSearchTree(students.head, 1);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("\n����� �����: %d\n\n", getTreeSize(searchTreeGroup));

	// ������ ����������
	printf("������ ���������� ��������� �� ������... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// ��������� ���������� ���������� �� ������
	fillHashTable(students.head, HashTableCources);
	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	for(int i = 0; i< 6; i++)
		printf("\n%d ����: %d ���������", i+1, (HashTableCources + i)->size);


	printf("\n\nstudents.txt - ��������� ��������� � ���������� �������... ");
	t1 = clock() / (CLOCKS_PER_SEC / 1000);

	// ������� ������ ��������� � ���������� ������� (�� �������, ������ ������� � ���)
	f = fopen("students.txt", "w");
	if (f == NULL)
		exit(EXIT_FAILURE);

	// ������� � ����
	printTreeStudents(searchTreeName, f);
	fclose(f);

	t2 = clock() / (CLOCKS_PER_SEC / 1000);
	printf("%lu ms\n", (t2 - t1));

	printf("end");

	getch();
	return 0;
}