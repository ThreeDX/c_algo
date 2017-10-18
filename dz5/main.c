/*
* Dmitry Panfilov
* HomeWork 5
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

///////////// Stack /////////////////
#define T char

struct Node {
    T data;
    struct Node* next;
};
typedef struct Node Node;

typedef struct {
    Node* head;
    int size;
} Stack;

void push(Stack* s, T val) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack Overflow");
        return;
    }
    tmp->data = val;
    tmp->next = s->head;
    s->head = tmp;
    s->size++;
}

T pop(Stack* s) {
    Node* tmp;
    T value;
    if (s->size == 0) {
        printf("Stack is empty");
        return -1;
    }
    tmp = s->head;
    value = s->head->data;
    s->head = s->head->next;
    free(tmp);
    s->size--;
    return value;
}

int length(Stack *s) {
    return s->size;
}

void clear(Stack *s) {
    while(length(s))
        pop(s);
}

void print(Node *n) {
    if (n) {
        printf("%d", n->data);
        print(n->next);
    } else
        return;
}

/////////////////////////////////////
// 5. реализовать очередь. (на Массиве)
///////////// Queue /////////////////

// Максимальное число элементов в очереди
#define MAX_QA 100

typedef struct {
	T data[MAX_QA];
	int head;
	int tail;
} AQueue;

void pushQA(AQueue* q, T val) {
	// Хвост уперся в границу массива
	if (q->tail == MAX_QA)
	{
		if (q->head != 0) // Еще есть место, сдвинем элементы в начало
		{
			int count = q->tail - q->head; // Определяем число элементов
			memmove(q->data, q->data + count, count * sizeof(T)); // Сдвигаем элементы в начало массива
		}
		else
		{
			printf("Queue is full");
			return;
		}
	}

	q->data[q->tail] = val;
	q->tail++;
}

T popQA(AQueue* q) {
	if (q->head == q->tail) {
		printf("Queue is empty");
		return -1;
	}
	q->head++;

	return q->data[q->head - 1];
}

int lengthQA(AQueue *q) {
	return q->tail - q->head;
}

void clearQA(AQueue *q) {
	q->head = 0;
	q->tail = 0;
}

void printQA(AQueue *q) {
	for (int i = q->head; i < q->tail; i++)
		printf("%d", q->data[i]);
}

void fillQueueA(AQueue* q, int size) {
	int i = 0;
	while (i < size) {
		pushQA(q, i);
		i++;
	}
}
////////////////////////////

/////////////////////////////////////
// 5. реализовать очередь. (на списке)
///////////// Queue /////////////////

struct QNode {
	T data;
	struct QNode* next;
	struct QNode* prev;
};
typedef struct QNode QNode;

typedef struct {
	QNode* head;
	QNode* tail;
	int size;
} Queue;

void pushQ(Queue* q, T val) {
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL) {
		printf("Stack Overflow");
		return;
	}
	tmp->data = val;
	tmp->prev = q->tail;
	tmp->next = NULL;

	if (q->tail)
		q->tail->next = tmp;
	q->tail = tmp;

	if (!q->head)
		q->head = tmp;
	q->size++;
}

T popQ(Queue* q) {
	QNode* tmp;
	T value;

	if (q->size == 0) {
		printf("Queue is empty");
		return -1;
	}

	tmp = q->head;
	value = tmp->data;
	q->head = tmp->next;

	if (q->tail == tmp)
		q->tail = NULL;

	if (q->head)
		q->head->prev = NULL;

	free(tmp);
	q->size--;
	return value;
}

int lengthQ(Queue *q) {
	return q->size;
}

void clearQ(Queue *q) {
	while (lengthQ(q))
		popQ(q);
}

void printQ(QNode *n) {
	if (n) {
		printf("%d", n->data);
		printQ(n->next);
	}
	else
		return;
}

void fillQueue(Queue* q, int size) {
	int i = 0;
	while (i < size) {
		pushQ(q, i);
		i++;
	}
}
////////////////////////////

/*
 * 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 */
void decToBin(int num, Stack* stack) {
    if (num < 2) {
        push(stack, num);
    } else {
        push(stack, num % 2);
        decToBin(num >> 1, stack);
    }
}

/*
 * 2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
 */
int checkString(char* str) {
	const int TYPES = 3;
	char braces[][2] = { { '(',')' }, { '[',']' }, { '{','}' } };
    Stack s;
    T tmp;
    s.head = NULL;
    s.size = 0;

    while (*str != '\0') {
		int i;
		for (i = 0; i < TYPES; i++)
			if (*str == braces[i][0])
			{
				push(&s, i);
				str++;
				continue; // Очень не хотелось лишний раз гонять цикл ниже
			}

		for (i = 0; i < TYPES; i++)
			if (*str == braces[i][1])
			{
				if (!length(&s)) // Стек пустой
					return 0;

				tmp = pop(&s);

				if (i != tmp) // Скобка не соответствует закрывающей
					return 0;
			}
		str++;
    }

    return (s.size == 0);
}

/*
 * 3. *Создать функцию, копирующую односвязный список.
 */
Node* copy(Node* from) {
    Node* tmp;
    if (from) {
        tmp = (Node*) malloc(sizeof(Node));
        if (tmp == NULL) {
            printf("Stack Overflow");
            return NULL;
        }
        tmp->data = from->data;
        tmp->next = copy(from->next);
        return tmp;
    } else
        return NULL;
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
    Stack stack;
    Queue queue;
	AQueue aqueue;
    stack.head = NULL;
    stack.size = 0;
    queue.head = NULL;
    queue.tail = NULL;
    queue.size = 0;
	aqueue.head = 0;
	aqueue.tail = 0;

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №5\n");
    
    printf("\nЗадание №1: Перевод из 10 сс в двоичную.\n");
    decToBin(100, &stack);
    printf("100 = ");
    print(stack.head);

    printf("\n\nЗадание №2: Проверка скобочной последовательности.\n");
    printf("(2+(2*2)) = %d\n", checkString("(2+(2*2))"));
    printf("[2/{5*(4+7)}] = %d\n", checkString("[2/{5*(4+7)}]"));
    printf("])}) = %d\n", checkString("])})"));
    printf("())({) = %d\n", checkString("())({)"));

    printf("\nЗадание №3: Скопировать список.\n");
    printf("First = ");
    print(stack.head);
    printf("\nSecond = ");
    print(copy(stack.head));

    printf("\n\nЗадание №5: Реализовать очередь.\n");
    fillQueue(&queue, 8);
    printf("QueueList = ");
    printQ(queue.head);
    printf("\nPopQ = %d, queue = ", popQ(&queue));
    printQ(queue.head);
	puts("");
	fillQueueA(&aqueue, 8);
	printf("QueueArray = ");
	printQA(&aqueue);
	printf("\nPopQ = %d, queue = ", popQA(&aqueue));
	printQA(&aqueue);

    getch();
    return 0;
}