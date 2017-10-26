/*
* Dmitry Panfilov
* HomeWork 7
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

#define maxHeight 25
#define maxWidth 25
int matrix[maxHeight][maxWidth];

typedef struct GraphNode {
	int value;
	int index;
	int isChecked;
	struct GraphNode* qnext;
	struct GraphNode* qprev;
} GraphNode;

typedef struct MatrixNode {
	char from;
	char to;
	int len;
	struct MatrixNode* next;
} MatrixhNode;

// Считывает размер матрицы (определяет посодержимому)
void readMatrixSize(FILE* f, int* width, int* height) {
	int lines = 0;
	int commas = 0;
	int max = 0;
	while (!feof(f)) {
		char c;
		fscanf(f, "%c", &c);
		if (c == ',')
			commas++;

		if (c == '\n') {
			lines++;
			if (commas > max)
				max = commas;
			commas = 0;
		}
	}
	*height = lines + 1;
	*width = max + 1;
}

// Считывает матрицу
void readMatrix(FILE* f, int size) {
	int i = 0, j = 0;
	while (!feof(f)) {
		char c;
		fscanf(f, "%d%c", &matrix[i][j], &c);
		j++;
		if (c == '\n' || c == '\r') {
			j = 0;
			i++;
		}
	}
}

// Выводит матрицу на экран
void printMatrix(int size) {
	int i, j;
	for (i = -1; i < size; i++) {
		for (j = -1; j < size; j++)
			(j < 0) ? printf("%c ", (i < 0) ? ' ' : 65 + i)
			: (i < 0) ? printf("%c ", 65 + j) : printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

// Очередь
typedef struct Queue {
	GraphNode* head;
	GraphNode* tail;
	int size;
} Queue;

// Вставка в очередь
void qPush(Queue* q, int value) {
	GraphNode* tmp = (GraphNode*)malloc(sizeof(GraphNode));
	if (tmp == NULL) {
		printf("Not enough memory\n");
		return;
	}
	tmp->qnext = q->head;
	tmp->qprev = NULL;
	tmp->value = value;
	tmp->index = q->size;
	if (q->head == NULL) {
		q->tail = tmp;
	}
	else {
		q->head->qprev = tmp;
	}
	q->head = tmp;
	q->size++;
}

// Извлечение из очереди
int qPop(Queue* q) {
	if (q->size == 0) {
		printf("Empty queue\n");
		return -1;
	}
	int value = q->tail->value;
	GraphNode* tmp = q->tail;
	q->tail = q->tail->qprev;
	if (q->size > 1) {
		q->tail->qnext = NULL;
	}
	else {
		q->head = NULL;
	}
	q->size--;
	free(tmp);

	return value;
}

// Обход в глубину
int isChecked[maxWidth] = { 0 }; // Массив для отметки посещенных узлов

int depthTravers(int start, int goal, int size) {
	printf("%c", 65 + start);
	if (start == goal || isChecked[start]) {
		return 1;
	}
	else {
		isChecked[start] = 1;
		int j;
		for (j = 0; j < size; j++)
			if (matrix[start][j] == 1 && isChecked[j] == 0)
				return 1 + depthTravers(j, goal, size);
	}
	return 0;
}

// Обход в ширину
Queue q;
int used[maxWidth] = { 0 };
int widthTravers(int start, int goal, int size) {
	qPush(&q, start);
	int steps = 0;
	while (q.size > 0) {
		int value = qPop(&q);
		if (used[value] == 1) continue;
		used[value] = 1;

		printf("%c", 65 + value);
		steps++;
		if (value == goal) {
			return steps;
		}

		int i;
		for (i = 0; i < size; i++) {
			if (matrix[value][i] == 1 && used[i] == 0)
				qPush(&q, i);
		}
	}
	return -1;
}

// преобразование в структуру
MatrixhNode* transformMatrix(int size) {
	MatrixhNode* m = NULL;
	MatrixhNode* p = NULL;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (matrix[i][j]) {
				p = (MatrixhNode*)malloc(sizeof(MatrixhNode));
				if (!p) {
					puts("Memory fail");
					exit(1);
				}
				p->next = m;
				p->from = 65 + i;
				p->to = 65 + j;
				p->len = matrix[i][j];
				m = p;
			}
		}
	}
	return p;
}

// Печатет новую структуру
void printTransform(MatrixhNode* p) {
	MatrixhNode* m = p;
	while (m) {
		printf("%c->%c: %d\n", m->from, m->to, m->len);
		m = m->next;
	}
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
	int h;
	int w;
	FILE* file;

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №7\n");
    
	file = fopen("matrix.csv", "r");
	if (file == NULL)
		return 1;

	readMatrixSize(file, &w, &h);
	if (h != w) {
		printf("Матрица должна быть квадратной.");
		return 1;
	}
	printf("h=%d, w=%d\n\n", h, w);
	rewind(file);
	readMatrix(file, w);
	fclose(file);

	printMatrix(w);
	puts("");

	printf(": В глубину (B->E): %d\n", depthTravers(1, 4, 6));
	printf(": В ширину (B->E): %d\n\n", widthTravers(1, 4, 6));

	printTransform(transformMatrix(w));

    getch();
    return 0;
}