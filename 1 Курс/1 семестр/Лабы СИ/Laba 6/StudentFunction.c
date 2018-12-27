#include "MyStringFunction.h"
#include <stdio.h>
#include <malloc.h>
#include <windows.h>

struct data
{
    int number;
    char fio[40];
};

////ADD Student////
int add_student(int count, struct data *student)
{
    int i, flag = 0, current_number;

    printf("\nWrite the number: ");
    scanf("%d", &current_number);
    for (i = 0; i < count; i++)
    {
        if(current_number == student[i].number)
        {
            printf("\nError: student already in base!\nPress any key to continue...");
            flag = 1;
            getchar();
            break;
        }
    }
    if (flag == 0)
    {
        student[count - 1].number = current_number;
        printf("Write the FIO: ");
        getchar();
        gets(student[count - 1].fio);
        printf("\nSuccessfull!\nPress any key to continue...");
        getchar();
        count++;
    }
    return count;
}

////DEL Student///
int del_student(int count, struct data *student)
{
    int poz, i, flag = 1, current_number;
    printf("\nWrite the number: ");
    scanf("%d", &current_number);
    for (i = 0; i < count; i++)
    {
        if(current_number == student[i].number)
        {
            poz = i;
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        for (i = poz; i < count - 1; i++)
        {
            student[i] = student[i+1];
        }
        count--;
        printf("\nSuccessfull: student find in the base and deleted!\nPress any key to continue...");
        getchar();
        getchar();
    }
    else
    {
        printf("\nError: student not find in the base!\nPress any key to continue...");
        getchar();
    }
    return count;
}

////SELECT Student////
void select_student(int count, struct data *student)
{
    int i, current_number, current_fio, select, flag;
    system("cls");
    printf("Select student\n\n");
    printf("1 - select of number;\n2 - select of FIO;\n\nWrite command: ");
    scanf("%d", &select);

    switch(select)
    {
        case 1: printf("\nWrite the number: ");
                scanf("%d", &current_number);
                flag = 1;
                for (i = 0; i < count; i++)
                {
                    if (student[i].number == current_number)
                    {
                        flag = 0;
                        printf("\n\nStudent was founded\n");
                        printf("Number: %d\n", student[i].number);
                        printf("FIO: %s\n", student[i].fio);
                        printf("\nPress any key to continue...");
                        getchar();
                        getchar();
                        break;
                    }
                }
                if (flag == 1)
                {
                    printf("\n\nError: student not founded!\n");
                    printf("\nPress any key to continue...");
                    getchar();
                }
        //case 0:
    }
}
