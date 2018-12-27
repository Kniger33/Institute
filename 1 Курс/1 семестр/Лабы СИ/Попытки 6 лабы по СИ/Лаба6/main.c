#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud_func.h"
#include <ctype.h>
#include <windows.h>

int num_of_students;
Student *base;

//ПОИСК
void select_choice() {

    int user_choice, record_book;
    double average_mark;
    system("cls");

    printf("Поиск студента:\n\n");
    printf("1 - По номеру зачётки\n");
    printf("2 - По ФИО\n");
    printf("3 - По средней оценке\n");
    printf("4 - Больше или равна средней оценке\n");
    printf("5 - Меньше или равна средней оценке\n\n");

    scanf("%d", user_choice);

    system("cls");

    switch (user_choice) {

    //ПО ЗАЧЁТКЕ
    case 1:
        printf("Введите номер зачётки: ");
        scanf("%d", &record_book);
        system("cls");

        Student *rb = select_RB(base, record_book, num_of_students);
        if (rb == NULL) {
            printf("Такого студента нет\n");
            system("pause");
            break;
        }
        print_student(rb);
        system("pause");
        break;

    //ПО ФИО
    case 2:
        printf("Введите ФИО: ");
        char first_name[100];
        char second_name[100];
        char patronym[100];

        scanf("%s%s%s", second_name, first_name, patronym);
        system("cls");

        select_FIO(base, num_of_students, first_name, second_name, patronym);
        system("pause");
        break;

    //ПО СРЕДНЕЙ ОЦЕНКЕ
    case 3:
        printf("Введите среднюю оценку: ");
        scanf("%lf", &average_mark);
        system("cls");

        select_average_mark(base, num_of_students, average_mark);
        system("pause");
        break;

    //БОЛЬШЕ ИЛИ РАВНА СРЕДНЕЙ ОЦЕНКЕ
    case 4:
        printf("Введите среднюю оценку: ");
        scanf("%lf", &average_mark);
        system("cls");
        select_average_mark_more(base, num_of_students, average_mark);
        system("pause");
        break;

    //МЕНЬШЕ ИЛИ РАВНА СРЕДНЕЙ ОЦЕНКЕ
    case 5:
        printf("Введите среднюю оценку: ");
        scanf("%lf", &average_mark);
        system("cls");
        select_average_mark_less(base, num_of_students, average_mark);
        system("pause");
        break;
    default:
        select_choice();
        break;
    }
}

int main(int argc, char *argv[]) {

    //ДЛЯ РУСИФИКАЦИИ
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char default_way[] = "Students.txt";

    if (argc > 1) {
        base = read_student_base(&num_of_students, argv[1]);
    }
    else {
        base = read_student_base(&num_of_students, default_way);
    }

    int user_choise, record_book, exit = 1, i;          //record_book - зачётка

    //ГЛАВНОЕ МЕНЮ
    while (exit) {

        system("cls");
        printf("Выберите действие: \n\n");
        printf("1 - Добавить студента\n");
        printf("2 - Удалить студента\n");
        printf("3 - Поиск студента\n");
        printf("4 - Показать всех студентов\n");
        printf("5 - Сохранить в базу\n\n");
        printf("0 - Выход\n\n");

        scanf("%d", &user_choise);

        system("cls");

        switch (user_choise) {
        //ДОБАВЛЕНИЕ СТУДЕНТА
        case 1:
            add_student(&base, &num_of_students);
            system("pause");
            break;

        //УДАЛЕНИЕ СТУДЕНТА
        case 2:
            printf("Введите номер зачётки: ");
            scanf("%d", &record_book);
            system("cls");
            delete_student(&base, &num_of_students, record_book);
            system("pause");
            break;

        //ПОИСК СТУДЕНТА
        case 3:
            select_choice();
            break;

        //ВЫВОД ВСЕХ СТУДЕНТОВ
        case 4:
            for (i = 0; i < num_of_students; i++) {
                print_student(base + i);
            }
            if (num_of_students == 0) {
                printf("Студентов нет\n");
            }
            system("pause");
            break;

        //СОХРАНЕНИЕ В БАЗУ
        case 5:
            if (argc > 1) {
                write_student_in_base(base, num_of_students, argv[1]);
            } else {
                write_student_in_base(base, num_of_students, default_way);
            }
            break;

        //ВЫХОД
        case 0:
            printf("\n\nДо свидания!\n\n");
            system("pause");
            exit = 0;
            break;
        default:
            break;
        }
    }

    if (argc > 1) {
        write_student_in_base(base, num_of_students, argv[1]);
    }
    else {
        write_student_in_base(base, num_of_students, default_way);
    }

    //ОСВОБОЖДЕНИЕ ПАМЯТИ
    for (i = 0; i < num_of_students; i++) {
        free(base[i].first_name);
        free(base[i].second_name);
        free(base[i].patronym);
    }

    free(base);
    return 0;
}
