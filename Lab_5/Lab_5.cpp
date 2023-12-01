/**************************************************/
/*             Лабораторна робота №5              */
/*               Робота з масивами                */
/*           Приклад рiшення. Варiант №19         */
/**************************************************/

#define _CRT_SECURE_NO_WARNINGS
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

    cout << " ЛАБОРАТОРНА РОБОТА 5" << endl;
    cout << endl;

    int choice;

    while (true)
    {
        SetConsoleTextAttribute(color, 14);
        cout << " Перелiк завданнь:" << endl;
        cout << " 0: Основне завдання: Заповнити одномiрний масив унiкальними числами" << endl;
        cout << " 1: Додаткове завдання 1: Квитки на лiтак" << endl;
        cout << " 2: Додаткове завдання 2: Додати/видалити з масиву" << endl;
        cout << " 3: Очистити консоль" << endl;
        cout << " 4: Завершити програму" << endl;
        cout << "\n Оберiть номер завдання: ";

        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 0: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            cout << " Основне завдання: Заповнити одномiрний масив унiкальними числами" << endl;
            cout << endl;
            srand(time(NULL));

            const int SIZE = 20;
            int arr[SIZE];
            bool isExist;

            for (int i = 0; i < SIZE; )
            {
                isExist = false;
                int newRandomValue = rand() % 100;

                for (int j = 0; j < SIZE; j++)
                {
                    if (arr[j] == newRandomValue) {
                        isExist = true;
                        break;
                    }
                }

                if (!isExist) {
                    arr[i] = newRandomValue;
                    i++;
                }
            }

            for (int k = 0; k < SIZE; k++)
            {
                SetConsoleTextAttribute(color, 12);
                cout << setw(4) << arr[k];
            }

            cout << endl << endl;
            break;
        }
        case 1: {

            system("cls");

            SetConsoleTextAttribute(color, 14);
            cout << " Додаткове завдання 1: Квитки на лiтак" << endl;
            cout << endl;

            int const SIZE = 5;
            int seatSmoke[SIZE] = { 0 };
            int seatNoSmoke[SIZE] = { 0 };
            int choice = 0;
            int flight = 1;
            int occupiedSeat = 0;

            SetConsoleTextAttribute(color, 13);
            cout << " Booking tickets for flight No. " << flight << endl;
            cout << endl;

            while (true) {
                {
                    SetConsoleTextAttribute(color, 14);
                    cout << " Do you smoke? " << endl;
                    cout << " 1. YES" << endl;
                    cout << " 2. NO" << endl;
                    cout << " 3. Clear" << endl;
                    cout << " 4. Go back" << endl;
                    cout << " 5. Out" << endl;
                    cout << endl;
                    cout << " Your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        SetConsoleTextAttribute(color, 11);
                        cout << " YES" << endl << endl;
                        for (int i = 0; i < SIZE; i++)
                        {
                            if (seatSmoke[i] == 0) {
                                seatSmoke[i] = 1;
                                occupiedSeat += 1;
                                break;

                                for (int i = 0; i < SIZE; i++)
                                {
                                    cout << setw(4) << seatSmoke[i];
                                }
                                cout << endl;
                            }

                            if (seatSmoke[4] == 1) {
                                SetConsoleTextAttribute(color, 12);
                                cout << " All seats are taken. Make a different choice or wait for a new flight" << endl << endl;
                                SetConsoleTextAttribute(color, 14);
                                break;
                            }
                        }
                        break;

                    case 2: SetConsoleTextAttribute(color, 12);
                        cout << " NO" << endl << endl;
                        for (int i = 0; i < SIZE; i++)
                        {
                            if (seatNoSmoke[i] == 0) {
                                seatNoSmoke[i] = 1;
                                occupiedSeat += 1;
                                break;

                                for (int i = 0; i < SIZE; i++)
                                {
                                    cout << setw(4) << seatNoSmoke[i];
                                }
                                cout << endl;
                            }

                            if (seatNoSmoke[4] == 1) {
                                SetConsoleTextAttribute(color, 12);
                                cout << " All seats are taken. Make a different choice or wait for a new flight" << endl << endl;
                                SetConsoleTextAttribute(color, 14);
                                break;
                            }
                        }
                        break;
                    case 3: system("cls");  break;
                    case 4: system("cls"); main();  break;
                    case 5: exit(0);  break;
                    default: {
                        SetConsoleTextAttribute(color, 10);
                        cout << " Invalid selection. Select 1 or 2 or 3 or 4" << endl;
                        break;
                    }
                    }

                    // публикация наличия свободных мест
                    SetConsoleTextAttribute(color, 14);
                    cout << " Smoking areas:     ";
                    for (int i = 0; i < SIZE; i++)
                    {
                        if (seatSmoke[i] == 1) {
                            SetConsoleTextAttribute(color, 4);
                        }
                        else {
                            SetConsoleTextAttribute(color, 10);
                        }
                        cout << setw(4) << seatSmoke[i];
                    }
                    cout << endl;

                    SetConsoleTextAttribute(color, 14);
                    cout << " NON-smoking areas: ";
                    for (int i = 0; i < SIZE; i++)
                    {
                        if (seatNoSmoke[i] == 1) {
                            SetConsoleTextAttribute(color, 4);
                        }
                        else {
                            SetConsoleTextAttribute(color, 10);
                        }
                        cout << setw(4) << seatNoSmoke[i];
                    }
                    cout << endl << endl;
                }

                // бронирование на СЛЕДУЮЩИЙ самолет
                if (occupiedSeat == 10) {
                    flight += 1;
                    occupiedSeat = 0;
                    cout << endl;
                    SetConsoleTextAttribute(color, 13);
                    cout << " Booking tickets for flight No. " << flight << endl;

                    for (int i = 0; i < SIZE; i++)
                    {
                        seatNoSmoke[i] = 0;
                        seatSmoke[i] = 0;
                    }
                    cout << endl;
                }
            }
            break;
        }
        case 2: {
            system("cls");
            SetConsoleTextAttribute(color, 14);
            cout << " Додаткове завдання 2: Додати/видалити з масиву" << endl << endl;
            int choice2;

            while (true)
            {
                SetConsoleTextAttribute(color, 14);
                cout << " Оберiть операцiю для масиву:" << endl;
                cout << " 1: Видалення елементiв" << endl;
                cout << " 2: Додавання елементiв" << endl;
                cout << " 3: Очистити консоль" << endl;
                cout << " 4: Завершити програму" << endl;
                cout << " 5: Повернутися до головного меню" << endl;
                cout << endl;
                cout << " Зробiть Ваш вибiр: ";

                cin >> choice2;
                cout << endl;

                switch (choice2) {
                case 1: {

                    // ВИДАЛЕННЯ ===========================================================
                    system("cls");
                    cout << " 1: Видалення елементiв з масиву" << endl << endl;

                    int arr[] = { 0 };
                    int lengthArr = 0, indexDel = 0, countDel = 0;
                    cout << " Оберiть довжину масива  -> ";
                    cin >> lengthArr;
                    if (lengthArr <= 0) {
                        cout << " Ви не створили масив. Число має бути бiльше 0!" << endl;
                        cout << endl;
                        break;
                    }

                    cout << " Оберiть iндекс, з якого хочете видалити  -> ";
                    cin >> indexDel;
                    if (indexDel < 0 || indexDel > lengthArr) {
                        cout << " Ваше число має бути бiльше 0 та не бiльше " << lengthArr << endl;
                        cout << endl;
                        break;
                    }

                    cout << " Оберiть кiлькiсть елементiв, якi хочете видалити  -> ";
                    cin >> countDel;
                    if (countDel >= (lengthArr - indexDel)) {
                        cout << " Початковий масив менше, нiж Ви намагаєтеся видалили. Змiнiть кiлькiсть або iндекс" << endl;
                        cout << endl;
                        break;
                    }
                    cout << endl;

                    cout << " Початковий массив: ";
                    for (int i = 0; i < lengthArr; i++)
                    {
                        arr[i] = rand() % 100;
                        SetConsoleTextAttribute(color, 11);
                        cout << setw(4) << arr[i];
                    }
                    cout << endl;

                    for (int i = indexDel; i < lengthArr - countDel; i++)
                    {
                        arr[i] = arr[i + countDel];
                    }

                    SetConsoleTextAttribute(color, 14);
                    cout << " Новий масив: ";
                    for (int i = 0; i < lengthArr - countDel; i++) {
                        SetConsoleTextAttribute(color, 11);
                        cout << setw(4) << arr[i];
                    }

                    cout << endl << endl;
                    break;
                }
                case 2: {
                    // ДОДАВАННЯ ===========================================================
                    system("cls");
                    SetConsoleTextAttribute(color, 14);
                    cout << " 2: Додавання елементiв до масиву" << endl << endl;

                    //int arr[] = { 0 };
                    //int addArr[] = { 0 }; //в таком варианте объявления не работает - ПОЧЕМУ? ==========
                    int arr[100];
                    int addArr[100];
                    int lengthArr = 0, indexAdd = 0, countAdd = 0;

                    cout << " Оберiть довжину початкового масиву  -> ";
                    cin >> lengthArr;
                    if (lengthArr <= 0) {
                        cout << " Ви не створили масив. Число має бути бiльше 0!" << endl;
                        cout << endl;
                        break;
                    }

                    cout << " Оберiть iндекс, з якого хочете додати новi елементи  -> ";
                    cin >> indexAdd;
                    if (indexAdd < 0 || indexAdd > lengthArr) {
                        cout << " Ваше число має бути вiд 0 до  " << lengthArr << endl;
                        cout << endl;
                        break;
                    }

                    cout << " Оберiть кiлькiсть елементiв, якi хочете додати  -> ";
                    cin >> countAdd;
                    if (countAdd < 0) {
                        cout << " Ваше число має бути бiльше 0" << endl;
                        break;
                    }
                    cout << endl;


                    cout << " Початковий массив: ";
                    for (int i = 0; i < lengthArr; i++)
                    {
                        // arr[i] = rand() % 100;
                        arr[i] = i + 1;
                        SetConsoleTextAttribute(color, 11);
                        cout << setw(4) << arr[i];
                        SetConsoleTextAttribute(color, 14);
                    }
                    cout << endl;

                    cout << " Новi елементи для додавання: ";
                    for (int i = 0; i < countAdd; i++)
                    {
                        //addArr[i] = rand() % 100;
                        SetConsoleTextAttribute(color, 12);
                        addArr[i] = i + 1;
                        cout << setw(4) << addArr[i];
                        SetConsoleTextAttribute(color, 14);
                    }
                    cout << endl;

                    // розбивання початкового масиву на 2 допомiжних масиви         
                    int newArr1[100];
                    int newArr2[100];

                    for (int i = 0; i < indexAdd; i++)
                    {
                        newArr1[i] = arr[i];
                    }

                    for (int i = indexAdd; i < lengthArr; i++)
                    {
                        newArr2[i] = arr[i];
                    }

                    // створення нового (фiнального) масиву
                    int newArr[200];

                    cout << " Новий масив: ";
                    for (int i = 0; i < (lengthArr + countAdd); i++)
                    {
                        if (i < indexAdd) {
                            SetConsoleTextAttribute(color, 11);
                            newArr[i] = newArr1[i];
                        }
                        else if (i >= indexAdd && i < (indexAdd + countAdd)) {
                            SetConsoleTextAttribute(color, 12);
                            newArr[i] = addArr[i - indexAdd];
                        }
                        else if (i >= (indexAdd + countAdd)) {
                            SetConsoleTextAttribute(color, 11);
                            newArr[i] = newArr2[i - countAdd];
                        }
                        cout << setw(4) << newArr[i];
                    }
                    cout << endl << endl;
                    SetConsoleTextAttribute(color, 14);
                    break;
                }
                case 3: {
                    system("cls");
                    break;
                }
                case 4: {
                    exit(0);
                    break;
                }
                case 5: {
                    system("cls");
                    main();
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
        case 3: {
            system("cls");
            break;
        }
        case 4: {
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
