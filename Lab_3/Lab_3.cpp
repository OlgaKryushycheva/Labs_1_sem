/****************************************************/
/*              Лабораторна робота № 3              */
/*                 Умовний оператор.                */
/*         Приклад виконання. ВарIант № 19          */
/****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>  
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "RU");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);

    printf(" ЛАБОРАТОРНА РОБОТА 3\n");

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        printf("\n Перелiк завданнь:\n");
        printf(" 0: Основне завдання: знаходження точки на осi координат\n");
        printf(" 1: Додаткове завдання 1: Квадратне рiвняння\n");
        printf(" 2: Додаткове завдання 2: Порахувати гриби\n");
        printf(" 3: Очистити консоль\n");
        printf(" 4: Завершити програму\n");

        printf("\n Оберiть номер завдання: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 0: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Завдання: знаходження точки на осi координат\n\n");
            SetConsoleTextAttribute(color, 15);

            float x, y;

            while (true)
            {
                /*вводити через кому ENG або пробIл*/

                printf("\n Введiть значення координат Х та Y вiд -10,00 до +10,00 > ");

                scanf("%f %f", &x, &y);

                printf("\n Значення Х = \x1b[34m%.2f\x1b[0m, значення Y = \x1b[34m%.2f\x1b[0m\n\n", x, y);


                if ((x * x + y * y <= 1 && y <= 0 && x <= 0) ||
                    (x >= 0 && x <= 1 && y >= 0 && y <= 1)) {
                    printf(" \x1b[32mТочка потрапляe в задану область\x1b[0m \n\n");
                }
                else {
                    printf(" \x1b[31mТочка не потрапляe в задану область\x1b[0m \n\n");
                };
            };
            break;
        };

        case 1: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Додаткове завдання 1: Квадратне рiвняння\n\n");

            float a, b, c;

            while (true)
            {
                SetConsoleTextAttribute(color, 14);
                printf(" Введiть значення а = ");
                scanf("%f", &a);
                printf(" Введiть значення b = ");
                scanf("%f", &b);
                printf(" Введiть значення c = ");
                scanf("%f", &c);
                SetConsoleTextAttribute(color, 15);

                if (a == 0 || b == 0 || c == 0) {
                    printf(" \n \x1b[31mЯкщо одне iз значень = 0, рiвняння не має розвязання\x1b[0m \n\n\n");
                    break;
                }

                float d;

                d = b * b - 4 * a * c;

                printf("\n Значення дискримiнаннту = ");

                if (d < 0) {
                    printf("\x1b[31m%f\x1b[0m\n\n", d);
                }
                else  if (d == 0) {
                    printf("\x1b[34m%f\x1b[0m\n\n", d);
                }
                else
                {
                    printf("\x1b[32m%f\x1b[0m\n\n", d);
                }

                float x1 = -((b + sqrt(d)) / (2 * a));
                float x2 = -((b - sqrt(d)) / (2 * a));

                if (d < 0) {
                    printf(" \x1b[31mУ рiвняння немає коренiв\x1b[0m \n\n\n");
                }
                else if (d == 0) {
                    printf(" У рiвняння є 1 корiнь = \x1b[34m%f\x1b[0m\n\n\n", x1);
                }
                else {
                    printf(" \x1b[32mУ рiвняння є 2 коренi:\x1b[0m\n Корiнь x1= \x1b[32m%f\x1b[0m\n Корiнь x2= \x1b[32m%f\x1b[0m\n\n\n", x1, x2);
                }
            };
            break;
        };

        case 2: {
            system("cls");

            SetConsoleTextAttribute(color, 14);
            printf(" Додаткове завдання 2: Порахувати гриби\n");


            while (true)
            {
                int x;

                SetConsoleTextAttribute(color, 14);
                printf("\n Скiльки у вас грибiв? => ");
                SetConsoleTextAttribute(color, 15);

                scanf("%d", &x);

                int y = x % 10;

                if (x >= 11 && x <= 14) {
                    printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x);
                }
                else if (x == 0) {
                    printf(" У вас \x1b[35mнемає\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x);
                }

                else {
                    switch (y) {
                    case 0:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    case 1:  printf(" У вас \x1b[35m%d\x1b[0m гриб\n\n", x); break;
                    case 2:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35mи\x1b[0m\n\n", x); break;
                    case 3:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35mи\x1b[0m\n\n", x); break;
                    case 4:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35mи\x1b[0m\n\n", x); break;
                    case 5:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    case 6:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    case 7:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    case 8:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    case 9:  printf(" У вас \x1b[35m%d\x1b[0m гриб\x1b[35miв\x1b[0m\n\n", x); break;
                    default:  printf(" Це у вас \x1b[35mне\x1b[0m гриб\x1b[35m\x1b[35miв\x1b[0m\x1b[0m!!!\n\n"); break;
                    }
                }
            }
            break;
        };
        case 3: {
            system("cls");
            break;
        }
        case 4: {
            exit(0);
            break;
        }
        default: {
            system("cls");
            printf("\n Такого вибору не iснує!\n");
            break;
        }
        }
    }
}