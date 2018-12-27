#include <iostream>
#include <cstdlib>
#include "myFunctions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int exit = 1;

    while (exit)
    {
        system("cls");
        char user_choise[1] = "";

        cout << "Выберите номер задания: " << endl;
        cout << ">>Три Примера - 1 " << endl;
        cout << ">>Большой пример - 2 " << endl;
        cout << ">>Площади фигур - 3 " << endl;
        cout << ">>Команды Z - 4 " << endl << endl;
        cout << ">>Выход - 0" << endl << endl;
        cout << ">>Ваш выбор: ";
        cin >> user_choise[0];
        char c_u_c;
        switch (user_choise[0])
        {
//Три Примера
        case '1':
            {
            system("cls");

            //X++ < Y
            cout << "Пример 1: " << endl << endl;
            ex_1_1();

            //++X * ++Y + 3
            cout << "Пример 2: " << endl << endl;
            ex_1_2();

            //X * Y >= X++
            cout << "Пример 3: " << endl;
            ex_1_3();
            system("pause");
            break;
            }
//Большой пример
        case '2':
            {
            system("cls");
            big_example();
            system("pause");
            break;
            }
//Площади фигур
        case '3':
            {
            system("cls");

            cout << "Какой способ: " << endl;
            cout << ">>IF - 1" << endl;
            cout << ">>SWITCH - 2" << endl;
            cin >> c_u_c;

            if (c_u_c == '1')
            {
                areas_if();
            }
            else if (c_u_c == '2')
            {
                areas_switch();
            }
            else
            {
                cout << "Нет такой команды/Неправильный регистр" << endl;
                break;
            }
            system("pause");
            break;
            }
//Команды Z
        case '4':
            {
            system("cls");
            options_z();
            system("pause");
            break;
            }
        case '0':
            exit = 0;
            break;
        default:
            cout << "Такой функции нет, попробуйте еще раз" << endl;
            system("pause");
            break;

        }
    }

    return 0;
}
