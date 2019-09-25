#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "myFunctions.h"

using namespace std;


//X++ < Y
void ex_1_1()
{

    double x, y;
    cout << "������� �������� x: ";
    cin >> x;
    cout << "������� �������� y: ";
    cin >> y;
    x++;

    if (
        x > y
        )
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
        cout << "X > Y" << endl << endl;
    }
    else if (
             x < y
             )
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
        cout << "X < Y" << endl << endl;
    }
    else if (
             x == y
             )
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
        cout << "X = Y" << endl << endl;
    }

}

//++X * ++Y + 3
void ex_1_2()
{
    double x, y;
    cout << "������� �������� x: ";
    cin >> x;
    cout << "������� �������� y: ";
    cin >> y;

    ++x;
    x *= ++y + 3;
    cout << "X = " << x << " " << "Y = " << y << endl;
    cout << "X = " << x << endl << endl;
}

//X * Y >= X++
void ex_1_3()
{
    double x, y;
    cout << "������� �������� x: ";
    cin >> x;
    cout << "������� �������� y: ";
    cin >> y;

    if (x * y >= x++)
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
        cout << "X * Y >= X++" << endl;
    }
    else if (x * y < x++)
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
        cout << "X * Y < X++" << endl;
    }
}

//������� ������
void big_example()
{
    char choise;

    cout << "�������� ������ ����� ������: " << endl;
    cout << ">>Integer - 1" << endl;
    cout << ">>Float - 2" << endl;
    cout << ">>Double - 3" << endl << endl;
    cout << ">>����� - 0" << endl;
    cout << ">>��� �����: ";
    cin >> choise;

    switch (choise)
    {
    case '1':
        {
        int b1, b2, x, n, m;

        cout << "������� ��������: " << endl;
        cout << "b1 = ";
        cin >> b1;
        cout << endl << "b2 = ";
        cin >> b2;
        cout << endl << "x = ";
        cin >> x;
        cout << endl << "n = ";
        cin >> n;
        cout << endl << "m = ";
        cin >> m;

        cout << endl << "����� int - " << solve_of_big_example(b1, b2, x, n, m) << endl;

       break;
        }
    case '2':
        {
        float b1, b2, x, n, m;

        cout << "������� ��������: " << endl;
        cout << "b1 = ";
        cin >> b1;;
        cout << endl << "b2 = ";
        cin >> b2;
        cout << endl << "x = ";
        cin >> x;
        cout << endl << "n = ";
        cin >> n;
        cout << endl << "m = ";
        cin >> m;

        cout << endl << "����� float - " << solve_of_big_example(b1, b2, x, n, m) << endl;

        break;
        }
    case '3':
        {
        double b1, b2, x, n, m;

        cout << "������� ��������: " << endl;
        cout << "b1 = ";
        cin >> b1;
        cout << endl << "b2 = ";
        cin >> b2;
        cout << endl << "x = ";
        cin >> x;
        cout << endl << "n = ";
        cin >> n;
        cout << endl << "m = ";
        cin >> m;

        cout << endl << "����� double - " << solve_of_big_example(b1, b2, x, n, m) << endl;

        break;
        }
    case '0':
        return;
    }
}

//������� ������ - ������� int
int solve_of_big_example(int b1, int b2, int x, int n, int m)
{
    int solve = (int)sqrt( b1 * pow(x, n) + b2 * (int)pow( abs( (int)sin(x) ), 1 / n) ) + m / (int)pow( exp(1.0), m * n);
    return solve;
}

//������� ������ - ������� float
float solve_of_big_example(float b1, float b2, float x, float n, float m)
{
    float solve = (float)sqrt( b1 * pow(x, n) + b2 * (float)pow( abs( (float)sin(x) ), 1 / n) ) + m / (float)pow( exp(1.0), m * n);
    return solve;
}

//������� ������ - ������� double
double solve_of_big_example(double b1, double b2, double x, double n, double m)
{
    double solve = (double)sqrt( b1 * pow(x, n) + b2 * (double)pow( abs( (double)sin(x) ), 1 / n) ) + m / (double)pow( exp(1.0), m * n);
    return solve;
}

