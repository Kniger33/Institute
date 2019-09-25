#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myFunctions.h"
#include <windows.h>

/*struct data {
    int rb;
    char second_name[100];
    char first_name[100];
    char patronym[100];
    char sex[10];
    int ball_1;
    int ball_2;
    int ball_3;
    double total_score;
    int day;
    int month;
    int year;
    int tel_num;
};*/

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int exit = 1;
    while (exit)
    {
        system("cls");
        char func[1] = "";
        int res;

        printf("�������� ��������:\n\n");
        printf(">>�������� ��������� - 1\n");
        printf(">>������� ��������� - 2\n");
        printf(">>����� ����������, �������� 1-3 ����� - 3\n");
        printf(">>������� ���� � ���� �������- 4\n");
        printf(">>����� ���������� �� ���������� - 5\n");
        printf(">>���������� ���������� �������� ����, ���������� � 2003�. - 6\n");
        printf(">>������� ������� ���������� ��������� - 7\n");
        printf(">>����� - 0\n\n");
        printf(">>��� �����: ");
        scanf("%s", &func[0]);
        switch(func[0])
        {
            //���������� ��������
            case '1':
                system("cls");
                res = add_student();
                if (res == 0)
                {
                    printf("�������� ������� ��������\n\n");
                }
                else if (res == 1)
                {
                    printf("����� �������� ��� ����\n\n");
                }
                else
                {
                    printf("������ �������� ��� �������� �����\n\n");
                }
                system("pause");
                break;
            //�������� ��������
            case '2':
                system("cls");
                res = delete_student();
                if (res == 0)
                {
                    printf("�������� ������� ������\n\n");
                }
                else if (res == 1)
                {
                    printf("�������� �� ������\n\n");
                }
                else
                {
                    printf("������ �������� �����\n\n");
                }
                system("pause");
                break;
            //����� ����������,�������� 1-3 �����
            case '3':
                system("cls");
                search_students();
                system("pause");
                break;
            //����� ���� ���������� � ���� �������
            case '4':
                system("cls");
                print_table();
                /*if (res == 0)
                {
                    printf("���������� ���");
                }
                else
                {
                    printf("���������:\n");
                }*/
                system("pause");
                break;
            //����� ���������� �� ����������
            case '5':
                system("cls");
                print_students();
                /*if (res == 0)
                {
                    printf("���������� ���");
                }
                else
                {
                    printf("���������:\n");
                }*/
                system("pause");
                break;
            //���������� ���������� �������� ����, ���������� � 2003�.
            case '6':
                printf("���������� ���������� �������� ����, ���������� � 2003�.: %d\n\n", male_func());
                system("pause");
                break;
            //������� ������� ���������� ���������
            case '7':
                printf("\n������� ������� ���������� ���������: %0.2lf\n\n", average_age());
                system("pause");
                break;
            case '0':
                exit = 0;
                break;

            default: {
                printf("����������� �������\n");
            }
        }
    }
    return 0;
}
//FILE *fp = fopen("spisok.txt", "");
