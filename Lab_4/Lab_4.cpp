/****************************************************/
/*              Лабораторна робота № 4              */
/*    Обчислення значень перiодичної функцiї.       */
/*         Приклад виконання. Варiант № 19          */
/****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <windows.h>  
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);

    printf(" ЛАБОРАТОРНА РОБОТА 4\n");

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        printf("\n Перелiк завданнь:\n");
        printf(" 0: Основне завдання: Побудувати графiк\n");
        printf(" 1: Додаткове завдання 1: Вгадати число\n");
        printf(" 2: Додаткове завдання 2: Перевiрка знань таблицi множення\n");
        printf(" 3: Додаткове завдання 3: Гра з числами\n");
        printf(" 4: Очистити консоль\n");
        printf(" 5: Завершити програму\n");

        printf("\n Оберiть номер завдання: ");
        scanf("%d", &choice);
        printf("\n");


        switch (choice)
        {
        case 0: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Основне завдання: Побудувати графiк\n\n");
            SetConsoleTextAttribute(color, 15);

            short n;        /* параметр зовнiшнього циклу */
            double x, y;    /* абсциса i ордината графiка */
            short h;        /* позицiя точки на екранi */
            /* зовнiшнiй цикл - для 5 перiодiв */
            for (n = 0; n < 5; n++) {
                /* виведення заголовка таблицi */
                printf("|   \x1b[36mх\x1b[0m   |      \x1b[33mу\x1b[0m     |\n");
                printf("|-------|------------|\n");
                /* внутрiшнiй цикл для одного перiоду */
                for (x = 0; x < 4; x += 0.25) {
                    /* 1-й вiдрiзок */
                    if (x < 2) y = sqrt(4 - (x - 2) * (x - 2));
                    /* 2-й вiдрiзок */
                    else y = -1 * x + 4;
                    /* виведення рядка таблицi */
                    printf("| \x1b[36m%5.2lf\x1b[0m | \x1b[33m%10.7lf\x1b[0m |", x + n * 4, y);

                    /* визначення позицiї точки */
                    h = (y + 1) * 10;
                    if (y - 1 - h * 10 > 0.5) h++;
                    /* виведення точки графiка */
                    for (; h > 0; h--) printf(" ");
                    printf("\x1b[36m*\x1b[0m\x1b[33m*\x1b[0m\n");
                }  /* кiнець внутрiшнього циклу */
              /* пауза до введення команди оператора */
               // printf("Натисншть клавшшу Enter...");
               // getchar();
            }  /* кiнець зовнiшнього циклу */
            break;
        }
        case 1: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Додаткове завдання 1: Вгадати число\n\n");

            int x = 10;
            int y;

            printf(" Введшть цiле число вiд 0 до 100\n");
            printf(" У Вас є 10 спроб \n\n");
            SetConsoleTextAttribute(color, 15);

            for (int i = 1; i <= 10; i++)
            {
                scanf(" %d", &y);

                do {
                    if (y == x) {
                        printf(" \x1b[32mВи вгадали число!\x1b[0m \n\n");
                        printf(" Усього спроб - \x1b[32m%d\x1b[0m \n\n", i);
                        exit(0);
                        break;
                    }
                    else if (y >= x) {
                        printf(" \x1b[36mМенше!\x1b[0m \n\n"); break;
                    }
                    else
                    {
                        printf(" \x1b[33mБiльше!\x1b[0m \n\n"); break;
                    }
                } while (y == x || i == 10);

                if (i == 10)
                {
                    printf(" \x1b[31mВи програли ((\x1b[0m  \n Загадане число = \x1b[34m%d\x1b[0m\n\n", x); break;
                }
            }
            break;
        }

        case 2: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Додаткове завдання 2: Перевiрка знань таблицi множення\n\n");

            int i = 0;
            int right = 0;
            int point = 2;

            int max = 9, min = 2;
            srand(static_cast<unsigned int>(time(0)));

            while (i < 10)
            {
                for (i = 0; i < 10; i++)
                {
                    int x = rand() % (max - min + 1) + min;
                    int y = rand() % (max - min + 1) + min;

                    int z = x * y;
                    int res;

                    SetConsoleTextAttribute(color, 14);
                    printf(" Скiльки буде %d * %d? \n", x, y);

                    SetConsoleTextAttribute(color, 15);
                    printf(" Введiть свiй резльтат = ");
                    scanf(" %d", &res);
                    //printf("\n");

                    if (res == z) {
                        right += 1;
                        printf("\n \x1b[32mПравильно\x1b[0m\n");
                    }
                    else {
                        printf("\n \x1b[31mПомилка!\x1b[0m\n");
                    }
                    printf("\n");
                }
            }

            switch (right) {
            case 0: point = 2; break;
            case 1: point = 2; break;
            case 2: point = 2; break;
            case 3: point = 2; break;
            case 4: point = 2; break;
            case 5: point = 2; break;
            case 6: point = 2; break;

            case 7: point = 3; break;
            case 8: point = 3; break;
            case 9: point = 4; break;
            case 10: point = 5; break;
            default: printf(" Щось пiшло не так... \n"); break;
            }

            SetConsoleTextAttribute(color, 15);
            printf(" Кiлькiсть правильних вiдповiдей - \x1b[35m%d\x1b[0m \n", right);
            printf(" Ваша оцiнка - ");
            if (point == 2) {
                printf("\x1b[31m%d\x1b[0m\n\n", point);
            }
            else  if (point == 3) {
                printf("\x1b[33m%d\x1b[0m\n\n", point);
            }
            else  if (point == 4) {
                printf("\x1b[34m%d\x1b[0m\n\n", point);
            }
            else
            {
                printf("\x1b[32m%d\x1b[0m\n\n", point);
            }
            break;
        }
        case 3: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Додаткове завдання 3: Гра з числами\n\n");

            // нельзя ввести 021, или 1п2
            int x;

            while (true)
            {
                SetConsoleTextAttribute(color, 14);
                printf(" Введiть позитивне число: ");
                SetConsoleTextAttribute(color, 12);
                scanf("%d", &x);

                if (x <= 0) {
                    printf("\n \x1b[31mНеправильне число!!!\x1b[0m  \n\n");
                    break;
                    // return 0;
                }

                SetConsoleTextAttribute(color, 15);
                printf("\n Обернене число: ");
                int i = 0;
                int sum = 0;
                int z;

                while (x != 0)
                {
                    printf("\x1b[36m%d\x1b[0m", x % 10);
                    i++;
                    sum += x % 10;
                    x = x / 10;
                }
                printf("\n");
                printf(" Кiлькiсть цифр = \x1b[36m%d\x1b[0m\n", i);
                printf(" Сума цифр = \x1b[36m%d\x1b[0m\n\n", sum);
            }
            break;
        }
        case 4: {
            system("cls");
            break;
        }
        case 5: {
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

    // игра с числами ======================================================================

    printf(" Додаткове завдання 3: Гра з числами ");

    while (true)
    {
        int x, y = 0;

        scanf("%d", &x);

        while (x != 0)
        {
            printf("%d", x % 10);
            x = x / 10;
        }
    }
} /* кiнець програми */
