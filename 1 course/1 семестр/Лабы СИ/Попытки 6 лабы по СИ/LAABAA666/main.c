#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "myF.h"


struct data {
    int number;
    char sec_name[15];
    char name[15];
    char patronym[15];          //��������
    char discp[4][15];
    int mark[4];
    double av_mark;
};

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int act = 1;
    while (act)
    {
        int com;
        int result;
        printf("�������� ��������: \n �������� �������� - 1\n ������� �������� - 2\n ����� ������������ - 3\n �������� ���� ����� - 4\n ������� ��������� - 0\n  ");
        scanf("%d", &com);
        switch(com)
        {
            //���������� ��������
            case 1: {
                system("cls");
                result = add_student();
                if (result == 0) {
                    printf("���� ������� ������� � ������!\n\n");
                } else if (result == 1) {
                    printf("����� ������ ���� ��� ����\n\n");
                } else {
                    printf("������ �������� ��� �������� �����\n\n");
                }
                break;
            }
            //�������� ��������
            case 2: {
                system("cls");
                result = del_student();
                if (result == 0) {
                    printf("������ ���� ������:\n\n");
                } else if (result == 1) {
                    printf("������ �������� � ��� ���\n\n");
                } else {
                    printf("������ �������� �����\n\n");
                }
                break;
            }
            //����� ��������
            case 3: {
                system("cls");
                int com2;
                printf("����� ������������: \n");
                printf("��������, ��� ��� �����:\n �� ������ ������� - 1\n �� ����� - 2\n �� ������� ������ - 3  ");
                scanf("%d", &com2);
                switch(com2)
                {
                    //����� �� ������ ��ר���
                    case 1: {

                        result = record_book();
                        if (result == 0) {
                            printf("������ ���� ������:\n\n");
                        } else if (result == 1) {
                            printf("������ �������� � ��� ���\n\n");
                        } else {
                            printf("������ �������� ��� �������� �����\n\n");
                        }
                        break;
                    }
                    //����� �� ���
                    case 2: {
                        result = select_fio_of_student();
                        if (result == 0) {
                            printf("������ ���� ������: \n\n");
                        } else if (result == 1) {
                            printf("������ �������� � ��� ���\n\n");
                        } else {
                            printf("������ �������� ��� �������� �����\n\n");
                        }
                        break;
                    }
                    //����� �� ������
                    case 3: {
                        result = mark_of_student();
                        if (result == 0) {
                            printf("������ ���� ������: \n\n");
                        } else if (result == 1) {
                            printf("������ �������� � ��� ���\n\n");
                        } else {
                            printf("������ �������� ��� �������� �����\n\n");
                        }
                        break;
                    }
                    default: {
                        printf("���...������,�� ������ ��-����-���. ��������-�� ��� ������� :)\n");
                    }
                }
                break;
            }

            //����� ���� ���������
            case 4: {
                system("cls");
                all_students();
                break;
            }
            case 0: {
                printf("�� �������� � ����� ����, ��� ���� �������!\n");
                system("pause");
                act = 0;
                break;
            }
            default: {
                printf("\n���...������,�� ������ ��-����-���. ��������-�� ��� ������� :)\n");
            }
        }
        system("cls");
    }
    return 0;
}

