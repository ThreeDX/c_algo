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
* 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
* где m-масса тела в килограммах, h - рост в метрах.
*/
void calcIndexBody() {
    float m = 0, h = 0, index = 0;
    printf("\nЗадача 1: Подсчет индекса массы тела.\n\nВведите Ваши массу и рост: ");
    scanf("%f %f", &m, &h);

    index = (h != 0) ? m / (h * h) : -1;

    printf("Индекс массы тела = %f\n", index);
}

/*
* 2. Найти максимальное из четырех чисел. Массивы не использовать.
*/
void maxFour() {
    int a = 0, b = 0, c = 0, d = 0, max = 0;
    printf("\nЗадача 2: Максимальное из 4 чисел.\n\nВведите четыре числа (a b c d): ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    max = a;

    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;

    printf("Максимальное число = %d\n", max);
}

/*
* 3. Написать программу обмена значениями двух целочисленных переменных:
*  a. с использованием третьей переменной;
*  b.*без использования третьей переменной.
*/
void swapVars() {
    int a = 0, b = 0;

    printf("\nЗадача 3: Обмен значений.\n\nВведите два числа A и B: ");
    scanf("%d %d", &a, &b);

    a ^= b;
    b ^= a;
    a ^= b;

    printf("Значения поменялись местами: %d %d\n", a, b);
}

/*
* 4. Написать программу нахождения корней заданного квадратного уравнения.
*/
void findX2() {
    int a = 0, b = 0, c = 0, d = 0;
    double x1 = 0, x2 = 0;

    printf("\nЗадача 4: Решить квадаратное уравнение aX^2 + bX + c = 0.\n\nВведите числа A B C: ");
    scanf("%d %d %d", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf("Нет решений!\n");
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
* С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
*/
void checkMonth() {
    int month = 0;

    printf("\nЗадача 5: Определение времени года по номеру месяца.\n\nВведите номер месяца (1..12): ");
    scanf("%d", &month);

    if (month >= 3 && month <= 5) // Весна
        printf("Время года: Весна\n");
    else if (month >= 6 && month <= 8) // Лето
        printf("Время года: Лето\n");
    else if (month >= 9 && month <= 11) // Осень
        printf("Время года: Осень\n");
    else if (month == 12 || month == 1 || month == 2) // Зима
        printf("Время года: Зима\n");
    else
        printf("Неправильный месяц\n");
}

/*
* 6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
*/
void checkAge() {
    char year[10] = "лет";
    int age = 0, checkValue = 0;

    printf("\nЗадача 6: Вывод возраста с правильным склонением.\n\nВведите Ваш возраст (1..150): ");
    scanf("%d", &age);

    if (age <0 || age > 150) {
        printf("Возраст вне диапазона\n");
        return;
    }

    if (age > 20)
        checkValue = age % 10;
    else
        checkValue = age;

    if (checkValue == 1)
        strcpy(year, "год");
    else if (checkValue >=2 && checkValue <= 4)
        strcpy(year, "года");

    printf("Вам %d %s\n", age, year);
}

/*
* 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
*    Требуется определить, относятся ли поля к одному цвету или нет.
*/
void checkChessCells() {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    printf("\nЗадача 7: Определение цвета яеек.\n\nВведите координаты ячеек (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if ((x1 + y1) % 2 == (x2 + y2) % 2) // Размер шахматной доски не важен, ячейки чередуются
        printf("Цвет ячеек одинаковый: %s", (x1 + y1) % 2 == 0 ? "черный" : "белый");
    else 
        printf("Цвет ячеек отличается\n");
}

/*
* 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
*/
void quadNumbers() {
    int a = 0, b = 0;

    printf("\nЗадача 8: Квадраты и кубы чисел.\n\nВведите два числа A и B (A < B): ");
    scanf("%d %d", &a, &b);

    while (a <= b) {
        printf("%d, квадрат = %d, куб = %d\n", a, a*a, a*a*a);
        a++;
    }
}

/*
* 9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, 
*    найти частное от деления нацело N на K, а также остаток от этого деления.
*/
void divisionNumbers() {
    int n = 0, k = 0, result = 0;

    printf("\nЗадача 9: Деление двух целых чисел.\n\nВведите два числа N и K: ");
    scanf("%d %d", &n, &k);

    if (n < 0 || k < 0) {
        printf("Некорректный ввод!");
        return;
    }

    while (n >= k) {
        n -= k;
        result++;
    }

    printf("N / K = %d, остаток = %d\n", result, n);
}

/*
* 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,
*     имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
*/
void evenNumbers() {
    int n = 0, result = 0, ostatok = 0;

    printf("\nЗадача 10: Определение нечетных цифр в числе.\n\nВведите число N > 0: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Некорректное число!");
        return;
    }

    while (n > 0) {
        if ((n % 10) % 2 == 1) {
            result = 1;
            break;
        }
        n /= 10;
    }

    printf("Наличие нечетных цифр: %s\n", result == 0 ? "False" : "True");
}

/*
* 11. С клавиатуры вводятся числа, пока не будет введен 0.
*     Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
*/
void avgNumbers() {
    int num = 0, count = 0, sum = 0;

    printf("\nЗадача 11: Среднее арифметическое положительных чисел, оканчивающихся на 8.\n\nВводите числа, для выхода - 0: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num > 0 && num % 10 == 8) {
            count++;
            sum += num;
        }
        scanf("%d", &num);
    }

    if (count > 0) 
        printf("Среднее арифметическое чисел: %lf\n", (double)sum / count);
    else
        printf("Подходящих чисел нет");
}

/*
* 12. Написать функцию нахождения максимального из трех чисел.
*/
void maxThree() {
    int a = 0, b = 0, c = 0, max = 0;
    printf("\nЗадача 12: Максимальное из 3 чисел.\n\nВведите три числа (a b c): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        max = a;
    else if (b >= a && b >= c)
        max = b;
    else
        max = c;

    printf("Максимальное число = %d\n", max);
}

/*
* 13. *Написать функцию, генерирующую случайное число от 1 до 100.
*      а) с использованием стандартной функции rand()
*      б) без использования стандартной функции rand()
*/
void randomNumbers() {
    int x = 0, a = 2, b = 3, m = 100;
    int n = 100, i = 0;
    printf("\nЗадача 13: Случайные числа от 1 до 100.\n\n");

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
* 14. *Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
*      Например, 25^2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа,
*      не превосходящие N.
*/
void avtomorfNumbers() {
    unsigned int n = 0, i = 0;
    unsigned int tn = 0, tq = 0, res = 0;
    printf("\nЗадача 14: Автоморфные числа от 0 до N.\n\nВведите число N > 0: ");
    scanf("%d", &n);

    if (n > 65535) {
        printf("Слишком большое число!\n");
        return;
    }

    while (i <= n)
    {
        if (i > 1 && i % 10 != 5 && i % 10 != 6) { // Автоморфные числа до 1 или заканчиваются на 5 или 6
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
    printf("Dmitry Panfilov Домашняя работа №1\n");

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