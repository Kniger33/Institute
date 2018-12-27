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

        cout << "�������� ����� �������: " << endl;
        cout << ">>��� ������� - 1 " << endl;
        cout << ">>������� ������ - 2 " << endl;
        cout << ">>������� ����� - 3 " << endl;
        cout << ">>������� Z - 4 " << endl << endl;
        cout << ">>����� - 0" << endl << endl;
        cout << ">>��� �����: ";
        cin >> user_choise[0];
        char c_u_c;
        switch (user_choise[0])
        {
//��� �������
        case '1':
            {
            system("cls");

            //X++ < Y
            cout << "������ 1: " << endl << endl;
            ex_1_1();

            //++X * ++Y + 3
            cout << "������ 2: " << endl << endl;
            ex_1_2();

            //X * Y >= X++
            cout << "������ 3: " << endl;
            ex_1_3();
            system("pause");
            break;
            }
//������� ������
        case '2':
            {
            system("cls");
            big_example();
            system("pause");
            break;
            }
//������� �����
        case '3':
            {
            system("cls");

            cout << "����� ������: " << endl;
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
                cout << "��� ����� �������/������������ �������" << endl;
                break;
            }
            system("pause");
            break;
            }
//������� Z
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
            cout << "����� ������� ���, ���������� ��� ���" << endl;
            system("pause");
            break;

        }
    }

    return 0;
}
