/*
* Dmitry Panfilov
* HomeWork 7
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>


/*
* Main function
*/
int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �7\n");
    
    /*printf("\n������� �1: CRC.\n");
    printf("\"test string\" = %d\n", crc("test string"));
	*/

    getch();
    return 0;
}