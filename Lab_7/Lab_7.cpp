/****************************************************/
/*             Лабораторна робота № 7               */
/*          Двовимiрнi масиви i функцiї             */
/*         Приклад виконання. Варiант №19           */
/****************************************************/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <windows.h>  
using namespace std;

#define ROW 3
#define COL 3

const int M = 5;

void TransformArrToMatrix(int arr1[]);
void FillingMatrix(int arr[][M], int N, int x);
void PrintMatrix(int arr[][M], int N);
void SumPosNumRow(int arr[][M], int N);

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    setlocale(LC_ALL, "RU");
    // srand(time(NULL));

    SetConsoleTextAttribute(color, 14);

    cout << " ЛАБОРАТОРНА РОБОТА 7. Двовимiрнi масиви i функцiї" << endl;
    cout << endl;

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        cout << " Перелiк завданнь:" << endl;
        cout << " 0: Основне завдання: Перетворення одновимiрних/двовимiрних масивiв" << endl;
        cout << " 1: Додаткове завдання 1: Рiзнi функцiї для масивiв" << endl;
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
            cout << " Основне завдання: Перетворення одновимiрних/двовимiрних масивiв" << endl;
            cout << endl;

            int arr1[ROW * COL];

            cout << "  Початковий масив:" << endl;
            for (int i = 0; i < ROW * COL; i++)
            {
                arr1[i] = rand() % 100;
                SetConsoleTextAttribute(color, 12);
                cout << setw(4) << arr1[i];
            };
            cout << endl;

            TransformArrToMatrix(arr1);

            SetConsoleTextAttribute(color, 14);
            cout << "  Mасив пiсля перетворення:" << endl;
            for (int i = 0; i < ROW * COL; i++)
            {
                SetConsoleTextAttribute(color, 12);
                cout << setw(4) << arr1[i];
            };
            cout << endl << endl;

            break;
        }
        case 1: {
            system("cls");
            cout << " Додаткове завдання 1: Рiзнi функцiї для масивiв" << endl;
            cout << endl;

            const int N = 5;

            int arr[][M] = { 0 };
            int x = 10;

            FillingMatrix(arr, N, x);

            PrintMatrix(arr, N);

            SumPosNumRow(arr, N);

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

void TransformArrToMatrix(int arr1[]) {

    int arr2[ROW][COL];

    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "  Друк двовимiрного масиву з одновимiрного: " << endl;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            arr2[i][j] = arr1[i * COL + j];
            SetConsoleTextAttribute(color, 11);
            cout << setw(4) << arr2[i][j];
        }
        cout << endl;
    }

    // Знайти середнє з мнiмальних у кожному стовпцi
    float sum = 0;
    float averageMinCol = 0;
    cout << endl;

    for (int j = 0; j < COL; j++)
    {
        int min = INT_MAX;

        for (int i = 0; i < ROW; i++)
        {
            if (arr2[i][j] < min) {
                min = arr2[i][j];
            }
        }
        SetConsoleTextAttribute(color, 14);
        cout << "  MIN-елемент у стовпцi " << j << ":  ";
        SetConsoleTextAttribute(color, 11);
        cout << min << endl;
        sum += min;
    }
    averageMinCol = sum / COL;

    cout << endl;
    SetConsoleTextAttribute(color, 14);
    cout << "  Середнє значення MIN-елементiв у кожному стовпцi: ";
    SetConsoleTextAttribute(color, 11);
    cout << averageMinCol << endl;
    cout << endl;

    // Отримати ОМ з ДМ 
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            arr1[i * COL + j] = arr2[i][j];
        }
    }
    SetConsoleTextAttribute(color, 14);
}

void FillingMatrix(int arr[][M], int N, int x) {
    SetConsoleTextAttribute(color, 11);
    cout << " Функцiя створення масиву: працює" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = rand() % x - x / 2;
        }
    }
    cout << endl;
}

void PrintMatrix(int arr[][M], int N) {
    SetConsoleTextAttribute(color, 11);
    cout << " Функцiя друку масиву: " << endl;
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] > 0) {
                SetConsoleTextAttribute(color, 12);
            }
            else {
                SetConsoleTextAttribute(color, 3);
            }
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void SumPosNumRow(int arr1[][M], int N) {
    SetConsoleTextAttribute(color, 11);
    cout << " Функцiя сумування позитивних значень у кожному рядку: " << endl;
    cout << endl;

    int sum;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < M; j++)
        {
            if (arr1[i][j] > 0) {
                sum += arr1[i][j];
            }
        }
        cout << " Сума позитивних елементiв рядка " << i << ":  ";
        SetConsoleTextAttribute(color, 12);
        cout << sum << endl;
        SetConsoleTextAttribute(color, 11);
    }
    cout << endl << endl;
}
