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

void printAndClear(Stack *s) {
    T tmp;
    while(length(s)) {
        tmp = pop(s);
        printf("%d", tmp);
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
    Stack s;
    T tmp;
    s.head = NULL;
    s.size = 0;

    while (*str != '\0') {
        if (*str == '{' || *str == '(' || *str == '[')
            push(&s, *str);
        else if (*str == '}' || *str == ')' || *str == ']') {
            if (!length(&s))
                return 0;
            
            tmp = pop(&s);
            
            if (tmp == '{' && *str != '}')
                return 0;
            else if (tmp == '[' && *str != ']')
                return 0;
            else if (tmp == '(' && *str != ')')
                return 0;
        }
        str++;
    }

    return (s.size == 0);
}
/*
* Main function
*/
int main(int argc, char* argv[]) {
   	Stack stack;
	stack.head = NULL;
	stack.size = 0;

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №5\n");
    
    printf("\nЗадание №1: Перевод из 10 сс в двоичную.\n");
    decToBin(100, &stack);
    printf("100 = ");
    printAndClear(&stack);

    printf("\nЗадание №2: Проверка скобочной последовательности.\n");
    printf("(2+(2*2)) = %d\n", checkString("(2+(2*2))"));
    printf("[2/{5*(4+7)}] = %d\n", checkString("[2/{5*(4+7)}]"));
    printf("])}) = %d\n", checkString("])})"));
    printf("())({) = %d\n", checkString("())({)"));

    getch();
    return 0;
}