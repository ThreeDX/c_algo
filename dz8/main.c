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
    count += len + SIZE101;

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
    int x = right - left;

    if (left < right)
        // Обрабатываемый фрагмент массива состоит более,
        // чем из одного элемента
        if (x == 1) {
            ++count;
            if (arr[right] < arr[left])
            {
                swap(&arr[left], &arr[right]);
            }
        }
        else
        { // Разбиваем заданный фрагмент на два массива
          // Рекурсивно вызываем функции MergeSort
            int l = left, r = left + x / 2 + 1;
            int* temp = (int*)malloc(sizeof(int) * (x + 1));
            
            count += mergeSort(arr, left, left + x / 2);
            count += mergeSort(arr, r, right);
            
            // Сливаем массивы, через временный массив
            for (int i = 0; i < x + 1; i++)
                if (l <= left + x / 2 && (r > right || arr[l] <= arr[r]))
                    temp[i] = arr[l++];
                else
                    temp[i] = arr[r++];

            for (int i = 0; i < x + 1; i++)
                arr[left + i] = temp[i];

            count += (x + 1) * 2; // дважды проходим по временному массиву
            free(temp);
        }
    return count;
}

/*
* 4. **Реализовать алгоритм сортировки со списком
*/
typedef struct Node {
    int val;
    struct Node *next;
} Node;

void add(Node **list, int val)
{
    Node *p = (Node*)malloc(sizeof(Node));

    if (p == NULL) {
        puts("Out of memory!");
        exit(1);
    }

    p->val = val;
    p->next = *list;
    *list = p;
}

int pop(Node **list)
{
    if (*list == NULL) {
        //puts("List is NULL");
        return -1;
    }

    Node* temp = *list;
    int val = temp->val;
    *list = temp->next;
    free(temp);
    
    return val;
}

// Для упрощения сортируем тот же массив, но сохраняем элементы в массив структур
int listSort(int *arr, int len)
{
    int count = 0; // счетчик обращений к элементам
    Node **values = (Node**)calloc(SIZE101, sizeof(Node*));

    if (values == NULL) {
        puts("Out of memory!");
        exit(1);
    }

    count += len;
    for (int i = 0; i < len; ++i) {
        add(&values[arr[i]], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < SIZE101; ++i) {
        do {
            int p = pop(&values[i]);
            if (p >= 0)
                arr[k++] = p;
            else
                break;

        } while (1);
    }
    count += len + SIZE101;

    free(values);
    return count;
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

    fillArr(arr, SIZE);
    //printArr(arr, SIZE);
    printf("\nListSort count = %d\n", listSort(arr, SIZE));
    printArr(arr, SIZE);

	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf("\n n\t\t\t100\t1000\t10000\n-------------------------------------------------\n");
	printf(" Count\t\t\t%d\t%d\t%d\n", countSort(arr1, SIZE100), countSort(arr2, SIZE1000), countSort(arr3, SIZE10000));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf(" Quick\t\t\t%d\t%d\t%d\n", quickSort(arr1, 0, SIZE100 - 1), quickSort(arr2, 0, SIZE1000 - 1), quickSort(arr3, 0, SIZE10000 - 1));
	fillArr(arr1, SIZE100);
	fillArr(arr2, SIZE1000);
	fillArr(arr3, SIZE10000);
	printf(" Merge\t\t\t%d\t%d\t%d\n", mergeSort(arr1, 0, SIZE100 - 1), mergeSort(arr2, 0, SIZE1000 - 1), mergeSort(arr3, 0, SIZE10000 - 1));
    fillArr(arr1, SIZE100);
    fillArr(arr2, SIZE1000);
    fillArr(arr3, SIZE10000);
    printf(" List\t\t\t%d\t%d\t%d\n", listSort(arr1, SIZE100), listSort(arr2, SIZE1000), listSort(arr3, SIZE10000));
    printf("-------------------------------------------------\n");


    getch();
    return 0;
}