#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "students_management.h"

int number_of_students;
Student *base;

void select_choice()
{
    int user_choice;
    float av_mark;
    system("cls");

    printf("Select student\n\n");
    printf("1 - Select ID\n");
    printf("2 - Select full name\n");
    printf("3 - Select average mark\n");
    printf("4 - Select more or equal average mark\n");
    printf("5 - Select less or equal average mark\n\n");
    printf("9 - Back\n\n");

    scanf("%d", &user_choice);

    system("cls");

    switch (user_choice)
    {
    case 1:
        printf("Enter ID: ");
        scanf("%d", &user_choice);
        system("cls");
        Student *man = select_ID(base, user_choice, number_of_students);
        if (man == NULL) {
            printf("The student is not found\n");
            system("pause");
            break;
        }
        print_student(man);
        system("pause");
        break;
    case 2:
        printf("Enter full name:\n");
        char f_name[MAX_LEN];
        char s_name[MAX_LEN];
        char t_name[MAX_LEN];
        scanf("%s%s%s", s_name, f_name, t_name);
        system("cls");
        select_FIO(base, number_of_students, f_name, s_name, t_name);
        system("pause");
        break;
    case 3:
        printf("Enter average mark: ");
        scanf("%f", &av_mark);
        system("cls");
        select_average(base, number_of_students, av_mark);
        system("pause");
        break;
    case 4:
        printf("Enter average mark: ");
        scanf("%f", &av_mark);
        system("cls");
        select_average_more(base, number_of_students, av_mark);
        system("pause");
        break;
    case 5:
        printf("Enter average mark: ");
        scanf("%f", &av_mark);
        system("cls");
        select_average_less(base, number_of_students, av_mark);
        system("pause");
        break;
    case 9:
        return;
        break;
    default:
        select_choice();
        break;
    }
}

int main(int argc, char *argv[])
{
    char default_path[] = "Students.base";

    if (argc > 1) {
        base = read_student_base(&number_of_students, argv[1]);
    } else {
        base = read_student_base(&number_of_students, default_path);
    }

    int user_choice, f_exit = 1, i;
    char exit_choice;
    while (f_exit)
    {
        system("cls");
        printf("Main menu\n\n");
        printf("1 - Add student\n");
        printf("2 - Delete student\n");
        printf("3 - Select student\n");
        printf("4 - Show all students\n");
        printf("5 - Save base\n\n");
        printf("9 - Exit\n\n");

        scanf("%d", &user_choice);

        system("cls");

        switch (user_choice)
        {
        case 1:
            add_student(&base, &number_of_students);
            system("pause");
            break;
        case 2:
            printf("Enter student's ID: ");
            scanf("%d", &user_choice);
            system("cls");
            delete_student(&base, &number_of_students, user_choice);
            system("pause");
            break;
        case 3:
            select_choice();
            break;
        case 4:
            for (i = 0; i < number_of_students; i++)
            {
                print_student(base + i);
            }
            if (number_of_students == 0) {
                printf("Base is empty\n");
            }
            system("pause");
            break;
        case 5:
            if (argc > 1) {
                write_student_base(base, number_of_students, argv[1]);
            } else {
                write_student_base(base, number_of_students, default_path);
            }
            break;
        case 9:
            printf("Are you sure? (y/n)\n");
            getchar();
            scanf("%c", &exit_choice);
            exit_choice = toupper(exit_choice);
            if (exit_choice == 'Y') {
                f_exit = 0;
                break;
            } else {
                break;
            }
        default:
            break;

        }

    }

    if (argc > 1) {
        write_student_base(base, number_of_students, argv[1]);
    } else {
        write_student_base(base, number_of_students, default_path);
    }

    for (i = 0; i < number_of_students; i++)
    {
        free((base + i)->first_name);
        free((base + i)->second_name);
        free((base + i)->third_name);
    }

    free(base);
    return 0;
}
