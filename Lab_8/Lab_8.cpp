/****************************************************/
/*             Лабораторна робота № 8               */
/*         Одновимiрнi масиви i покажчики           */
/*         Приклад виконання. Варiант №19           */
/****************************************************/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <windows.h>  

using namespace std;

void FillingArr(int* arr, int SIZE, int x);
void СreateArrTreeMin(int* arr, int* newArr, int SIZE, int NEWSIZE);

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleTextAttribute(color, 14);

    cout << " ЛАБОРАТОРНА РОБОТА 8. Одновимiрнi масиви i покажчики" << endl;
    cout << endl;

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        cout << " Перелiк завданнь:" << endl;
        cout << " 0: Основне завдання: Знайти три першi мiнiмальнi числа. Записати їх в новий масив" << endl;
        cout << " 1: Додаткове завдання 1: З масиву А зробити масиви В, C, D та записати у масив А" << endl;
        cout << " 2: Очистити консоль" << endl;
        cout << " 3: Завершити програму" << endl;
        cout << endl;
        cout << " Оберiть номер завдання: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 0: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            cout << " Основне завдання: Знайти три першi мiнiмальнi числа. Записати їх в новий масив" << endl;
            cout << endl;

            const int SIZE = 10;
            const int NEWSIZE = 3;

            int arr[SIZE];
            int* ptrArr = arr;

            int newArr[NEWSIZE];
            int* ptrNewArr = newArr;
            /*int* ptrArr = &arr[0];
            int* ptrNewArr = &newArr[0];*/ /*те ж саме*/

            FillingArr(arr, SIZE, 100);

            СreateArrTreeMin(arr, newArr, SIZE, NEWSIZE);

            break;
        }
        case 1: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            cout << " Додаткове завдання 1: З масиву А зробити масиви В, C, D та записати у масив А" << endl;
            cout << endl;

            int A[] = { -9,  17, -16, -50, 0, 19, -26,  28, 8,  12,  14, 0 };
            const int sizeA = sizeof(A) / sizeof(int);
            int* ptrA = A;

            int B[sizeA] = { 0 };
            int sizeB = sizeof(B) / sizeof(int);
            int* ptrB = B;

            int C[sizeA] = { 0 };
            int sizeC = sizeof(C) / sizeof(int);
            int* ptrC = C;

            int D[sizeA] = { 0 };
            int sizeD = sizeof(D) / sizeof(int);
            int* ptrD = D;

            SetConsoleTextAttribute(color, 11);
            cout << "  Початковий масив A:" << endl;

            for (int i = 0; i < sizeA; i++) {
                if (*(A + i) == 0) {
                    SetConsoleTextAttribute(color, 10);
                }
                else if (*(A + i) > 0)
                {
                    SetConsoleTextAttribute(color, 12);
                }
                else {
                    SetConsoleTextAttribute(color, 3);
                }
                cout << setw(4) << *(A + i);
            }
            cout << endl << endl;

            SetConsoleTextAttribute(color, 11);
            cout << "  Масив B < 0: " << endl;
            SetConsoleTextAttribute(color, 3);
            int i_b = 0;
            for (int i = 0; i < sizeA; i++) {

                if (*(A + i) < 0) {
                    *(B + i_b++) = *(A + i);
                }
            }

            for (int i = 0; i < i_b; i++) {
                cout << setw(4) << *(B + i);
            }

            cout << endl << endl;

            SetConsoleTextAttribute(color, 11);
            cout << "  Mасив C > 0: " << endl;
            SetConsoleTextAttribute(color, 12);
            int i_c = 0;
            for (int i = 0; i < sizeA; i++) {
                if (*(A + i) > 0) {
                    *(C + i_c++) = *(A + i);
                }
            }

            for (int i = 0; i < i_c; i++) {
                cout << setw(4) << *(C + i);
            }
            cout << endl << endl;

            SetConsoleTextAttribute(color, 11);
            cout << "  Mасив D == 0: " << endl;
            SetConsoleTextAttribute(color, 10);
            int i_d = 0;
            for (int i = 0; i < sizeA; i++) {
                if (*(A + i) == 0) {
                    *(D + i_d++) = *(A + i);
                }
            }

            for (int i = 0; i < i_d; i++) {
                cout << setw(4) << *(D + i);
            }
            cout << endl << endl;

            SetConsoleTextAttribute(color, 11);
            cout << "  Новий масив A:" << endl;

            sizeB = i_b;
            sizeC = i_c;
            sizeD = i_d;

            for (int i = 0; i < sizeA; i++) {

                if (i < sizeD) {
                    SetConsoleTextAttribute(color, 10);
                    *(A + i) = *(D + i);
                }
                else if (i >= sizeD && i < (sizeD + sizeB)) {
                    SetConsoleTextAttribute(color, 3);
                    *(A + i) = *(B + i - sizeD);
                }
                else if (i >= (sizeD + sizeB)) {
                    A[i] = C[i - sizeB - sizeD];
                    SetConsoleTextAttribute(color, 12);
                    *(A + i) = *(C + i - sizeB - sizeD);
                }
                cout << setw(4) << A[i];
            }
            cout << endl << endl;

            break;
        }
        case 2: {
            system("cls");
            break;
        }
        case 3: {
            exit(0);
            break;
        }
        default: {
            cout << " Такого вибору не iснує!" << endl << endl;
            break;
        }

        }
    }
}

void FillingArr(int* ptrArr, int SIZE, int x) {
    SetConsoleTextAttribute(color, 11);
    cout << " Функцiя створення ПОЧАТКОВОГО масиву:" << endl << endl;
    SetConsoleTextAttribute(color, 3);
    cout << "  Початковий масив:" << endl;
    SetConsoleTextAttribute(color, 6);
    for (int i = 0; i < SIZE; i++) {
        *ptrArr = rand() % x;
        cout << setw(4) << *ptrArr++;
    }
    cout << endl << endl;
}

void СreateArrTreeMin(int* arr, int* newArr, int SIZE, int NEWSIZE) {
    SetConsoleTextAttribute(color, 11);
    cout << " Функцiя створення НОВОГО масиву з 3-х MIN початкового масиву:" << endl << endl;
    SetConsoleTextAttribute(color, 6);
    int t;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++)
        {
            if (*(arr + i) > *(arr + j)) {
                t = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = t;
            }
        }
    }
    SetConsoleTextAttribute(color, 3);
    cout << "  Сортований масив:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (i < NEWSIZE) {
            SetConsoleTextAttribute(color, 6);
        }
        else {
            SetConsoleTextAttribute(color, 14);
        }
        cout << setw(4) << *(arr + i);
    }
    cout << endl << endl;

    SetConsoleTextAttribute(color, 3);
    cout << "  Новий масив:" << endl;
    SetConsoleTextAttribute(color, 6);

    for (int i = 0; i < NEWSIZE; i++)
    {
        *(newArr + i) = *(arr + i);
        cout << setw(4) << *(newArr + i);
    }
    cout << endl << endl;
}
