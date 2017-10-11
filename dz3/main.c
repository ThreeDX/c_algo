/*
* Dmitry Panfilov
* HomeWork 3
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

// Меняем элемнеты местами
void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Заполняем массив элемнетами (всегда одинаковая последовательность)
void fillArr(int* arr, int len) {
    int i;
	srand(0); // чтобы всегда одинаковая последовательность была
    for(i = 0; i < len; i++)
        arr[i] = rand() % 100 + 1;
}

// Печатает массив
void printArr(int* arr, int len) {
    int i;
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
    puts("");
}

// Вспомогательная функция, Бинарный поиск места в массиве для вставки элемента
// 3. По сути третье задание
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
 * 1. Оптимизированная сортировка
 */
int mySort(int* arr, int len) {
    int count = 0;
    int i;
    int value, position;
    
    for (i = 1; i < len; i++) {
        if (arr[i] < arr[i-1]) {
			count++; // Тут все же не 1 операция обмена значениями, а операция обмена со сдвигом и еще бинарный поиск куда вставлять.
			value = arr[i];
            position = searchInsertIndex(arr, i, arr[i], &count); // Ищем позицию для вставки элемента
            memmove(arr + position + 1, arr + position, (i-position)*sizeof(*arr)); // Сдвигаем вправо часть массива
            arr[position] = value;
        }
    }
    
    return count;
}

/*
 * 2. Шейкерная сортировка
 */
int shakeSort(int* arr, int len) {
    int i;
    int j;
    int count = 0;
    for(i = 0; i < len; i++)
        if (i % 2) {
            for(j = len - 1 - i; j > i - 1; j--) {
				if (arr[j] < arr[j - 1]) {
					swap(&arr[j], &arr[j - 1]);
					count++;
				}
            }
        } else {
            for(j = 0; j < len - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
					count++;
				}
            }
        }
    return count;
}

/*
 * Рекурсивный линейный поиск
 */
int linearSearchRC(int* arr, int len, int value) {
    if (len < 1)
        return -1;
    len--;
    return (arr[len] != value) 
        ? linearSearchRC(arr, len, value) 
        : len;
}

/*
 * Рекурсивная сортировка пузырьком
 */
// Вспомогательная функция
int bubbleRC(int* arr, int len) {
	int count = 0;

    if (len < 2)
        return 0;

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
		count++;
    }

    return bubbleRC(arr+1, len-1) + count;
}

int bubbleSortRC(int* arr, int len) {
    if (len < 2)
        return 0;

    return bubbleRC(arr, len) + bubbleSortRC(arr, len - 1);
}

/*
* Main function
*/
#define SIZE 25
#define SIZE100 100
#define SIZE1000 1000
#define SIZE10000 10000
int main(int argc, char* argv[]) {
	int arr[SIZE];
	int arr1[SIZE100];
	int arr2[SIZE1000];
	int arr3[SIZE10000];

	setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №3\n");
    
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    printf("\nMySort count = %d\n", mySort(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
    //printArr(arr, SIZE);
    printf("\nBubbleRC count = %d\n", bubbleSortRC(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
    //printArr(arr, SIZE);
    printf("\nShakeSort count = %d\n", shakeSort(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
	puts("");
    printArr(arr, SIZE);
    printf("LinearSearchRC find 22 result = %d\n\n", linearSearchRC(arr, SIZE, 22));

	
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf(" n\t\t\t100\t1000\t10000\n-------------------------------------------------\n");
	printf(" Bubble\t\t\t%d\t%d\t%d\n", bubbleSortRC(arr1, SIZE100), bubbleSortRC(arr2, SIZE1000), bubbleSortRC(arr3, SIZE10000));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf(" Shake\t\t\t%d\t%d\t%d\n", shakeSort(arr1, SIZE100), shakeSort(arr2, SIZE1000), shakeSort(arr3, SIZE10000));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf(" My Sort\t\t%d\t%d\t%d\n", mySort(arr1, SIZE100), mySort(arr2, SIZE1000), mySort(arr3, SIZE10000));
	printf("-------------------------------------------------\n");




    getch();
    return 0;
}