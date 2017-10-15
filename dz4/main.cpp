/*
* Dmitry Panfilov
* HomeWork 3
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

// Размер поля
const int He = 8;
const int Wi = 8;

// 1. *Количество маршрутов с препятствиями.
int routes(int r, int c, int map[He][Wi]) {
	if (r == 0 || c == 0)
		return 1;
	else
		return (map[r][c] == 1) ?
		routes(r - 1, c, map) + routes(r, c - 1, map) :
		0;
}


// 3**Требуется обойти конём шахматную доску размером NxM

// Доска
int desk[He][Wi];

// Возможные варианты ходов
int possible[][2] = {
	{ -2, 1 },{ -1, 2 },{ 1, 2 },{ 2, 1 },
	{ 2, -1 },{ 1, -2 },{ -1, -2 },{ -2, -1 } };

// Максимальное число ходов
int maxMoves = He * Wi - 1;

// Проверка на допустимость такого хода
int isPosible(int x, int y) {
	return x >= 0 && x < He && y >= 0 && y < Wi && desk[x][y] == 0;
}

// Вывод доски
void printDesk() {
	printf("\n");
	for (int i = 0; i < He; i++) {
		for (int j = 0; j < Wi; j++)
			printf("%3d ", desk[i][j]);
		puts("");
	}
}

// Обход конем рекурсивно
int knightMove(int currentX, int currentY, int move) {
	int nextX, nextY;
	desk[currentX][currentY] = move;
	if (move > maxMoves) return 1;

	for (int i = 0; i < 7; i++) {
		nextX = currentX + possible[i][1];
		nextY = currentY + possible[i][0];
		if (isPosible(nextX, nextY) && knightMove(nextX, nextY, move + 1))
			return 1;
	}

	desk[currentX][currentY] = 0;
	return 0;
}

int main() {

	// 1. *Количество маршрутов с препятствиями.
	// Реализовать чтение массива с препятствием и нахождение количество маршрутов.
	int arr[He][Wi];
	int obstacles[He][Wi];
	int i;
	int j;

	// Поле с препятствиями
	for (i = 0; i < He; i++)
		for (j = 0; j < Wi; j++)
			obstacles[i][j] = 1;
	obstacles[3][2] = 0;
	obstacles[5][6] = 0;
	obstacles[6][5] = 0;

	// Распечатка карты
	for (i = 0; i < He; i++) {
		for (j = 0; j < Wi; j++)
			printf("%4d ", obstacles[i][j]);
		puts("");
	}
	puts("");

	// Определение маршрутов
	for (i = 0; i < He; i++)
		for (j = 0; j < Wi; j++)
			arr[i][j] = routes(i, j, obstacles);

	// Результат
	for (i = 0; i < He; i++) {
		for (j = 0; j < Wi; j++)
			printf("%4d ", arr[i][j]);
		puts("");
	}

	// 3.	**Требуется обойти конём шахматную доску размером NxM,
	// пройдя через все поля доски по одному разу.

	knightMove(0, 0, 1);
	printDesk();

	getchar();
	return 0;
}
