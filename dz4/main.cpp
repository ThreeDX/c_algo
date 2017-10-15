/*
* Dmitry Panfilov
* HomeWork 3
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

// ������ ����
const int He = 8;
const int Wi = 8;

// 1. *���������� ��������� � �������������.
int routes(int r, int c, int map[He][Wi]) {
	if (r == 0 || c == 0)
		return 1;
	else
		return (map[r][c] == 1) ?
		routes(r - 1, c, map) + routes(r, c - 1, map) :
		0;
}


// 3**��������� ������ ���� ��������� ����� �������� NxM

// �����
int desk[He][Wi];

// ��������� �������� �����
int possible[][2] = {
	{ -2, 1 },{ -1, 2 },{ 1, 2 },{ 2, 1 },
	{ 2, -1 },{ 1, -2 },{ -1, -2 },{ -2, -1 } };

// ������������ ����� �����
int maxMoves = He * Wi - 1;

// �������� �� ������������ ������ ����
int isPosible(int x, int y) {
	return x >= 0 && x < He && y >= 0 && y < Wi && desk[x][y] == 0;
}

// ����� �����
void printDesk() {
	printf("\n");
	for (int i = 0; i < He; i++) {
		for (int j = 0; j < Wi; j++)
			printf("%3d ", desk[i][j]);
		puts("");
	}
}

// ����� ����� ����������
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

	// 1. *���������� ��������� � �������������.
	// ����������� ������ ������� � ������������ � ���������� ���������� ���������.
	int arr[He][Wi];
	int obstacles[He][Wi];
	int i;
	int j;

	// ���� � �������������
	for (i = 0; i < He; i++)
		for (j = 0; j < Wi; j++)
			obstacles[i][j] = 1;
	obstacles[3][2] = 0;
	obstacles[5][6] = 0;
	obstacles[6][5] = 0;

	// ���������� �����
	for (i = 0; i < He; i++) {
		for (j = 0; j < Wi; j++)
			printf("%4d ", obstacles[i][j]);
		puts("");
	}
	puts("");

	// ����������� ���������
	for (i = 0; i < He; i++)
		for (j = 0; j < Wi; j++)
			arr[i][j] = routes(i, j, obstacles);

	// ���������
	for (i = 0; i < He; i++) {
		for (j = 0; j < Wi; j++)
			printf("%4d ", arr[i][j]);
		puts("");
	}

	// 3.	**��������� ������ ���� ��������� ����� �������� NxM,
	// ������ ����� ��� ���� ����� �� ������ ����.

	knightMove(0, 0, 1);
	printDesk();

	getchar();
	return 0;
}
