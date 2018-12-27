#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include "myS.h"
#include "myFunctions.h"




struct data {


    int zachyotka;
    char name[40];
    char distsiplini[5][15];
    int otsenki[5];
    double srednyaya_otsenka;

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    int i, com, act = 1, select;
    int count = 1;
    struct data *student;
    student = (struct data*)malloc(count * sizeof(struct data));

    FILE *file;
    FILE *Stud;
    char buffer[BUFSIZ];
    size_t nread;
    file = fopen("Student", "rb");
    Stud = fopen("Stud.txt", "wb");
    while(nread = fread(buffer, sizeof(char), sizeof(buffer), file)){
        fwrite(buffer, sizeof(char), nread, Stud);
    }

    file = fopen("Student", "rb");
    fread(&count, sizeof(int), 1, file);
    student = (struct data*)realloc(student, count * sizeof(struct data));
    for (i = 0; i < count; i++)
    {
        fread(&student[i], sizeof(struct data), 1, file);
    }
    fclose(file);

    printf("%d\n\n", count);


    while (act)
    {
        printf("1 - ���������� ��������;\n2 - �������� �������� ;\n3 - ����� �������� ;\n4 - �������� ���� �����;\n9 - ������� ���������;\n\n�������� �������: ");
        scanf("%d", &com);
        printf("\n");
        switch(com)
        {
            case 1: count = add_student(count, student);
                    student = (struct data*)realloc(student, count * sizeof(struct data));
                    break;

            case 2: count = del_student(count, student);
                    break;

            case 3: system("cls");
                    printf("����� ��������:\n\n");
                    printf("1 - ����� �� �������;\n2 - ����� �� ���;\n3 - ����� �� ������� ������;\n\n�������� �������: ");
                    scanf("%d", &select);
                    switch(select)
                    {
                        case 1: select_zachyotka(count, student);
                                break;
                        case 2: select_name(count, student);
                                break;
                        case 3: select_srednyaya_otsenka(count, student);
                    }
                    break;

            case 4: system("cls");
                    view_students(count, student);
                    break;

            case 9: printf("�� �������� � ����� ����!\n");
                    system("pause");
                    act = 0;
                    break;
        }
        system("cls");
    }

    file = fopen("Student", "wb");
    fwrite(&count, sizeof(int), 1, file);
    for (i = 0; i < count; i++)
    {
        fwrite(&student[i], sizeof(struct data), 1, file);
    }
    fclose(file);

    free(student);
    return 0;
}
