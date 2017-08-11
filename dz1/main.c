/*
 * Dmitry Panfilov
 * HomeWork 1
 */
#include <locale.h>

#include <stdio.h>
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
    int a = 0, b = 0, c = 0;
    float d = 0, x1 = 0, x2 = 0;

    printf("\nЗадача 4: Решить квадаратное уравнение aX^2 + bX + c = 0.\n\nВведите числа A B C: ");
    scanf("%d %d %d", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf("Нет решений!\n");
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
 * 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся ли поля к одному цвету или нет.
 */
void checkChessCells() {

}





/*
 * Main function
 */
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov Домашняя работа №1\n");

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