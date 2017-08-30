/*
* Dmitry Panfilov
* HomeWork 6
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

unsigned int crc(char* str) {
	unsigned int c = 0;
	while (*str != '\0') {
		c += *str;
		str++;
	}
	return c;
}
/*
* Main function
*/
int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №6\n");
    
    printf("\nЗадание №1: CRC.\n");
    printf("\"test string\" = %d\n", crc("test string"));

/*    printf("\n\nЗадание №2: Проверка скобочной последовательности.\n");
    printf("(2+(2*2)) = %d\n", checkString("(2+(2*2))"));
    printf("[2/{5*(4+7)}] = %d\n", checkString("[2/{5*(4+7)}]"));
    printf("])}) = %d\n", checkString("])})"));
    printf("())({) = %d\n", checkString("())({)"));

    printf("\nЗадание №3: Скопировать список.\n");
    printf("First = ");
    print(stack.head);
    printf("\nSecond = ");
    print(copy(stack.head));

    printf("\n\nЗадание №4: Реализовать очередь.\n");
    fillQueue(&queue, 8);
    printf("Queue = ");
    printQ(queue.head);
    printf("\nPopQ = %d, queue = ", popQ(&queue));
    printQ(queue.head);*/

    getch();
    return 0;
}