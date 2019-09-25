#include <stdio.h>
#include <string.h>
#include "myF.h"
#include <windows.h>

struct data {
    int number;
    char sec_name[15];
    char name[15];
    char patronym[15];
    char discp[4][15];
    int mark[4];
    double Smark;
};


///////////���������� ��������///////

int add_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fl = 1;
    struct data student;
    struct data student1;

    FILE *fp = fopen("studentS.txt", "a+");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    printf("��������� ����������: \n����� �������: ");
    scanf("%d", &student.number);
    int num = -1;
    while(num != student1.number) {
        num = student1.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student1.number, &student1.sec_name, &student1.name, &student1.patronym, &student1.discp[0], &student1.discp[1], &student1.discp[2], &student1.discp[3], &student1.mark[0], &student1.mark[1], &student1.mark[2], &student1.mark[3], &student1.Smark);
        if (student1.number == student.number) {
            fclose(fp);
            fl = 0;
            return 1;
        }
    }
    printf("�������: ");
    scanf("%s", &student.sec_name);
    printf("���: ");
    scanf("%s", &student.name);
    printf("��������: ");
    scanf("%s", &student.patronym);

    /*int i;
    for (i = 0; i < 4;i++) {
        printf("\n������ �������: ");
        fflush()
    }*/

    printf("������� 1: ");
    scanf("%s", &student.discp[0]);
    printf("������ �� ��������: ");
    scanf("%d", &student.mark[0]);
    printf("������� 2: ");
    scanf("%s", &student.discp[1]);
    printf("������ �� ��������: ");
    scanf("%d", &student.mark[1]);
    printf("������� 3: ");
    scanf("%s", &student.discp[2]);
    printf("������ �� ��������: ");
    scanf("%d", &student.mark[2]);
    printf("������� 4: ");
    scanf("%s", &student.discp[3]);
    printf("������ �� ��������: ");
    scanf("%d", &student.mark[3]);

    student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
     fprintf(fp, " %d %s %s %s %s %s %s %s \n%d %d %d %d %f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
    fclose(fp);

    printf("\n������� ��� �����������...");
    getch();
    return 0;
}

//////////�������� ��������//////////

int del_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, result = 1;
    printf("������� ����� �������, �� �������� ����� ������ �������: ");
    scanf("%d", &n);
    int i = 0, count = 1;
    struct data *student2;
    struct data *student;
    //char student1[] = student;

    student2 = (struct data*)malloc(count * sizeof(struct data));
    FILE *fp;
    fp = fopen("studentS.txt", "rb");
    int for_del = -1;

    int find = mySearch();

    for (i; i < find; i++) {
        if (student[i].number == n) {
            for_del = 1;
        }
    }
    int id_stud;
   if (for_del == 1) {
        for (i = 0; i < find; i++) {
            if (student[i].number == n) {
                id_stud = i;
                break;
            }
        }
        printf("������� �����");
   }
   else printf("������ �������� ���");

    free(student[id_stud].sec_name);
    free(student[id_stud].name);
    free(student[id_stud].patronym);

    find -= 1;

    for (i = id_stud; i < find; i++) {
        student[i] = student[i + 1];
    }
    student = (struct data*) realloc(student, find * sizeof(struct data));
    /*int num = 0;
    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        if (num == student.number) {
            continue;
        }
        count++;
    }
    fclose(fp);
    fp = fopen("studentS.txt", "rb");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    student2 = (struct data*)realloc(student2, count * sizeof(struct data));
    for (i = 0; i < count; i++) {
        scanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student2[i].discp[2], &student2[i].discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student2[i] = student;
    }
    fclose(fp);
    fp = fopen("studentS.txt", "wb");
    for (i = 0; i < count; i++)
    {
        if (student2[i].number != n) {

        student2[i].Smark = (student2[i].mark[0] + student2[i].mark[1] + student2[i].mark[2] + student2[i].mark[3]) / 4.0;
        fprintf(fp, "%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f ", student2[i].number, student2[i].sec_name, student2[i].name, student2[i].patronym, student2[i].discp[0], student2[i].discp[1],  student2[i].discp[2], student2[i].discp[3], student2[i].mark[0], student2[i].mark[1], student2[i].mark[2], student2[i].mark[3], student2[i].Smark);
        }
        else {
            result = 0;
        }
    }*/
    fclose(fp);
    free(student2);

    printf("\n������� ��� �����������...");
    getch();
    return result;
}

/////////������� �� ������ �������///
/////////Record_book - �������///////

