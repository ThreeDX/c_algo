/*
* Dmitry Panfilov
* HomeWork 3
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
//#include <mem.h>

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void fillArr(int* arr, int len) {
	int i;
	for(i = 0; i < len; i++)
		arr[i] = rand() % 100 + 1;
}

void printArr(int* arr, int len) {
	int i;
	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);
	puts("");
}

int searchInsertIndex(int* arr, int len, int value, int* count) {
	int left = 0;
	int right = len - 1;
	int middle = left + (right - left) / 2;
	while (left < right && arr[middle] != value) {
        (*count)++;
		if (arr[middle] < value)
			left = middle + 1;
		else
			right = middle - 1;
		middle = left + (right - left) / 2;
	}
    (*count)++;
    if(arr[middle] < value)
    	return ++middle;
    else return middle;
}

int mySort(int* arr, int len) {
	int count = 0;
	int i;
    int value, position;
	for (i = 1; i < len; i++) {
        count++;
        if (arr[i] < arr[i-1]) {
            value = arr[i];
            position = searchInsertIndex(arr, i, arr[i], &count); // Ищем позицию для вставки элемента
            memmove(arr + position + 1, arr + position, (i-position)*sizeof(*arr)); // Сдвигаем вправо часть массива
            arr[position] = value;
        }
	}
    return count;
}
/*
* Main function
*/
#define SIZE 40
int main(int argc, char* argv[]) {
	int arr[SIZE];
    srand(time(0));
	fillArr(arr, SIZE);
	printArr(arr, SIZE);
    printf("count = %d\n", mySort(arr, SIZE));
    printArr(arr, SIZE);

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №3\n");

    //printf("\nЗадание №1: Перевод из 10 сс в двоичную.\n");
    //printf("100 = %s\n", decToBin(100, str));

    getch();
    return 0;
}