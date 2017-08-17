/*
* Dmitry Panfilov
* HomeWork 2
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

/*
 * 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
 *    Возвращает строку с двоичным представлением числа.
 */
char*  decToBin(int num, char* bin) {
    char str[2];

    if (num >= 2)
        decToBin(num >> 1, bin);

    return strcat(bin, itoa((num % 2), str, 10));
}

/*
 * 2. Реализовать функцию возведения числа a в степень b:
 *    a. без рекурсии;
 *    b. рекурсивно;
 *    c. *рекурсивно, используя свойство чётности степени.
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
 * 3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
 *    Прибавь 1
 *    Умножь на 2
 *    Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
 *    Сколько существует программ, которые число 3 преобразуют в число 20 с использованием рекурсии.
 */
int move(int from, int to) {
    int mc = 0; // Счетчик
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
    printf("Dmitry Panfilov Домашняя работа №2\n");

    printf("\nЗадание №1: Перевод из 10 сс в двоичную.\n");
    printf("100 = %s\n", decToBin(100, str));

    printf("\nЗадание №2: Возведение в степень.\n");
    printf("power:\t\t2^16 = %d", power(2, 16));
    printf(", шагов: %d\n", pi);
    printf("powerRC:\t2^16 = %d", powerRC(2, 16));
    printf(", шагов: %d\n", prc);
    printf("powerRCFast:\t2^16 = %d", powerRCFast(2, 16));
    printf(", шагов: %d\n", prcf);

    printf("\nЗадание №3: Число путей от 3 до 20.\n");
    printf("Число путей от 3 до 20 = %d\n", move(3, 20));

    getch();
    return 0;
}