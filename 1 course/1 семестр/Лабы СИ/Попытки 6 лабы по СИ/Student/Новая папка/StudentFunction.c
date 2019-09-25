/*#include "myS.h"
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

////ADD Student
int add_student(int count, struct data *student){


    int i, flag = 0, cur_num;

    printf("\nНапишите номер зачётки: ");
    scanf("%d", &cur_num);

    for (i = 0; i < count; i++) {
        if(cur_num == student[i].zachyotka) {
            printf("\nЭто фиаско, братан!Такой уже есть!");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        student[count - 1].zachyotka = cur_num;

        printf("Напишите ФИО: ");
        fflush(stdin);
        gets(student[count - 1].name);
        student[count - 1].srednyaya_otsenka = 0;

        for (i = 0; i < 5; i++) {
            printf("\nНапишите предмет: ");
            fflush(stdin);
            gets(student[count - 1].distsiplini[i]);

            int j, flag2 = 0;
            for(j = 0; j < i; j++){
                if (myStrcmp((student[count - 1].distsiplini[j]), (student[count - 1].distsiplini[i])) == 0){
                        printf("Это фиаско, братан!Такой предмет уже есть!\n");
                        flag2 = 1;
                }
            }
            if (flag2 == 1){
                i--;
                continue;
            }
            printf("Напишите оценки студента по предмету: ");
            scanf("%d", &student[count - 1].otsenki[i]);
            student[count - 1].srednyaya_otsenka += student[count - 1].otsenki[i];
        }
        student[count - 1].srednyaya_otsenka /= 5;
        printf("\nКрасава!Всё кошерно");
        count++;
    }

    printf("\nНажмите любую кнопку...");
    getch();

    return count;
}


////DEL Student
int del_student(int count, struct data *student) {


    int poz, i, flag = 1, cur_num;

    printf("\nНомер зачётки: ");
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
        printf("\nУспех!Студент был найден и убран!");
    }
    else {
        printf("\nЭто фиаско, братан!Такого нет!");
    }

    printf("\nНажмите любую кнопку...");
    getch();

    return count;
}


////SELECT zachyotka
void select_zachyotka(int count, struct data *student) {


    int j, cur_num, flag;

    printf("\nНомер зачётки: ");
    scanf("%d", &cur_num);

    flag = 1;
    for (j = 0; j < count; j++) {
        if (student[j].zachyotka == cur_num) {
            flag = 0;

            printf("\n\nУспех!Студент был найден:\n\n");
            vvod_studenta(j, student);

            break;
        }
    }
    if (flag == 1) {
        printf("\n\nс\n");
    }

    printf("\nНажмите любую кнопку...");
    getch();
}


////SELECT NAME
void select_name(int count, struct data *student) {


    int j, flag = 2;
    char cur_name[40];

    printf("\nНапишите ФИО: ");
    fflush(stdin);
    gets(cur_name);

    for (j = 0; j < count; j++) {
        flag = myStrcmp(cur_name, student[j].name);

        if (flag == 0) {
            printf("\n\nУспех!Студент найден:\n\n");
            vvod_studenta(j, student);
        }
    }
    if (flag == 2) {
        printf("\n\nЭто фиаско, братан!Такого нет!\n");
    }

    printf("\nНажмите любую кнопку...");
    getch();
}


////SELECT srednyaya_otsenka
void select_srednyaya_otsenka(int count, struct data *student) {


    int i, flag = 1 , select;
    double cur_mark;

    system("cls");
    printf("Выберите студента\n\n");

    printf("1 - <=;\n2 - >=;\n\nНапишите команду: ");
    scanf("%d", &select);

    printf("\nНапишите оценку: ");
    scanf("%lf", &cur_mark);

    switch(select) {
        case 1:for (i = 0; i < count; i++) {
                    if (student[i].srednyaya_otsenka <= cur_mark && (student[i].srednyaya_otsenka >= 0) && (student[i].srednyaya_otsenka <= 5)) {
                        flag = 0;
                        printf("\n\nУспех!Студент был найден:\n\n");
                        vvod_studenta(i, student);
                    }
                }
                if (flag == 1) {
                    printf("\n\nЭто фиаско, братан!Такого нет!\n");
                }
                break;
        case 2: for (i = 0; i < count; i++) {
                    if ((student[i].srednyaya_otsenka >= cur_mark) && (student[i].srednyaya_otsenka >= 0) && (student[i].srednyaya_otsenka <= 5)) {

                        flag = 0;
                        printf("\n\nУспех!Студент был найден:\n\n");
                        vvod_studenta(i, student);
                    }
                }
                if (flag == 1) {
                    printf("\n\nЭто фиаско, братан!Такого нет!\n");
                }
                break;
    }

    printf("\nНажмите любую кнопку...");
    getch();
}

////view_students
void view_students(int count, struct data *student) {


    int i;
    printf("Все студенты:\n");

    for (i = 0; i < count - 1; i++) {
        printf("\nСтуденты:\n");
        vvod_studenta(i, student);
    }

    printf("\nНажмите любую кнопку...");
    getch();
}

////VVOD Studenta
void vvod_studenta(int i, struct data *student) {
    \
    printf("Зачётка: %d\n", student[i].zachyotka);
    printf("ФИО: %s\n", student[i].name);
    printf("Средняя оценка: %.2lf\n", student[i].srednyaya_otsenka);
}
*/
