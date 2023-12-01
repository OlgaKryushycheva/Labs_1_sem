/*****************************************************/
/*              Лабораторна робота №6                */
/*                 Робота з матрицями                */
/*           Приклад виконання. Варiант №19          */
/*****************************************************/

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <windows.h>  
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);

    cout << " ЛАБОРАТОРНА РОБОТА 6. Двовимiрнi масиви" << endl;
    cout << endl;

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        cout << " Перелiк завданнь:" << endl;
        cout << " 0: Основне завдання: Заповнити двовимiрний масив спiраллю вiд центра вниз" << endl;
        cout << " 1: Додаткове завдання 1: Знайти числа i помiняти мiсцями" << endl;
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
            cout << " Основне завдання: Заповнити двовимiрний масив спiраллю вiд центра вниз" << endl;
            cout << endl;

            const int N = 9;
            int spiralMatrix[N][N];
            int end, num = N * N;
            int i, j, k;

            for (k = 0; k < N / 2; k++) // k - это количество спиралей от центра, каждый раз уменьшается
            {
                // каждая сторона (N - 1, 4 раза)
                end = N - 1 - k;
                for (i = end; i > k; i--, num--) {
                    spiralMatrix[i][k] = num;
                }

                for (j = k; j < end; j++, num--) {
                    spiralMatrix[k][j] = num;
                }

                for (i = k; i < end; i++, num--) {
                    spiralMatrix[i][end] = num;
                }

                for (j = end; j > k; j--, num--) {
                    spiralMatrix[end][j] = num;
                }
            }

            if (N % 2) {  // для N-нечетного (центр)
                spiralMatrix[N / 2][N / 2] = num;
            }

            for (i = 0; i < N; i++)
            {
                for (j = N - 1; j >= 0; j--) {
                    if (spiralMatrix[i][j] > 0 && spiralMatrix[i][j] <= 4) {
                        SetConsoleTextAttribute(color, 12);
                    }
                    else if (spiralMatrix[i][j] > 4 && spiralMatrix[i][j] <= 16) {
                        SetConsoleTextAttribute(color, 14);
                    }
                    else if (spiralMatrix[i][j] > 16 && spiralMatrix[i][j] <= 36) {
                        SetConsoleTextAttribute(color, 6);
                    }
                    else if (spiralMatrix[i][j] > 36 && spiralMatrix[i][j] <= 64) {
                        SetConsoleTextAttribute(color, 10);
                    }
                    else {
                        SetConsoleTextAttribute(color, 9);
                    }

                    cout << setw(4) << spiralMatrix[i][j];
                }
                cout << endl;
            }
            cout << endl;

            break;
        }
        case 1: {
            system("cls");
            cout << " Додаткове завдання 1: Знайти числа i помiняти мiсцями" << endl;
            cout << endl;

            const int ROW = 5;
            const int COL = 5;
            int arr[ROW][COL]{};

            int choice1;

            while (true)
            {
                SetConsoleTextAttribute(color, 14);
                cout << " Варiанти:" << endl;
                cout << " 1: Знайти МАX число у кожному рядку i помiняти з 1-м елементом у рядку" << endl;
                cout << " 2: Знайти MIN число у кожному стовпцi i помiняти з останнiм елементом у стовпцi" << endl;
                cout << " 3: Очистити консоль" << endl;
                cout << " 4: Повернутися до головного меню" << endl;
                cout << " 5: Завершити програму" << endl;
                cout << endl;
                cout << " Оберiть варiант: ";
                cin >> choice1;
                cout << endl;

                switch (choice1)
                {
                case 1: {
                    system("cls");

                    SetConsoleTextAttribute(color, 14);
                    cout << " Знайти МАX число у кожному рядку i помiняти з 1-м елементом у рядку" << endl;
                    cout << endl;

                    SetConsoleTextAttribute(color, 9);
                    cout << " Початковий масив:" << endl;
                    SetConsoleTextAttribute(color, 14);
                    cout << endl;
                    int i, j;

                    for (i = 0; i < ROW; i++)
                    {
                        for (j = 0; j < COL; j++)
                        {
                            if (j == 0) {
                                SetConsoleTextAttribute(color, 9);
                            }
                            else
                            {
                                SetConsoleTextAttribute(color, 14);
                            }
                            arr[i][j] = rand() % 100;
                            cout << setw(4) << arr[i][j];
                        }
                        cout << endl;
                    }
                    cout << endl;

                    int x = 0;

                    for (i = 0; i < ROW; i++)
                    {
                        int max = INT_MIN;
                        for (j = 0; j < COL; j++)
                        {
                            if (arr[i][j] > max) {
                                x = j;
                                max = arr[i][j];
                            }
                        }
                        // печать MAX значений
                        cout << " MAX число у рядку " << i << ": ";
                        SetConsoleTextAttribute(color, 10);
                        cout << max;
                        SetConsoleTextAttribute(color, 14);

                        // меняем местами МАХ и 1-й элемент строки
                        int t = arr[i][x];
                        arr[i][x] = arr[i][0];
                        arr[i][0] = t;
                        cout << endl;
                    }
                    cout << endl;

                    // печатаем новый массив
                    SetConsoleTextAttribute(color, 10);
                    cout << " Новий масив:" << endl;
                    SetConsoleTextAttribute(color, 14);
                    cout << endl;

                    for (int i = 0; i < ROW; i++)
                    {
                        for (int j = 0; j < COL; j++)
                        {
                            if (j == 0) {
                                SetConsoleTextAttribute(color, 10);
                            }
                            else
                            {
                                SetConsoleTextAttribute(color, 14);
                            }
                            cout << setw(4) << arr[i][j];
                        }
                        cout << endl;
                    }
                    cout << endl;
                    break;
                }
                case 2: {
                    system("cls");
                    cout << " Знайти MIN число у кожному стовпцi i помiняти з останнiм елементом у стовпцi" << endl;
                    cout << endl;

                    SetConsoleTextAttribute(color, 9);
                    cout << " Початковий масив:" << endl;
                    SetConsoleTextAttribute(color, 14);
                    cout << endl;


                    for (int i = 0; i < ROW; i++)
                    {
                        for (int j = 0; j < COL; j++)
                        {

                            if (i == ROW - 1) {
                                SetConsoleTextAttribute(color, 9);
                            }
                            else
                            {
                                SetConsoleTextAttribute(color, 14);
                            }
                            arr[i][j] = rand() % 100;
                            cout << setw(4) << arr[i][j];
                        }
                        cout << endl;
                    }
                    cout << endl;

                    int x = 0;

                    for (int j = 0; j < COL; j++)
                    {
                        int min = INT_MAX;
                        for (int i = 0; i < ROW; i++)
                        {
                            if (arr[i][j] < min) {
                                x = i;
                                min = arr[i][j];
                            }
                        }
                        // печать MIN значений
                        SetConsoleTextAttribute(color, 14);
                        cout << " MIN число у стовпцi " << j << ": ";
                        SetConsoleTextAttribute(color, 10);
                        cout << min;
                       
                        // меняем местами МIN и последний элемент столбца
                        int t = arr[x][j];
                        arr[x][j] = arr[ROW - 1][j];
                        arr[ROW - 1][j] = t;

                        cout << endl;
                    }
                    cout << endl;

                    // печатаем новый массив
                    SetConsoleTextAttribute(color, 10);
                    cout << " Новий масив:" << endl;
                    SetConsoleTextAttribute(color, 14);
                    cout << endl;

                    for (int i = 0; i < ROW; i++)
                    {
                        for (int j = 0; j < COL; j++)
                        {
                            if (i == ROW - 1) {
                                SetConsoleTextAttribute(color, 10);
                            }
                            else
                            {
                                SetConsoleTextAttribute(color, 14);
                            }
                            cout << setw(4) << arr[i][j];
                        }
                        cout << endl;
                    }
                    cout << endl;

                    break;
                }
                case 3: {
                    system("cls");
                    break;
                }
                case 4: {
                    system("cls");
                    main();
                    break;
                }
                case 5: {
                    exit(0);
                    break;
                }
                default: {
                    cout << " Такого вибору не iснує!" << endl << endl;
                    break;
                }
                }
            }
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
