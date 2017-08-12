/*
* Dmitry Panfilov
* HomeWork 1
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* 1. ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);
* ��� m-����� ���� � �����������, h - ���� � ������.
*/
void calcIndexBody() {
    float m = 0, h = 0, index = 0;
    printf("\n������ 1: ������� ������� ����� ����.\n\n������� ���� ����� � ����: ");
    scanf("%f %f", &m, &h);

    index = (h != 0) ? m / (h * h) : -1;

    printf("������ ����� ���� = %f\n", index);
}

/*
* 2. ����� ������������ �� ������� �����. ������� �� ������������.
*/
void maxFour() {
    int a = 0, b = 0, c = 0, d = 0, max = 0;
    printf("\n������ 2: ������������ �� 4 �����.\n\n������� ������ ����� (a b c d): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    max = a;

    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;

    printf("������������ ����� = %d\n", max);
}

/*
* 3. �������� ��������� ������ ���������� ���� ������������� ����������:
*  a. � �������������� ������� ����������;
*  b.*��� ������������� ������� ����������.
*/
void swapVars() {
    int a = 0, b = 0;

    printf("\n������ 3: ����� ��������.\n\n������� ��� ����� A � B: ");
    scanf("%d %d", &a, &b);

    a ^= b;
    b ^= a;
    a ^= b;

    printf("�������� ���������� �������: %d %d\n", a, b);
}

/*
* 4. �������� ��������� ���������� ������ ��������� ����������� ���������.
*/
void findX2() {
    int a = 0, b = 0, c = 0, d = 0;
    double x1 = 0, x2 = 0;

    printf("\n������ 4: ������ ����������� ��������� aX^2 + bX + c = 0.\n\n������� ����� A B C: ");
    scanf("%d %d %d", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf("��� �������!\n");
    }
    else if (d == 0)
    {
        x1 = -b / (2 * (double)a);
        printf("X1 = X2 = %f\n", x1);
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("X1 = %f, X2 = %f\n", x1, x2);
    }
}

/*
* � ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������.
*/
void checkMonth() {
    int month = 0;

    printf("\n������ 5: ����������� ������� ���� �� ������ ������.\n\n������� ����� ������ (1..12): ");
    scanf("%d", &month);

    if (month >= 3 && month <= 5) // �����
        printf("����� ����: �����\n");
    else if (month >= 6 && month <= 8) // ����
        printf("����� ����: ����\n");
    else if (month >= 9 && month <= 11) // �����
        printf("����� ����: �����\n");
    else if (month == 12 || month == 1 || month == 2) // ����
        printf("����� ����: ����\n");
    else
        printf("������������ �����\n");
}

/*
* 6. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
*/
void checkAge() {
    char year[10] = "���";
    int age = 0, checkValue = 0;

    printf("\n������ 6: ����� �������� � ���������� ����������.\n\n������� ��� ������� (1..150): ");
    scanf("%d", &age);

    if (age <0 || age > 150) {
        printf("������� ��� ���������\n");
        return;
    }

    if (age > 20)
        checkValue = age % 10;
    else
        checkValue = age;

    if (checkValue == 1)
        strcpy(year, "���");
    else if (checkValue >=2 && checkValue <= 4)
        strcpy(year, "����");

    printf("��� %d %s\n", age, year);
}

/*
* 7. � ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2).
*    ��������� ����������, ��������� �� ���� � ������ ����� ��� ���.
*/
void checkChessCells() {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    printf("\n������ 7: ����������� ����� ����.\n\n������� ���������� ����� (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if ((x1 + y1) % 2 == (x2 + y2) % 2) // ������ ��������� ����� �� �����, ������ ����������
        printf("���� ����� ����������: %s", (x1 + y1) % 2 == 0 ? "������" : "�����");
    else 
        printf("���� ����� ����������\n");
}

/*
* 8. ������ a � b � ������� �������� � ���� ����� �� a �� b.
*/
void quadNumbers() {
    int a = 0, b = 0;

    printf("\n������ 8: �������� � ���� �����.\n\n������� ��� ����� A � B (A < B): ");
    scanf("%d %d", &a, &b);

    while (a <= b) {
        printf("%d, ������� = %d, ��� = %d\n", a, a*a, a*a*a);
        a++;
    }
}

/*
* 9. ���� ����� ������������� ����� N � K. ��������� ������ �������� �������� � ���������, 
*    ����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.
*/
void divisionNumbers() {
    int n = 0, k = 0, result = 0;

    printf("\n������ 9: ������� ���� ����� �����.\n\n������� ��� ����� N � K: ");
    scanf("%d %d", &n, &k);

    if (n < 0 || k < 0) {
        printf("������������ ����!");
        return;
    }

    while (n >= k) {
        n -= k;
        result++;
    }

    printf("N / K = %d, ������� = %d\n", result, n);
}

/*
* 10. ���� ����� ����� N (> 0). � ������� �������� ������� ������ � ������ ������� �� ������� ����������,
*     ������� �� � ������ ����� N �������� �����. ���� �������, �� ������� True, ���� ��� � ������� False.
*/
void evenNumbers() {
    int n = 0, result = 0, ostatok = 0;

    printf("\n������ 10: ����������� �������� ���� � �����.\n\n������� ����� N > 0: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("������������ �����!");
        return;
    }

    while (n > 0) {
        if ((n % 10) % 2 == 1) {
            result = 1;
            break;
        }
        n /= 10;
    }

    printf("������� �������� ����: %s\n", result == 0 ? "False" : "True");
}

/*
* 11. � ���������� �������� �����, ���� �� ����� ������ 0.
*     ���������� ������� �������������� ���� ������������� ������ �����, �������������� �� 8.
*/
void avgNumbers() {
    int num = 0, count = 0, sum = 0;

    printf("\n������ 11: ������� �������������� ������������� �����, �������������� �� 8.\n\n������� �����, ��� ������ - 0: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num > 0 && num % 10 == 8) {
            count++;
            sum += num;
        }
        scanf("%d", &num);
    }

    if (count > 0) 
        printf("������� �������������� �����: %lf\n", (double)sum / count);
    else
        printf("���������� ����� ���");
}

/*
* 12. �������� ������� ���������� ������������� �� ���� �����.
*/
void maxThree() {
    int a = 0, b = 0, c = 0, max = 0;
    printf("\n������ 12: ������������ �� 3 �����.\n\n������� ��� ����� (a b c): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        max = a;
    else if (b >= a && b >= c)
        max = b;
    else
        max = c;

    printf("������������ ����� = %d\n", max);
}

/*
* 13. *�������� �������, ������������ ��������� ����� �� 1 �� 100.
*      �) � �������������� ����������� ������� rand()
*      �) ��� ������������� ����������� ������� rand()
*/
void randomNumbers() {
    int x = 0, a = 2, b = 3, m = 100;
    int n = 100, i = 0;
    printf("\n������ 13: ��������� ����� �� 1 �� 100.\n\n");

    srand(time(NULL));
    x = rand() % 100 + 1;

    while (i < n)
    {
        x = ((a + i) * x  + b)  % m;
        printf("%d ", x);
        i++;
    }
}

/*
* 14. *����������� �����. ����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.
*      ��������, 25^2 = 625. �������� ���������, ������� ������ ����������� ����� N � ������� �� ����� ��� ����������� �����,
*      �� ������������� N.
*/
void avtomorfNumbers() {
    unsigned int n = 0, i = 0;
    unsigned int tn = 0, tq = 0, res = 0;
    printf("\n������ 14: ����������� ����� �� 0 �� N.\n\n������� ����� N > 0: ");
    scanf("%d", &n);

    if (n > 65535) {
        printf("������� ������� �����!\n");
        return;
    }

    while (i <= n)
    {
        if (i > 1 && i % 10 != 5 && i % 10 != 6) { // ����������� ����� �� 1 ��� ������������� �� 5 ��� 6
            i++;
            continue;
        }
        tn = i;
        tq = i * i;
        res = 1;
        while (tn > 0) {
            if (tn % 10 != tq % 10) {
                res = 0;
                break;
            }
            tn /= 10;
            tq /= 10;
        }
        if (res != 0)
            printf("%d - %d\n", i, i * i);
        i++;
    }
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �1\n");

    // task 1
    calcIndexBody();

    // task 2
    maxFour();

    // task 3
    swapVars();

    // task 4
    findX2();

    // task 5
    checkMonth();

    // task 6
    checkAge();

    // task 7
    checkChessCells();

    // task 8
    quadNumbers();

    // task 9
    divisionNumbers();

    // task 10
    evenNumbers();

    // task 11
    avgNumbers();

    // task 12
    maxThree();

    // task 13
    randomNumbers();

    // task 14
    avtomorfNumbers();



    getch();
    return 0;
}