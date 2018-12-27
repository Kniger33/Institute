
#include <stdio.h>
#include <string.h>
#include "myF.h"
#include <windows.h>

struct data {
    int number;
    char sname[15];
    char name[15];
    char oname[15];
    char predm[4][15];
    int point[4];
    double Spoint;
};

int add_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fl = 1;
    struct data stud;
    struct data stud1;

    FILE *fp = fopen("studS.txt", "a+");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    printf("Заполните информацию: \nНомер зачётки: ");
    scanf("%d", &stud.number);
    int num = -1;
    while(num != stud1.number) {
        num = stud1.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud1.number, &stud1.sname, &stud1.name, &stud1.oname, &stud1.predm[0], &stud1.predm[1], &stud1.predm[2], &stud1.predm[3], &stud1.point[0], &stud1.point[1], &stud1.point[2], &stud1.point[3], &stud1.Spoint);
        if (stud1.number == stud.number) {
            fclose(fp);
            fl = 0;
            return 1;
        }
    }
    printf("Фамилия: ");
    scanf("%s", &stud.sname);
    printf("Имя: ");
    scanf("%s", &stud.name);
    printf("Отчество: ");
    scanf("%s", &stud.oname);

    /*int i;
    for (i = 0; i < 4;i++) {
        printf("\nНапиши предмет: ");
        fflush()
    }*/

    printf("Предмет 1: ");
    scanf("%s", &stud.predm[0]);
    printf("Оценка по предмету: ");
    scanf("%d", &stud.point[0]);
    printf("Предмет 2: ");
    scanf("%s", &stud.predm[1]);
    printf("Оценка по предмету: ");
    scanf("%d", &stud.point[1]);
    printf("Предмет 3: ");
    scanf("%s", &stud.predm[2]);
    printf("Оценка по предмету: ");
    scanf("%d", &stud.point[2]);
    printf("Предмет 4: ");
    scanf("%s", &stud.predm[3]);
    printf("Оценка по предмету: ");
    scanf("%d", &stud.point[3]);

    stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
     fprintf(fp, " %d %s %s %s %s %s %s %s %d %d %d %d %f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
    fclose(fp);
    printf("\nЖмякай уже что-нить!...");
    getch();
    return 0;
}
int del_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, res = 1;
    printf("Введите номер зачётки, по которому будет удален студент: ");
    scanf("%d", &n);
    int i = 0, count = 0;
    struct data *student;
    struct data stud;

    student = (struct data*)malloc(count * sizeof(struct data));

    FILE *fp;
    fp = fopen("studS.txt", "rb");
    int num = -1;
    while(num != stud.number) {
        num = stud.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &stud.predm[2], &stud.predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
        if (num == stud.number) {
            break;
        }
        count++;
    }
    fclose(fp);
    fp = fopen("studS.txt", "rb");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    student = (struct data*)realloc(student, count * sizeof(struct data));
    for (i = 0; i < count; i++) {
        scanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &student[i].predm[2], &student[i].predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
        student[i] = stud;
    }
    fclose(fp);
    fp = fopen("studS.txt", "wb");
    for (i = 0; i < count; i++)
    {
        if (student[i].number != n) {
        student[i].Spoint = (student[i].point[0] + student[i].point[1] + student[i].point[2] + student[i].point[3]) / 4.0;
        fprintf(fp, "%d %s %s %s %s %s %s %s %d %d %d %d %.2f ", student[i].number, student[i].sname, student[i].name, student[i].oname, student[i].predm[0], student[i].predm[1],  student[i].predm[2], student[i].predm[3], student[i].point[0], student[i].point[1], student[i].point[2], student[i].point[3], student[i].Spoint);
        }
        else {
            res = 0;
        }
    }
    fclose(fp);
    free(student);
    return res;
}

//Record_book - зачетка
int record_book() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Enter student's number: ");
    struct data stud;
    int n, res = 1;
    scanf("%d", &n);
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int num = -1;
    while(num != stud.number) {
        num = stud.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &stud.predm[2], &stud.predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
//      printf("%d %d\n", n, stud.number);
        if (n == stud.number) {
            stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
            res = 0;
            printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
        }
    }
    fclose(fp);
    printf("\nЖмякай уже что-нить!...");
    getch();
    return res;
}
int select_fio_of_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Enter student's name: ");
    struct data stud;
    int res = 1;
    char s[15] = "";
    scanf("%s", &s);
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int poi = -1;
    while(poi != stud.number) {
        poi = stud.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &stud.predm[2], &stud.predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
        stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
        //printf("%s %s\n", s, stud.name);
        if (poi == stud.number) { break; }
        if (strcmp(s, stud.name) == 0) {
            res = 0;
            printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
        }
    }
    fclose(fp);
    printf("\nЖмякай уже что-нить!...");
    getch();
    return res;
}
int mark_of_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Enter student's score: ");
    struct data stud;
    int res = 1;
    float p;
    scanf("%f", &p);
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int poi = -1;
    while(poi != stud.number) {
        poi = stud.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &stud.predm[2], &stud.predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
        stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
        //printf("%f %f\n", p, stud.Spoint);
        if (p == stud.Spoint) {
            res = 0;
            printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
        }
    }
    fclose(fp);
    printf("\nЖмякай уже что-нить!...");
    getch();
    return res;
}
int all_students() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Все жертвы: \n");
    struct data stud;
    FILE *fp = fopen("studS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int num = -1;
    while(num != stud.number) {
        num = stud.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &stud.predm[2], &stud.predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
        stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
        if (num == stud.number) { break; }
        printf("%d %s %s %s\nПредметы   Оценки \n%s -       %d\n%s -      %d\n%s -     %d\n%s -     %d\nСредняя оценка:  %.2f \n\n\n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.point[0], stud.predm[1], stud.point[1],  stud.predm[2], stud.point[2], stud.predm[3], stud.point[3], stud.Spoint);
    }
    fclose(fp);
    printf("\nЖмякай уже что-нить!...");
    getch();
    return 0;
}
