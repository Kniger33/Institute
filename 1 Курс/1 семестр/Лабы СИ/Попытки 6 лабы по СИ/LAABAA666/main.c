#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "myF.h"


struct data {
    int number;
    char sec_name[15];
    char name[15];
    char patronym[15];          //Отчество
    char discp[4][15];
    int mark[4];
    double av_mark;
};

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int act = 1;
    while (act)
    {
        int com;
        int result;
        printf("Выберите действие: \n Добавить студента - 1\n Удалить студента - 2\n Выбор недостойного - 3\n Показать всех жертв - 4\n Закрыть программу - 0\n  ");
        scanf("%d", &com);
        switch(com)
        {
            //ДОБАВЛЕНИЕ СТУДЕНТА
            case 1: {
                system("cls");
                result = add_student();
                if (result == 0) {
                    printf("Юный падаван занесен в список!\n\n");
                } else if (result == 1) {
                    printf("Такой джедай юный уже есть\n\n");
                } else {
                    printf("Ошибка создания или открытия файла\n\n");
                }
                break;
            }
            //УДАЛЕНИЕ СТУДЕНТА
            case 2: {
                system("cls");
                result = del_student();
                if (result == 0) {
                    printf("Джедай юный найден:\n\n");
                } else if (result == 1) {
                    printf("Такого падавана у нас нет\n\n");
                } else {
                    printf("Ошибка открытия файла\n\n");
                }
                break;
            }
            //ВЫБОР СТУДЕНТА
            case 3: {
                system("cls");
                int com2;
                printf("Выбор недостойного: \n");
                printf("Выберите, как его найти:\n По номеру зачетки - 1\n По имени - 2\n По средней оценке - 3  ");
                scanf("%d", &com2);
                switch(com2)
                {
                    //ВЫБОР ПО НОМЕРУ ЗАЧЁТКИ
                    case 1: {

                        result = record_book();
                        if (result == 0) {
                            printf("Джедай юный найден:\n\n");
                        } else if (result == 1) {
                            printf("Такого падавана у нас нет\n\n");
                        } else {
                            printf("Ошибка создания или открытия файла\n\n");
                        }
                        break;
                    }
                    //ВЫБОР ПО ФИО
                    case 2: {
                        result = select_fio_of_student();
                        if (result == 0) {
                            printf("Джедай юный найден: \n\n");
                        } else if (result == 1) {
                            printf("Такого падавана у нас нет\n\n");
                        } else {
                            printf("Ошибка создания или открытия файла\n\n");
                        }
                        break;
                    }
                    //ВЫБОР ПО ОЦЕНКЕ
                    case 3: {
                        result = mark_of_student();
                        if (result == 0) {
                            printf("Джедай юный найден: \n\n");
                        } else if (result == 1) {
                            printf("Такого падавана у нас нет\n\n");
                        } else {
                            printf("Ошибка создания или открытия файла\n\n");
                        }
                        break;
                    }
                    default: {
                        printf("Хмм...Видимо,ты жомнул то-чего-нет. Попробуй-ка ещё разочек :)\n");
                    }
                }
                break;
            }

            //ВЫВОД ВСЕХ СТУДЕНТОВ
            case 4: {
                system("cls");
                all_students();
                break;
            }
            case 0: {
                printf("Да пребудет с тобой сила, мой юный падаван!\n");
                system("pause");
                act = 0;
                break;
            }
            default: {
                printf("\nХмм...Видимо,ты жомнул то-чего-нет. Попробуй-ка ещё разочек :)\n");
            }
        }
        system("cls");
    }
    return 0;
}

