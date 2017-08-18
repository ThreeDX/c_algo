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
    printf("Dmitry Panfilov Домашняя работа №3\n");

    //printf("\nЗадание №1: Перевод из 10 сс в двоичную.\n");
    //printf("100 = %s\n", decToBin(100, str));

    getch();
    return 0;
}