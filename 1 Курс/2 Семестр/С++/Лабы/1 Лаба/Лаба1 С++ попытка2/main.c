#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myFunctions.h"
#include <windows.h>

/*struct data {
    int rb;
    char second_name[100];
    char first_name[100];
    char patronym[100];
    char sex[10];
    int ball_1;
    int ball_2;
    int ball_3;
    double total_score;
    int day;
    int month;
    int year;
    int tel_num;
};*/

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int exit = 1;
    while (exit)
    {
        system("cls");
        char func[1] = "";
        int res;

        printf("Выберите действие:\n\n");
        printf(">>Добавить участника - 1\n");
        printf(">>Удалить участника - 2\n");
        printf(">>Вывод участников, занявших 1-3 места - 3\n");
        printf(">>Вывести всех в виде таблицы- 4\n");
        printf(">>Вывод информации об участниках - 5\n");
        printf(">>Количество участников мужского пола, родившихся в 2003г. - 6\n");
        printf(">>Средний возраст участников олимпиады - 7\n");
        printf(">>Выход - 0\n\n");
        printf(">>Ваш выбор: ");
        scanf("%s", &func[0]);
        switch(func[0])
        {
            //Добавление студента
            case '1':
                system("cls");
                res = add_student();
                if (res == 0)
                {
                    printf("Учащийся успешно добавлен\n\n");
                }
                else if (res == 1)
                {
                    printf("Такой учащийся уже есть\n\n");
                }
                else
                {
                    printf("Ошибка открытия или создания файла\n\n");
                }
                system("pause");
                break;
            //Удаление студента
            case '2':
                system("cls");
                res = delete_student();
                if (res == 0)
                {
                    printf("Учащийся успешно удален\n\n");
                }
                else if (res == 1)
                {
                    printf("Учащийся не найден\n\n");
                }
                else
                {
                    printf("Ошибка открытия файла\n\n");
                }
                system("pause");
                break;
            //Вывод участников,занявших 1-3 места
            case '3':
                system("cls");
                search_students();
                system("pause");
                break;
            //Вывод всех участников в виде таблицы
            case '4':
                system("cls");
                print_table();
                /*if (res == 0)
                {
                    printf("Участников нет");
                }
                else
                {
                    printf("Участники:\n");
                }*/
                system("pause");
                break;
            //Вывод информации об участниках
            case '5':
                system("cls");
                print_students();
                /*if (res == 0)
                {
                    printf("Участников нет");
                }
                else
                {
                    printf("Участники:\n");
                }*/
                system("pause");
                break;
            //Количество участников мужского пола, родившихся в 2003г.
            case '6':
                printf("Количество участников мужского пола, родившихся в 2003г.: %d\n\n", male_func());
                system("pause");
                break;
            //Средний возраст участников олимпиады
            case '7':
                printf("\nСредний возраст участников олимпиады: %0.2lf\n\n", average_age());
                system("pause");
                break;
            case '0':
                exit = 0;
                break;

            default: {
                printf("Неизвестная функция\n");
            }
        }
    }
    return 0;
}
//FILE *fp = fopen("spisok.txt", "");
