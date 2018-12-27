#include "myS.h"
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

struct data {

    int zachyotka;
    char name[40];
    char distsiplini[5][15];
    int otsenki[5];
    double srednyaya_otsenka;
};

//Add Student
int add_student(int count, struct data *student){

    int i, flag = 0, cur_num;

    printf("\n�������� ����� �������: ");
    scanf("%d", &cur_num);

    for (i = 0; i < count; i++) {
        if(cur_num == student[i].zachyotka) {
            printf("\n��� ������, ������!����� ���� ������ ��� ����!");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        student[count - 1].zachyotka = cur_num;

        printf("�������� ���: ");
        fflush(stdin);                          //���������� � ��������� � ������� ������ ���� ������, ����������� � ������
        gets(student[count - 1].name);
        student[count - 1].srednyaya_otsenka = 0;

        for (i = 0; i < 5; i++) {
            printf("\n�������� �������: ");
            fflush(stdin);
            gets(student[count - 1].distsiplini[i]);

            int j, flag2 = 0;
            for(j = 0; j < i; j++){
                if (myStrcmp((student[count - 1].distsiplini[j]), (student[count - 1].distsiplini[i])) == 0){
                        printf("��� ������, ������!����� ������� ��� ����!\n");
                        flag2 = 1;
                }
            }
            if (flag2 == 1){
                i--;
                continue;
            }
            printf("�������� �������� ������ �� ��������: ");
            scanf("%d", &student[count - 1].otsenki[i]);
            student[count - 1].srednyaya_otsenka += student[count - 1].otsenki[i];
        }
        student[count - 1].srednyaya_otsenka /= 5;
        printf("\n�������!�� �������");
        count++;
    }

    printf("\n������ ��� ���-����!...");
    getch();

    return count;
}


//Del Student
int del_student(int count, struct data *student) {

    int poz, i, flag = 1, cur_num;

    printf("\n����� �������: ");
    scanf("%d", &cur_num);

    for (i = 0; i < count; i++) {
        if(cur_num == student[i].zachyotka) {
            poz = i;
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        for (i = poz; i < count - 1; i++) {
            student[i] = student[i+1];
        }

        count--;
        printf("\n�������!����� ������ ���� ������� � ���� ������ � ��� �����������!");
    }
    else {
        printf("\n��� ������, ������!������ ���!");
    }

    printf("\n������ ��� ���-����!...");
    getch();

    return count;
}


//Select zachyotka
void select_zachyotka(int count, struct data *student) {

    int j, cur_num, flag;

    printf("\n����� �������: ");
    scanf("%d", &cur_num);

    flag = 1;
    for (j = 0; j < count; j++) {
        if (student[j].zachyotka == cur_num) {
            flag = 0;

            printf("\n\n�������!����� ����� �������:\n\n");
            vvod_studenta(j, student);

            break;
        }
    }
    if (flag == 1) {
        printf("\n\n�\n");
    }

    printf("\n������ ��� ���-����!...");
    getch();
}


//Select_name
void select_name(int count, struct data *student) {


    int j, flag = 2;
    char cur_name[40];

    printf("\n�������� ���: ");
    fflush(stdin);
    gets(cur_name);

    for (j = 0; j < count; j++) {
        flag = myStrcmp(cur_name, student[j].name);

        if (flag == 0) {
            printf("\n\n�������!����� ����� �������:\n\n");
            vvod_studenta(j, student);
        }
    }
    if (flag == 2) {
        printf("\n\n��� ������, ������!������ ���!\n");
    }

    printf("\n������ ��� ���-����!...");
    getch();
}


//Select_srednyaya_otsenka
void select_srednyaya_otsenka(int count, struct data *student) {


    int i, flag = 1 , select;
    double cur_mark;

    system("cls");
    printf("�������� ��������\n\n");

    printf("1 - <=;\n2 - >=;\n\n�������� �������: ");
    scanf("%d", &select);

    printf("\n�������� ������: ");
    scanf("%lf", &cur_mark);

    switch(select) {
        case 1:for (i = 0; i < count; i++) {
                    if (student[i].srednyaya_otsenka <= cur_mark && (student[i].srednyaya_otsenka >= 0) && (student[i].srednyaya_otsenka <= 5)) {
                        flag = 0;
                        printf("\n\n�������!����� ������ ���� �������:\n\n");
                        vvod_studenta(i, student);
                    }
                }
                if (flag == 1) {
                    printf("\n\n��� ������, ������!������ ���!\n");
                }
                break;
        case 2: for (i = 0; i < count; i++) {
                    if ((student[i].srednyaya_otsenka >= cur_mark) && (student[i].srednyaya_otsenka >= 0) && (student[i].srednyaya_otsenka <= 5)) {

                        flag = 0;
                        printf("\n\n�������!����� ������ ���� �������:\n\n");
                        vvod_studenta(i, student);
                    }
                }
                if (flag == 1) {
                    printf("\n\n��� ������, ������!������ ���!\n");
                }
                break;
    }

    printf("\n������ ��� ���-����!...");
    getch();
}

////view_students
void view_students(int count, struct data *student) {


    int i;
    printf("��� �������� ����:\n");

    for (i = 0; i < count - 1; i++) {
        printf("\n�������:\n");
        vvod_studenta(i, student);
    }

    printf("\n������ ��� ���-����!...");
    getch();
}

////VVOD Studenta
void vvod_studenta(int i, struct data *student) {
    \
    printf("�������: %d\n", student[i].zachyotka);
    printf("���: %s\n", student[i].name);
    printf("������� ������: %.2lf\n", student[i].srednyaya_otsenka);
}

