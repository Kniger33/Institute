#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "MyStringFunction.h"
#include "StudentFunction.h"

struct data
{
    int number;
    char fio[40];
};


int main()
{
    int i, com, active = 1;
    int count = 1;
    // int func(int *count);
    // func(&count)

    struct data *student;
    student = (struct data*)malloc(count * sizeof(struct data));

    while (active)
    {
        printf("1 - new student in base;\n2 - delete student on base;\n3 - select the student;\n9 - close the program;\n\nWrite command: ");
        scanf("%d", &com);
        printf("\n");
        switch(com)
        {
            case 1: count = add_student(count, student);
                    student = (struct data*)realloc(student, count * sizeof(struct data));
                    break;
            case 2: count = del_student(count, student);
                    break;
            case 3: select_student(count, student);
                    break;
            case 9: active = 0;
                    break;
        }
        system("cls");
    }

    for (i = 0; i < count - 1; i++)
    {
        printf("\nN:%d\n", i);
        printf("Number:%d\n", student[i].number);
        printf("FIO:%s\n", student[i].fio);
    }
    free(student);
    return 0;
}