//������� ����� switch
void areas_switch ()
{
    int locale_exit = 1;

    while (locale_exit)
    {
        system("cls");
        char locale_user_choise;
        double const pi = 3.14;

        cout << "�������� ������� �������: " << endl;
        cout << ">>������� ����� - � " << endl;
        cout << ">>������� ��������������� - � " << endl;
        cout << ">>������� �������� - S " << endl;
        cout << ">>����� - � " << endl << endl;
        cout << ">>��� �����: ";
        cin >> locale_user_choise;
        locale_user_choise = tolower(locale_user_choise);

        switch (locale_user_choise)
        {
        case 'c':
            double r;
            cout << "������� ������: ";
            cin >> r;
            cout << endl << "������� �����: " << pi * r * r << endl;
            system("pause");
            break;
        case 'p':
            char c;
            cout << "�������� ������: " << endl;
            cout << ">>����� ��������� � ������ - 1" << endl;
            cout << ">>����� ��� ������� � ���� ����� ���� - 2" << endl << endl;
            cout << ">>����� - 0" << endl;
            cout << "��� �����:";
            cin >> c;
            if (c == '1')
            {
                double h, b;
                cout << "������� ���������:";
                cin >> b;
                cout << "������� ������:";
                cin >> h;
                cout << "������� ���������������: " << b * h << endl;
            }
            else if (c == '2')
            {
                double a, b, c;
                cout << "������� 1 �������:";
                cin >> a;
                cout << "������� 2 �������:";
                cin >> b;
                cout << "������� ����:";
                cin >> c;
                cout << "������� ���������������: " << a * b * sin(c) << endl;

            }
            else if (c == '0')
            {
                return;
            }
            system("pause");
            break;
        case 's':
            double a;
            cout << "������� �������: ";
            cin >> a;
            cout << endl << "������� ��������: " << a * a << endl;
            system("pause");
            break;
        case 'e':
            return;
        default:
            cout << "��� ����� �������" << endl;
            break;
        }
    }
}

//������� ����� if
void areas_if()
{
    int locale_exit = 1;

    do
    {
        system("cls");
        char locale_user_choise;
        double const pi = 3.14;

        cout << "�������� ������� �������: " << endl;
        cout << ">>������� ����� - � " << endl;
        cout << ">>������� ��������������� - � " << endl;
        cout << ">>������� �������� - S " << endl;
        cout << ">>����� - � " << endl << endl;
        cout << ">>��� �����: ";
        cin >> locale_user_choise;
        locale_user_choise = tolower(locale_user_choise);

        if (locale_user_choise == 'c')
        {
            double r;
            cout << "������� ������: ";
            cin >> r;
            cout << endl << "������� �����: " << pi * r * r << endl << endl;
            system("pause");
        }
        else if(locale_user_choise =='p')
        {
            char c;
            cout << "�������� ������: " << endl;
            cout << "����� ��������� � ������ - 1" << endl << "����� ��� ������� � ���� ����� ���� - 2" << endl << "����� - 0" << endl;
            cout << "��� �����:";
            cin >> c;
            if (c == '1')
            {
                double h, b;
                cout << "������� ���������:";
                cin >> b;
                cout << "������� ������:";
                cin >> h;
                cout << "������� ���������������: " << b * h << endl << endl;
            }
            else if (c == '2')
            {
                double a, b, c;
                cout << "������� 1 �������:";
                cin >> a;
                cout << "������� 2 �������:";
                cin >> b;
                cout << "������� ����:";
                cin >> c;
                cout << "������� ���������������: " << a * b * sin(c) << endl << endl;

            }
            else if (c == '0')
            {
                return;
            }
            system("pause");
        }
        else if (locale_user_choise == 's')
        {
            double a;
            cout << "������� �������: ";
            cin >> a;
            cout << endl << "������� ��������: " << a * a << endl << endl;
            system("pause");
        }
        else if (locale_user_choise == 'e')
        {
            return;
        }
        else
        {
            cout << "��� ����� �������" << endl;
            system("pause");
            break;
        }
    }

    while (locale_exit);

}

