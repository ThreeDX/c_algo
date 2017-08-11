/*
 * Dmitry Panfilov
 * HomeWork 1
 */
#include <locale.h>

#include <stdio.h>
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
    int a = 0, b = 0, c = 0;
    float d = 0, x1 = 0, x2 = 0;

    printf("\n������ 4: ������ ����������� ��������� aX^2 + bX + c = 0.\n\n������� ����� A B C: ");
    scanf("%d %d %d", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf("��� �������!\n");
    }
    else if (d == 0)
    {
        x1 = -b / (2 * (float)a);
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
 * 7. � ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2). ��������� ����������, ��������� �� ���� � ������ ����� ��� ���.
 */
void checkChessCells() {

}





/*
 * Main function
 */
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �1\n");

    // task 1
    //calcIndexBody();

    // task 2
    //maxFour();

    // task 3
    //swapVars();

    // task 4
    //findX2();

    // task 5
    //checkMonth();

    // task 6
    checkAge();



    getch();
    return 0;
}