/*
* Dmitry Panfilov
* HomeWork 3
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

/*
* Main function
*/
int main(int argc, char* argv[]) {
    char str[33] = {0};

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �3\n");

    //printf("\n������� �1: ������� �� 10 �� � ��������.\n");
    //printf("100 = %s\n", decToBin(100, str));

    getch();
    return 0;
}