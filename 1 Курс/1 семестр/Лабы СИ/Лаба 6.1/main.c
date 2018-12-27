#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud_func.h"
#include <windows.h>


int num_of_students;
Student *base;

//ÏÎÈÑÊ
void select_choice() {

    int user_choice, record_book;
    double average_mark;
    system("cls");

    printf("Ïîèñê ñòóäåíòà:\n\n");
    printf("1 - Ïî íîìåğó çà÷¸òêè\n");
    printf("2 - Ïî ÔÈÎ\n");
    printf("3 - Ïî ñğåäíåé îöåíêå\n");
    printf("4 - Áîëüøå èëè ğàâíà ñğåäíåé îöåíêå\n");
    printf("5 - Ìåíüøå èëè ğàâíà ñğåäíåé îöåíêå\n\n");

    scanf("%d", &user_choice);

    system("cls");

    switch (user_choice) {

    //ÏÎ ÇÀ×¨ÒÊÅ
    case 1:
        printf("Ââåäèòå íîìåğ çà÷¸òêè: ");
        scanf("%d", &record_book);
        system("cls");

        Student *rb = select_RB(base, record_book, num_of_students);
        if (rb == NULL) {
            printf("Òàêîãî ñòóäåíòà íåò\n");
            system("pause");
            break;
        }
        print_student(rb);
        system("pause");
        break;

    //ÏÎ ÔÈÎ
    case 2:
        printf("Ââåäèòå ÔÈÎ: ");
        char first_name[100];
        char second_name[100];
        char patronym[100];

        scanf("%s%s%s", second_name, first_name, patronym);
        system("cls");

        select_FIO(base, num_of_students, first_name, second_name, patronym);
        system("pause");
        break;

    //ÏÎ ÑĞÅÄÍÅÉ ÎÖÅÍÊÅ
    case 3:
        printf("Ââåäèòå ñğåäíşş îöåíêó: ");
        scanf("%lf", &average_mark);
        system("cls");

        select_average_mark(base, num_of_students, average_mark);
        system("pause");
        break;

    //ÁÎËÜØÅ ÈËÈ ĞÀÂÍÀ ÑĞÅÄÍÅÉ ÎÖÅÍÊÅ
    case 4:
        printf("Ââåäèòå ñğåäíşş îöåíêó: ");
        scanf("%lf", &average_mark);
        system("cls");
        select_average_mark_more(base, num_of_students, average_mark);
        system("pause");
        break;

    //ÌÅÍÜØÅ ÈËÈ ĞÀÂÍÀ ÑĞÅÄÍÅÉ ÎÖÅÍÊÅ
    case 5:
        printf("Ââåäèòå ñğåäíşş îöåíêó: ");
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

    //ÄËß ĞÓÑÈÔÈÊÀÖÈÈ
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    char default_way[] = "Students.txt";

    if (argc > 1) {
        base = read_student_base(&num_of_students, argv[1]);
    }
    else {
        base = read_student_base(&num_of_students, default_way);
    }

    int user_choise, record_book, exit = 1, i;          //record_book - çà÷¸òêà

    //ÃËÀÂÍÎÅ ÌÅÍŞ
    while (exit) {

        system("cls");
        printf("Âûáåğèòå äåéñòâèå: \n\n");
        printf("1 - Äîáàâèòü ñòóäåíòà\n");
        printf("2 - Óäàëèòü ñòóäåíòà\n");
        printf("3 - Ïîèñê ñòóäåíòà\n");
        printf("4 - Ñîõğàíèòü â áàçó\n\n");
        printf("5 - Ïîêàçàòü âñåõ ñòóäåíòîâ\n\n");
        printf("0 - Âûõîä\n\n");

        printf("Âàø âûáîğ: ");
        scanf("%d", &user_choise);

        system("cls");

        switch (user_choise) {
        //ÄÎÁÀÂËÅÍÈÅ ÑÒÓÄÅÍÒÀ
        case 1:
            add_student(&base, &num_of_students);
            system("pause");
            break;

        //ÓÄÀËÅÍÈÅ ÑÒÓÄÅÍÒÀ
        case 2:
            printf("Ââåäèòå íîìåğ çà÷¸òêè: ");
            scanf("%d", &record_book);
            system("cls");
            delete_student(&base, &num_of_students, record_book);
            system("pause");
            break;

        //ÏÎÈÑÊ ÑÒÓÄÅÍÒÀ
        case 3:
            select_choice();
            break;

        //ÑÎÕĞÀÍÅÍÈÅ Â ÁÀÇÓ
        case 4:
            if (argc > 1) {
                write_student_in_base(base, num_of_students, argv[1]);
            } else {
                write_student_in_base(base, num_of_students, default_way);
            }
            break;

        //ÂÛÂÎÄ ÂÑÅÕ ÑÒÓÄÅÍÒÎÂ
        case 5:
            for (i = 0; i < num_of_students; i++) {
                print_student(base + i);
            }
            if (num_of_students == 0) {
                printf("Ñòóäåíòîâ íåò\n");
            }
            system("pause");
            break;

        //ÂÛÕÎÄ
        case 0:
            printf("\n\nÄî ñâèäàíèÿ!\n\n");
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

    //ÎÑÂÎÁÎÆÄÅÍÈÅ ÏÀÌßÒÈ
    for (i = 0; i < num_of_students; i++) {
        free(base[i].first_name);
        free(base[i].second_name);
        free(base[i].patronym);
    }

    free(base);
    return 0;
}
