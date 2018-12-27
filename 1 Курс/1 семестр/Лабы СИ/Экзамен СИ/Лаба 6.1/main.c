#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud_func.h"
#include <windows.h>


int num_of_students;
Student *base;

//�����
void select_choice() {

    int user_choice, record_book;
    double average_mark;
    system("cls");

    printf("����� ��������:\n\n");
    printf("1 - �� ������ �������\n");
    printf("2 - �� ���\n");
    printf("3 - �� ������� ������\n");
    printf("4 - ������ ��� ����� ������� ������\n");
    printf("5 - ������ ��� ����� ������� ������\n\n");

    scanf("%d", &user_choice);

    system("cls");

    switch (user_choice) {

    //�� ��ר���
    case 1:
        printf("������� ����� �������: ");
        scanf("%d", &record_book);
        system("cls");

        Student *rb = select_RB(base, record_book, num_of_students);
        if (rb == NULL) {
            printf("������ �������� ���\n");
            system("pause");
            break;
        }
        print_student(rb);
        system("pause");
        break;

    //�� ���
    case 2:
        printf("������� ���: ");
        char first_name[100];
        char second_name[100];
        char patronym[100];

        scanf("%s%s%s", second_name, first_name, patronym);
        system("cls");

        select_FIO(base, num_of_students, first_name, second_name, patronym);
        system("pause");
        break;

    //�� ������� ������
    case 3:
        printf("������� ������� ������: ");
        scanf("%lf", &average_mark);
        system("cls");

        select_average_mark(base, num_of_students, average_mark);
        system("pause");
        break;

    //������ ��� ����� ������� ������
    case 4:
        printf("������� ������� ������: ");
        scanf("%lf", &average_mark);
        system("cls");
        select_average_mark_more(base, num_of_students, average_mark);
        system("pause");
        break;

    //������ ��� ����� ������� ������
    case 5:
        printf("������� ������� ������: ");
        scanf("%lf", &average_mark);
        system("cls");
        select_average_mark_less(base, num_of_students, average_mark);
        system("pause");
        break;
    default:
        select_choice();
        break;
    }
}

int main(int argc, char *argv[]) {

    //��� �����������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    char default_way[] = "Students.txt";

    if (argc > 1) {
        base = read_student_base(&num_of_students, argv[1]);
    }
    else {
        base = read_student_base(&num_of_students, default_way);
    }

    int user_choise, record_book, exit = 1, i;          //record_book - �������

    //������� ����
    while (exit) {

        system("cls");
        printf("�������� ��������: \n\n");
        printf("1 - �������� ��������\n");
        printf("2 - ������� ��������\n");
        printf("3 - ����� ��������\n");
        printf("4 - ��������� � ����\n\n");
        printf("5 - �������� ���� ���������\n\n");
        printf("0 - �����\n\n");

        printf("��� �����: ");
        scanf("%d", &user_choise);

        system("cls");

        switch (user_choise) {
        //���������� ��������
        case 1:
            add_student(&base, &num_of_students);
            system("pause");
            break;

        //�������� ��������
        case 2:
            printf("������� ����� �������: ");
            scanf("%d", &record_book);
            system("cls");
            delete_student(&base, &num_of_students, record_book);
            system("pause");
            break;

        //����� ��������
        case 3:
            select_choice();
            break;

        //���������� � ����
        case 4:
            if (argc > 1) {
                write_student_in_base(base, num_of_students, argv[1]);
            } else {
                write_student_in_base(base, num_of_students, default_way);
            }
            break;

        //����� ���� ���������
        case 5:
            for (i = 0; i < num_of_students; i++) {
                print_student(base + i);
            }
            if (num_of_students == 0) {
                printf("��������� ���\n");
            }
            system("pause");
            break;

        //�����
        case 0:
            printf("\n\n�� ��������!\n\n");
            system("pause");
            exit = 0;
            break;
        default:
            break;
        }
    }

    if (argc > 1) {
        write_student_in_base(base, num_of_students, argv[1]);
    }
    else {
        write_student_in_base(base, num_of_students, default_way);
    }

    //������������ ������
    for (i = 0; i < num_of_students; i++) {
        free(base[i].first_name);
        free(base[i].second_name);
        free(base[i].patronym);
    }

    free(base);
    return 0;
}