void record_book() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    printf("������� ����� ������� ������ �����: ");
    struct data student;
    int num_of_rb, result = 1;
    scanf("%d", &num_of_rb);
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        printf("������ �������� ��� �������� �����");
    }

    int num = 0;
    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);

        if (num_of_rb == student.number) {
            student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
            result = 0;
            printf("����� ������� ������: \n\n");
            printf("%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
            num = student.number;
        }
    }
    fclose(fp);

    if (result == 1) {
        printf("������ �������� ���\n\n");
    }

    printf("\n������� ��� �����������...");
    getch();

}

/////////������� �� ���//////////////

void select_fio_of_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    printf("������� ��� : ");
    struct data student;
    int result = 1;
    char sec_name[100] = "";
    char name[100] = "";
    char patronym[100] = "";
    scanf("%s%s%s", &sec_name, &name, &patronym);
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int point = -1;
    while(point != student.number) {
        point = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;

        if (point == student.number) {
            break;
        }
        else if ((strcmp(sec_name, student.sec_name) == 0) && (strcmp(name, student.name) == 0) && (strcmp(patronym, student.patronym) == 0 ) ) {
            result = 0;
            printf("\n����� ������� ������:\n");
            printf("%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
        }
    }
    fclose(fp);

    if (result == 1) {
        printf("\n������ �������� ���\n");
    }
    printf("\n������� ��� �����������...");
    getch();
}


/////////������� �� ������///////////

void mark_of_student(const int counter ) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

   // printf("������� ������ ������ �����: ");
    struct data student;
    int  select, i = -1, flag = 2;
    double cur_mark;
    //float p;
    //scanf("%f", &p);
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    printf("1 - <=;\n2 - >=;\n\n�������� �������: ");
    scanf("%d", &select);

    printf("\n�������� ������: ");
    scanf("%lf", &cur_mark);


    /*student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
    double x = student.Smark;*/

    int poi = -1, num = -1;
    while(fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%lf", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark) && num < 4) {
        num = student.number;
        //fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%lf", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
        double x = student.Smark;
        if (select == 1) {
            for(i ; i < counter; i++) {
                    /*printf("\nasd\n");
                    system("pause");*/
                    if (x <= cur_mark && x >= 0 && x <= 5) {
                        flag = 0;
                        printf("\n\n����� ������� ������:\n\n");
                        //printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
                        printf("�������: %d\n", student.number);
                        printf("�������: %s\n", student.sec_name);
                        printf("���: %s\n", student.name);
                        printf("��������: %s\n", student.patronym);
                        printf("������� ������: %.2lf\n", student.Smark);
                        system("pause");
                        student.number = num + 1;
                        continue;
                    }
                    else {
                        //printf("\n\n������ ������ � ��� � ������������� ���!���������� � �������!\n");
                        flag = 2;
                        continue;


                    }
                }
            }

        else if (select == 2) {
            for (i ; i < counter; i++) {
                    if (x >= cur_mark && x >= 0 && x <= 5) {
                        flag = 0;
                        printf("\n\n����� ������� ������:\n\n");
                        //printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
                        printf("�������: %d\n", student.number);
                        printf("�������: %s\n", student.sec_name);
                        printf("���: %s\n", student.name);
                        printf("��������: %s\n", student.patronym);
                        printf("������� ������: %.2lf\n", student.Smark);
                        system("pause");
                        student.number = num + 1;
                        continue;

                    }
                    else {
                       // printf("\n\n������ ������ � ��� � ������������� ���!���������� � �������!\n");
                        flag = 2;
                        continue;
                    }
                }
        }
        num++;
        student.number = num + 1;
        i -= 1;
    }
        if (flag == 2) {
            system("pause");
            printf("\n\n������ �������� ���\n");
        }





    printf("\n������� ��� �����������...");
    getch();

}

////////����� ���� ���������/////////


int all_students() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("��� ��������: \n");
    struct data student;
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    int num = -1;
    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
        if (num == student.number) {
            break;
        }
        printf("%d %s %s %s\n��������   ������ \n%s -       %d\n%s -      %d\n%s -     %d\n%s -     %d\n������� ������:  %.2f \n\n\n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.mark[0], student.discp[1], student.mark[1],  student.discp[2], student.mark[2], student.discp[3], student.mark[3], student.Smark);
    }
    fclose(fp);

    printf("\n������� ��� �����������...");
    getch();
    return 0;
}

int mySearch () {

    int sear = 0;
    int num = -1;
    struct data student;
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }


    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
        sear++;
        if (num == student.number) {
            break;
        }
    }
    fclose(fp);
    sear--;

    return sear;

}
