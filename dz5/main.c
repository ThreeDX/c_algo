/*
* Dmitry Panfilov
* HomeWork 5
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

/*
* Main function
*/
#define SIZE 25
int main(int argc, char* argv[]) {
    int arr[SIZE];
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №5\n");
    
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    //printf("MySort count = %d\n", mySort(arr, SIZE));
    //printArr(arr, SIZE);

    getch();
    return 0;
}