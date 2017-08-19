/*
* Dmitry Panfilov
* HomeWork 3
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
 * 1. Оптимизированная сортировка
 */
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
 * 2. Шейкерная сортировка
 */
int shakeSort(int* arr, int len) {
	int i;
	int j;
    int count = 0;
	for(i = 0; i < len; i++)
        if (i % 2) {
		    for(j = len - 1 - i; j > i - 1; j--) {
                count++;
			    if(arr[j] < arr[j - 1])
				    swap(&arr[j], &arr[j - 1]);
            }
        } else {
		    for(j = 0; j < len - 1 - i; j++) {
                count++;
			    if(arr[j] > arr[j + 1])
				    swap(&arr[j], &arr[j + 1]);
            }
        }
    return count;
}

/*
 * 3. Рекурсивный линейный поиск
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
 * 5. Рекурсивная сортировка пузырьком
 */
// Вспомогательная функция
int bubbleRC(int* arr, int len) {
    if (len < 2)
        return 0;

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return bubbleRC(arr+1, len-1) + 1;
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
int main(int argc, char* argv[]) {
	int arr[SIZE];
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №3\n");
	
    fillArr(arr, SIZE);
	printArr(arr, SIZE);
    printf("MySort count = %d\n", mySort(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
	printArr(arr, SIZE);
    printf("BubbleRC count = %d\n", bubbleSortRC(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
	printArr(arr, SIZE);
    printf("ShakeSort count = %d\n", shakeSort(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
	printArr(arr, SIZE);
    printf("LinearSearchRC find 23 result = %d\n", linearSearchRC(arr, SIZE, 23));

    getch();
    return 0;
}