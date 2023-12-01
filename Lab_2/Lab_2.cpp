/*******************************************************/
/*            Лабораторна  робота №2                   */
/*        Типи даних і введення-виведення              */
/*        Приклад виконання. Варіант № 19              */
/*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>  
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "RU");

    printf(" ЛАБОРАТОРНА РОБОТА 2\n");

    /* Ініціалізація змінних */
    char substance1[11], substance2[11], substance3[11];
    char type1, type2, type3;
    char humidity1[8], humidity2[8], humidity3[8];
    float coefficient1, coefficient2, coefficient3;

    printf("\n Таблиця теплопроводностi материалiв\n");

    /* Введення фактичних даних */
    printf("\n Введiть речовину, тип, вологiсть (вiд-до), коефiцiент > ");
    scanf("%s %c %s %f", substance1, &type1, humidity1, &coefficient1);
    printf("\n Введiть речовину, тип, вологiсть (вiд-до), коефiцiент > ");
    scanf("%s %c %s %f", substance2, &type2, humidity2, &coefficient2);
    printf("\n Введiть речовину, тип, вологiсть (вiд-до), коефiцiент > ");
    scanf("%s %c %s %f", substance3, &type3, humidity3, &coefficient3);
    printf("\n");

    /* Виведення таблиці */

    /* виведення заголовків */
    printf(" ------------------------------------------------------\n");
    printf(" | \x1b[36mКоефiцiєнти теплопроводностi материалiв\x1b[0m            |\n");
    printf(" |----------------------------------------------------|\n");
    printf(" |  \x1b[36mРечовина\x1b[0m   | \x1b[36mТип\x1b[0m   | \x1b[36mВологiсть (%%)\x1b[0m  | \x1b[36mКоефiцiент\x1b[0m  |\n");
    printf(" |-------------|-------|----------------|-------------|\n");
    /* виведення рядків фактичних даних */
    printf(" | \x1b[33m%-11s\x1b[0m | \x1b[33m%-5c\x1b[0m | \x1b[33m%-14s\x1b[0m | \x1b[33m%-11.1f\x1b[0m |\n", substance1, type1, humidity1, coefficient1);
    printf(" | \x1b[33m%-11s\x1b[0m | \x1b[33m%-5c\x1b[0m | \x1b[33m%-14s\x1b[0m | \x1b[33m%-11.3f\x1b[0m |\n", substance2, type2, humidity2, coefficient2);
    printf(" | \x1b[33m%-11s\x1b[0m | \x1b[33m%-5c\x1b[0m | \x1b[33m%-14s\x1b[0m | \x1b[33m%-11.2f\x1b[0m |\n", substance3, type3, humidity3, coefficient3);

    /* виведення приміток */
    printf(" |----------------------------------------------------|\n");
    printf(" | \x1b[36mПримiтка: М – метали, Т – термоiзоляцiйнi\x1b[0m          |\n");
    printf(" | \x1b[36mматерiали, A – iншi матерiали\x1b[0m                      |\n");
    printf(" ------------------------------------------------------\n");

    /*
    Aluminum M 0-100 209,3
    Fiberglass T 0-100 0,035
    Clay A 15-20 0,73
    */
}