//������� Z
void options_z()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int locale_exit = 1;

    while (locale_exit)
    {
        system("cls");

        char loc_user_choise;

        cout << ">>���������� ������ - 1" << endl;
        cout << ">>������� NxM - 2" << endl;
        cout << ">>����� ���� � ����� �������� - 3" << endl;
        cout << ">>����� � 2 ��������������  - 4" << endl << endl;
        cout << ">>>����� - 0" << endl << endl;
        cout << ">>��� �����:";
        cin >> loc_user_choise;

        switch (loc_user_choise)
        {
            //���������� ������
        case '1':
            {
            int n;
            cout << "������� ������ �������: ";
            cin >> n;

            if (n <= 0)
            {
                cerr << "������������ ������" << endl;
                break;
            }

            int mas[n];

            cout << endl << "��������� ������: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "������� [" << i << "]:";
                cin >> mas[i];
            }

            int temp;

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (mas[j] > mas[j + 1])
                    {
                        temp = mas[j];
                        mas[j] = mas[j + 1];
                        mas[j + 1] = temp;
                    }
                }
            }
            cout << endl << "��������������� ������: ";
            for (int i = 0; i < n; i++)
            {
                cout << mas[i] << " ";
            }
            cout << endl;

            delete [] mas; // ������������ ������

            system("pause");
            break;
            }
            //������� NxM
        case '2':
            {
            int n, m;

            cout << "������� ������� �������:" << endl;
            cout << "N(������) - ";
            cin >> n;
            cout << endl << "M(�������) - ";
            cin >> m;

            int mas[n][m];

            cout << endl << "��������� ������: " << endl;


            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << "mas [" << i << "][" << j << "] = ";
                    cin >> mas[i][j];
                }
            }

            cout << "��� ������: " << endl;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << setw(5) << mas[i][j] << " ";
                }
                cout << endl;
            }

            int i1, j1, max_chetn = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (
                        i < j
                        && mas[i][j] % 2 == 0
                        && mas[i][j] > max_chetn
                        )
                    {
                        i1 = i;
                        j1 = j;
                        max_chetn = mas[i][j];
                    }
                }

            }



            cout << "�������: " << max_chetn << endl;
            cout << "�������: [" << i1 << "][" << j1 << "]" << endl;

            system("pause");
            break;
            }
            //������ � ���������� �����. ��������� ���������� ���� � ������ � ����� �������� �������.
        case '3':
            {
            string in_string;
            cout << endl << "���� ������: "<< in_string << endl;
            cin.get();
            getline(cin, in_string);

            int i = 0, count_vowel = 0, count_words = 0;
            int j, c = 0;
            string glasn("aeiouy���������");
            for(i = 0; i <= in_string.length(); i++)
            {
                if(in_string[i] != ' ' && in_string[i] != '\0')
                {
                    for(size_t j = 0; j < glasn.length(); j++)
                    {
                        if (in_string[i] == glasn[j])
                        {
                            count_vowel++;
                        }
                    }
                }
                else if (in_string[i] == ' ' || in_string[i] == '\0')
                {
                    if (count_vowel == 2)
                    {
                        count_words++;
                    }
                    count_vowel = 0;
                }
            }
            cout << "���������� ���� � 2 ��������: " << count_words << endl;
            system("pause");
            break;
            }
            //������ ����� � ��� �������������� (��������������1 � ��������������2). �������� � ������ ��������������1 �� ��������������2.
        case '4':
            {
            string my_string;
            cout << endl << "��� �����: " << my_string << endl;
            cin.get();
            getline(cin, my_string);

            string slovo1, slovo2;

            cout << endl << "����� 1: ";
            getline(cin, slovo1);

            cout << endl << "����� 2: ";
            getline(cin, slovo2);

            string::size_type ind;
            while((ind = my_string.find(slovo1)) != std::string::npos)
            {
                my_string.replace(ind, slovo1.size(), slovo2);
            }

            cout << my_string << endl;
            system("pause");
            break;
            }
            //�����
        case '0':
            locale_exit = 0;
            break;
        default:
            cout << "��� ����� �������" << endl << endl;
            system("pause");
            system("cls");
            continue;
        }

    }

}

