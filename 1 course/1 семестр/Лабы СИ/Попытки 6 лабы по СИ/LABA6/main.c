#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myF.h"

typedef struct {
    char *name
}name;

typedef struct {
    int math, rus, eng, fizra;
}predmeti;

typedef struct {
    name FIO;
    int zachyotka;
    predmeti pred;
}Student;

Student *students;

int main()
{
    char *name = "test.txt";
    int i = 0;
    int num;

    while(1){
        system("cls");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Search by average score\n");
        printf("4. Exit\n\n");

        printf("Select: ");

        scanf("%d", &num);

        switch(num){
            case 1:
                i = read_students(name);
                i--;
                i = add_student(i);
                break;
            case 2:
                i = delete_student(i);
                write_students(students, i);
                break;
            case 3:
                select_student(i);
                break;
            case 4:
                write_students(students, i);
                int k;
                /*for (k = 0; k < i; k++) {
                    free(students.FIO.name);
                }*/
                free(students);
                exit(0);
            default:
                exit(-1);
                break;
        }

        printf("\n");
        system("pause");
    }

    return 0;
}
