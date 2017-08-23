/*
* Dmitry Panfilov
* HomeWork 4
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

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

// Вспомогательная функция, Бинарный поиск места в массиве для вставки элемента
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
    else
        return middle;
}

/*
* Main function
*/
#define SIZE 25
int main(int argc, char* argv[]) {
    int arr[SIZE];
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №4\n");
    
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    //printf("MySort count = %d\n", mySort(arr, SIZE));
    printArr(arr, SIZE);


    getch();
    return 0;
}