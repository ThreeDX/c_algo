/*
* Dmitry Panfilov
* HomeWork 2
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

/*
 * 1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
 *    ���������� ������ � �������� �������������� �����.
 */
char*  decToBin(int num, char* bin) {
    char str[2];

    if (num >= 2)
        decToBin(num >> 1, bin);

    return strcat(bin, itoa((num % 2), str, 10));
}

/*
 * 2. ����������� ������� ���������� ����� a � ������� b:
 *    a. ��� ��������;
 *    b. ����������;
 *    c. *����������, ��������� �������� �������� �������.
 */
int pi = 0;
long power(int a, int b) {
	long result = 1;
	int i;
	for (i = 0; i < b; i++)
		result *= a;
    pi = i + 1;
	return result;
}

int prc = 0;
long powerRC(int a, unsigned int b) {
    prc++;
    if (b == 0)
        return 1;
    return a * powerRC(a, --b);
}

int prcf = 0;
long powerRCFast(int a, unsigned int b) {
    prcf++;
    if (b == 0)
        return 1;

    if (b % 2 == 0)
        return powerRCFast(a * a, b >> 1);
    else
		return a * powerRCFast(a, --b);
}

/*
 * 3. ����������� ����������� ����������� ����� �����, ���������� �� ������. � ����������� ��� �������, ������ ������� �������� �����:
 *    ������� 1
 *    ������ �� 2
 *    ������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����.
 *    ������� ���������� ��������, ������� ����� 3 ����������� � ����� 20 � �������������� ��������.
 */
int move(int from, int to) {
    int mc = 0; // �������
    if (from == to) {
        return 1;
    }
    if (from < to) {
        mc += move(from + 1, to);
        mc += move(from << 1, to);
    }
    return mc;
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
    char str[33] = {0};

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �2\n");

    printf("\n������� �1: ������� �� 10 �� � ��������.\n");
    printf("100 = %s\n", decToBin(100, str));

    printf("\n������� �2: ���������� � �������.\n");
    printf("power:\t\t2^16 = %d", power(2, 16));
    printf(", �����: %d\n", pi);
    printf("powerRC:\t2^16 = %d", powerRC(2, 16));
    printf(", �����: %d\n", prc);
    printf("powerRCFast:\t2^16 = %d", powerRCFast(2, 16));
    printf(", �����: %d\n", prcf);

    printf("\n������� �3: ����� ����� �� 3 �� 20.\n");
    printf("����� ����� �� 3 �� 20 = %d\n", move(3, 20));

    getch();
    return 0;
}