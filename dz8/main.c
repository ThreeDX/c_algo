/*
* Dmitry Panfilov
* HomeWork 8
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

// Для сортировки подсчетом, значения в массиве до 100 включительно
#define SIZE101 101

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

/*
 * 1. Реализовать сортировку подсчетом.
 */
int countSort(int *arr, int len)
{
    int count = 0; // счетчик обращений к элементам
    int *values = (int*)calloc(SIZE101, sizeof(int));

    if (values == NULL) {
        puts("Out of memory!");
        exit(1);
    }

    count += len;
    for (int i = 0; i < len; ++i) {
        ++values[arr[i]];
    }

    int k = 0;
    for (int i = 0; i < SIZE101; ++i) {
        for (int j = 0; j < values[i]; ++j)
            arr[k++] = i;
    }
    count += k + SIZE101;

    free(values);
    return count;
}


/*
* 2. Реализовать быструю сортировку.
*/
int quickSort(int *arr, int first, int last)
{
    int count = 0;
    int i = first, j = last;
    int x = arr[(first + last) / 2];

    do
    {
        while (arr[i] < x) {
            ++count;
            ++i;
        }
        while (arr[j] > x) {
            ++count;
            --j;
        }
        if (i <= j)
        {
            ++count;
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        count += quickSort(arr, i, last);
    if (first < j)
        count += quickSort(arr, first, j);

    return count;
}

/*
* 3. *Реализовать сортировку слиянием.
*/
int mergeSort(int *arr, int left, int right)
{
    int count = 0;
    int x = (left + right) / 2;

    if (left < right)
        // Обрабатываемый фрагмент массива состоит более,
        // чем из одного элемента
        if (right - left == 1) {
            ++count;
            if (arr[right] < arr[left])
            {
                swap(&arr[left], &arr[right]);
            }
        }
        else
        { // Разбиваем заданный фрагмент на два массива
          // Рекурсивно вызываем функции MergeSort
            count += mergeSort(arr, left, left + x);
            count += mergeSort(arr, left + x + 1, right);
            //Merge(m, l, r); // Сливаем массивы
        }
    return count;
}

/*
* 4. **Реализовать алгоритм сортировки со списком
*/
void listSort(int *arr, int len)
{

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
    printf("Dmitry Panfilov Домашняя работа №8\n");
    
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    printf("\nCountSort count = %d\n", countSort(arr, SIZE));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
    //printArr(arr, SIZE);
    printf("\nQuickSort count = %d\n", quickSort(arr, 0, SIZE - 1));
    printArr(arr, SIZE);

    fillArr(arr, SIZE);
    //printArr(arr, SIZE);
    printf("\nMergeSort count = %d\n", mergeSort(arr, 0, SIZE - 1));
    printArr(arr, SIZE);

	
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf("\n n\t\t\t100\t1000\t10000\n-------------------------------------------------\n");
//	printf(" Bubble\t\t\t%d\t%d\t%d\n", bubbleSortRC(arr1, SIZE100), bubbleSortRC(arr2, SIZE1000), bubbleSortRC(arr3, SIZE10000));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
//	printf(" Shake\t\t\t%d\t%d\t%d\n", shakeSort(arr1, SIZE100), shakeSort(arr2, SIZE1000), shakeSort(arr3, SIZE10000));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
//	printf(" My Sort\t\t%d\t%d\t%d\n", mySort(arr1, SIZE100), mySort(arr2, SIZE1000), mySort(arr3, SIZE10000));
	printf("-------------------------------------------------\n");


    getch();
    return 0;
}