#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>  
#include <stdlib.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);

    printf(" ЛАБОРАТОРНА РОБОТА 1\n\n");

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        printf(" Перелiк завданнь:\n");
        printf(" 1: Визначити обсяг пам'ятi рiзних типiв змiнних\n");
        printf(" 2: Знайти площу трикутника\n");
        printf(" 3: Розрахувати 8 ступiнь числа\n");
        printf(" 4: Помiняти мiсцями значення 2-х змiнних\n");
        printf(" 5: Порахувати кiлькiсть секунд у роках\n");
        printf(" 6: Очистити консоль\n");
        printf(" 7: Завершити програму\n");

        printf("\n Оберiть номер завдання: ");
        scanf("%d", &choice);
        printf("\n");

        SetConsoleTextAttribute(color, 15);

        switch (choice)
        {
        case 1: {
            system("cls");

            SetConsoleTextAttribute(color, 14);
            printf(" Завдання 1: Визначити обсяг пам'ятi рiзних типiв змiнних\n\n");
            SetConsoleTextAttribute(color, 15);

            printf(" sizeof bool =  \x1b[32m%d\x1b[0m\n\n", sizeof(bool));

            printf(" sizeof char = \x1b[32m%d\x1b[0m\n", sizeof(char));
            printf(" sizeof char16_t = \x1b[32m%d\x1b[0m\n", sizeof(char16_t));
            printf(" sizeof char32_t = \x1b[32m%d\x1b[0m\n\n", sizeof(char32_t));

            printf(" sizeof int = \x1b[32m%d\x1b[0m\n", sizeof(int));
            printf(" sizeof unsigned int = \x1b[32m%d\x1b[0m\n\n", sizeof(unsigned int));

            printf(" sizeof short = \x1b[32m%d\x1b[0m\n", sizeof(short));
            printf(" sizeof unsigned short = \x1b[32m%d\x1b[0m\n\n", sizeof(unsigned short));

            printf(" sizeof long = \x1b[32m%d\x1b[0m\n", sizeof(long));
            printf(" sizeof unsigned long = \x1b[32m%d\x1b[0m\n", sizeof(unsigned long));
            printf(" sizeof long long = \x1b[32m%d\x1b[0m\n", sizeof(long long));
            printf(" sizeof unsigned long long = \x1b[32m%d\x1b[0m\n\n", sizeof(unsigned long long));

            printf(" sizeof float = \x1b[32m%d\x1b[0m\n\n", sizeof(float));

            printf(" sizeof double = \x1b[32m%d\x1b[0m\n", sizeof(double));
            printf(" sizeof long double = \x1b[32m%d\x1b[0m\n\n", sizeof(long double));
            break;
        }
        case 2: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Завдання 2: Знайти площу трикутника\n");

            float  x, y, z;
            printf("\n Визначте довжину сторони x: ");
            SetConsoleTextAttribute(color, 9);
            scanf("%f", &x);
            SetConsoleTextAttribute(color, 14);
            printf("\n Визначте довжину сторони y: ");
            SetConsoleTextAttribute(color, 9);
            scanf("%f", &y);
            SetConsoleTextAttribute(color, 14);
            printf("\n Визначте довжину сторони z: ");
            SetConsoleTextAttribute(color, 9);
            scanf("%f", &z);
            SetConsoleTextAttribute(color, 4);

            if (x <= 0 || y <= 0 || z <= 0) {

                printf("\n Такого трикутника не iснує! Можна обрати тiльки позитивнi значення x, y, z \n\n");

            }
            else {
                float p = (x + y + z) / 2;
                float a = (p * (p - x) * (p - y) * (p - z));
                float s = sqrt(a);
                if (s <= 0 || a <= 0) {
                    printf("\n Такого трикутника не iснує! Введiть правильне значення сторiн\n\n");
                }
                else
                {
                    SetConsoleTextAttribute(color, 2);
                    printf("\n Площа трикутника =  %f\n\n", s);
                }
            }
            break;
        }
        case 3: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Завдання 3: Розрахувати 8 ступiнь числа\n");

            unsigned long long number;
            printf("\n Введiть значення числа: ");
            SetConsoleTextAttribute(color, 10);
            scanf("%llu", &number);

            number *= number *= number *= number;

            SetConsoleTextAttribute(color, 15);
            printf(" Ваше число у ступенi \x1b[32m8\x1b[0m  = \x1b[31m%llu\x1b[0m\n\n", number);
            break;
        }
        case 4: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Завдання 4: Помiняти мiсцями значення 2-х змiнних\n");

            SetConsoleTextAttribute(color, 15);
            int b, c, d;
            printf("\n Введiть значення змiнної 1: ");
            SetConsoleTextAttribute(color, 10);
            scanf("%d", &b);

            SetConsoleTextAttribute(color, 15);
            printf("\n Введiть значення змiнної 2: ");
            SetConsoleTextAttribute(color, 4);
            scanf("%d", &c);


            int i = 1;
            while (i < 3)
            {
                int choiceCount;
                SetConsoleTextAttribute(color, 14);
                printf("\n Як Ви хочете помiняти мiсцями значення змiнних?\n");
                printf(" За допомогою 2 змiнних - натиснiть 2\n");
                printf(" За допомогою 3 змiнних - натиснiть 3\n");
                printf(" Повернутися до головного меню - натиснiть 0\n");
                printf(" Ваш вибiр: ");
                scanf("%d", &choiceCount);
                printf("\n");

                SetConsoleTextAttribute(color, 15);

                switch (choiceCount)
                {
                case 0: {
                    main();
                    break;
                }
                case 2: {
                    b = b + c;
                    c = b - c;
                    b -= c;
                    printf(" Змiнна 1 = \x1b[31m%d\x1b[0m, змiнна 2 = \x1b[32m%d\x1b[0m\n\n", b, c);
                    i++;

                    // повернення значень до початкових
                    b = b + c;
                    c = b - c;
                    b -= c;

                    break;
                }
                case 3: {
                    d = b;
                    b = c;
                    c = d;
                    printf(" Змiнна 1 = \x1b[31m%d\x1b[0m, змiнна 2 = \x1b[32m%d\x1b[0m\n\n", b, c);
                    i++;

                    // повернення значень до початкових
                    d = b;
                    b = c;
                    c = d;

                    break;
                }
                default:  printf(" Такого вибору не iснує!\n ");
                    break;
                }
            }
            break;
        }
        case 5: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            printf(" Завдання 5: Порахувати кiлькiсть секунд у роках\n\n");
            SetConsoleTextAttribute(color, 15);

            unsigned long sec1 = 365 * 24 * 60 * 60;
            printf(" 1 year = \x1b[36m%lu\x1b[0m\n\n", sec1); // 31 536 000 правильно

            unsigned long sec10 = sec1 * 10;
            printf(" 10 years =\x1b[36m%lu\x1b[0m\n\n", sec10); // 315 360 000 правильно

            unsigned long sec100 = sec1 * 100;
            printf(" 100 years = \x1b[36m%lu\x1b[0m\n\n", sec100); // 3 153 600 000 правильно

            // далi починаються помилки при множеннi, хоча числа у дiапазонi!!!
            unsigned long long sec1000 = 3153600000000;
            printf(" 1 000 years = \x1b[36m%llu\x1b[0m\n\n", sec1000);

            unsigned long long sec10000 = 31536000000000000;
            printf(" 10 000 years = \x1b[36m%llu\x1b[0m\n\n", sec10000);

            unsigned long long sec100001 = 10000 * 365 * 24 * 60 * 60;
            printf(" 10 000 years (*) = \x1b[31m%llu\x1b[0m\n\n", sec100001); // 1 827 387 392 чому?????

            // unsigned long long sec100000 = 3153600000000000000000; підкреслює червоним надто велике цiле число
            // printf("sec1 = %llu\n\n", sec10000);
            break;
        }
        case 6: {
            system("cls");
            break;
        }
        case 7: {
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