#include <stdio.h>
#include <string.h>
#include "stud.h"
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

int studadd() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fl = 1;
    struct data stud;struct data stud1;
    FILE *fp = fopen("studS.txt", "a+");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    printf("Enter the data: \nNumber: ");
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
    printf("Surname: ");
    scanf("%s", &stud.sname);
    printf("Name: ");
    scanf("%s", &stud.name);
    printf("Patronymic: ");
    scanf("%s", &stud.oname);
    printf("Subject 1: ");
    scanf("%s", &stud.predm[0]);
    printf("Score on the subject: ");
    scanf("%d", &stud.point[0]);
    printf("Subject 2: ");
    scanf("%s", &stud.predm[1]);
    printf("Score on the subject: ");
    scanf("%d", &stud.point[1]);
    printf("Subject 3: ");
    scanf("%s", &stud.predm[2]);
    printf("Score on the subject: ");
    scanf("%d", &stud.point[2]);
    printf("Subject 4: ");
    scanf("%s", &stud.predm[3]);
    printf("Score on the subject: ");
    scanf("%d", &stud.point[3]);
    stud.Spoint = (stud.point[0] + stud.point[1] + stud.point[2] + stud.point[3]) / 4.0;
    fprintf(fp, " %d %s %s %s %s %s %s %s %d %d %d %d %f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
    fclose(fp);
    return 0;
}
int studdel() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, res = 1;
    printf("Enter the number of the student to be deleted: ");
    scanf("%d", &n);
    int i = 0, count = 0;
    struct data *student;
    struct data stud;
 //   struct data stud1;
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
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &stud.number, &stud.sname, &stud.name, &stud.oname, &stud.predm[0], &stud.predm[1], &student[i].predm[2], &student[i].predm[3], &stud.point[0], &stud.point[1], &stud.point[2], &stud.point[3], &stud.Spoint);
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
int snum() {

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
    return res;
}
int sname() {

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
    return res;
}
int srait() {

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
    return res;
}
int studall() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("All the students: \n");
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
        printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", stud.number, stud.sname, stud.name, stud.oname, stud.predm[0], stud.predm[1],  stud.predm[2], stud.predm[3], stud.point[0], stud.point[1], stud.point[2], stud.point[3], stud.Spoint);
    }
    fclose(fp);
    return 0;
}
