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

///////////ДОБАВЛЕНИЕ СТУДЕНТА///////

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
    printf("Заполните информацию: \nНомер зачётки: ");
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
    printf("Фамилия: ");
    scanf("%s", &student.sec_name);
    printf("Имя: ");
    scanf("%s", &student.name);
    printf("Отчество: ");
    scanf("%s", &student.patronym);

    /*int i;
    for (i = 0; i < 4;i++) {
        printf("\nНапиши предмет: ");
        fflush()
    }*/

    printf("Предмет 1: ");
    scanf("%s", &student.discp[0]);
    printf("Оценка по предмету: ");
    scanf("%d", &student.mark[0]);
    printf("Предмет 2: ");
    scanf("%s", &student.discp[1]);
    printf("Оценка по предмету: ");
    scanf("%d", &student.mark[1]);
    printf("Предмет 3: ");
    scanf("%s", &student.discp[2]);
    printf("Оценка по предмету: ");
    scanf("%d", &student.mark[2]);
    printf("Предмет 4: ");
    scanf("%s", &student.discp[3]);
    printf("Оценка по предмету: ");
    scanf("%d", &student.mark[3]);

    student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
     fprintf(fp, " %d %s %s %s %s %s %s %s \n%d %d %d %d %f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
    fclose(fp);

    printf("\nЖмякай уже что-нить!...");
    getch();
    return 0;
}

//////////УДАЛЕНИЕ СТУДЕНТА//////////

int del_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, result = 1;
    printf("Введите номер зачётки, по которому будет удален студент: ");
    scanf("%d", &n);
    int i = 0, count = 0;
    struct data *studentent;
    struct data student;

    studentent = (struct data*)malloc(count * sizeof(struct data));

    FILE *fp;
    fp = fopen("studentS.txt", "rb");
    int num = -1;
    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        if (num == student.number) {
            break;
        }
        count++;
    }
    fclose(fp);
    fp = fopen("studentS.txt", "rb");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }
    studentent = (struct data*)realloc(studentent, count * sizeof(struct data));
    for (i = 0; i < count; i++) {
        scanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &studentent[i].discp[2], &studentent[i].discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        studentent[i] = student;
    }
    fclose(fp);
    fp = fopen("studentS.txt", "wb");
    for (i = 0; i < count; i++)
    {
        if (studentent[i].number != n) {
        studentent[i].Smark = (studentent[i].mark[0] + studentent[i].mark[1] + studentent[i].mark[2] + studentent[i].mark[3]) / 4.0;
        fprintf(fp, "%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f ", studentent[i].number, studentent[i].sec_name, studentent[i].name, studentent[i].patronym, studentent[i].discp[0], studentent[i].discp[1],  studentent[i].discp[2], studentent[i].discp[3], studentent[i].mark[0], studentent[i].mark[1], studentent[i].mark[2], studentent[i].mark[3], studentent[i].Smark);
        }
        else {
            result = 0;
        }
    }
    fclose(fp);
    free(studentent);

    printf("\nЖмякай уже что-нить!...");
    getch();
    return result;
}

/////////ВЫБОРКА ПО НОМЕРУ ЗАЧЕТКИ///
/////////Record_book - зачетка///////

void record_book() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    printf("Введите номер зачетки джедая юного: ");
    struct data student;
    int num_of_rb, result = 1;
    scanf("%d", &num_of_rb);
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        printf("Ошибка создания или открытия файла");
    }

    int num = -1;
    while(num != student.number) {
        num = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s\n%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);

        if (num_of_rb == student.number) {
            student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;
            result = 0;
            printf("Джедай юный найден: \n\n");
            printf("%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
        }
    }
    fclose(fp);

    if (result == 1) {
        printf("Такого джедая у нас в сопротивлении нет!Посмотрите у империи!\n\n");
    }

    printf("\nЖмякай уже что-нить!...");
    getch();

}

/////////ВЫБОРКА ПО ФИО//////////////

void select_fio_of_student() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

    printf("Введите имя джедая юного: ");
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
            printf("\nДжедай юный найден:\n");
            printf("%d %s %s %s %s %s %s %s \n%d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
        }
    }
    fclose(fp);

    if (result == 1) {
        printf("\nТакого джедая у нас в сопротивлении нет!Посмотрите у империи!\n");
    }
    printf("\nЖмякай уже что-нить!...");
    getch();
}


/////////ВЫБОРКА ПО ОЦЕНКЕ///////////

void mark_of_student(int counter ) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");

   // printf("Введите оценку джедая юного: ");
    struct data student;
    int  select, i , flag = 1;
    double cur_mark;
    //float p;
    //scanf("%f", &p);
    FILE *fp = fopen("studentS.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 2;
    }

    printf("1 - <=;\n2 - >=;\n\nНапишите команду: ");
    scanf("%d", &select);

    printf("\nНапишите оценку: ");
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
            for(i = 0; i < counter; i++) {
                    /*printf("\nasd\n");
                    system("pause");*/
                    if (x <= cur_mark && x >= 0 && x <= 5) {
                        flag = 0;
                        printf("\n\nКрасава!Такой джедай юный нашёлся:\n\n");
                        //printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
                        printf("Зачётка: %d\n", student.number);
                        printf("Фамилия: %s\n", student.sec_name);
                        printf("Имя: %s\n", student.name);
                        printf("Отчество: %s\n", student.patronym);
                        printf("Средняя оценка: %.2lf\n", student.Smark);
                        system("pause");
                        num++;
                        student.number = num;
                        num--;

                    }
                    else {
                        printf("\n\nТакого джедая у нас в сопротивлении нет!Посмотрите у империи!\n");
                        num = 5;
                        break;

                    }
                }
            }

        else if (select == 2) {
            for (i = 0; i < counter; i++) {
                    if (x >= cur_mark && x >= 0 && x <= 5) {
                        flag = 0;
                        printf("\n\nКрасава!Такой джедай юный нашёлся:\n\n");
                        //printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
                        printf("Зачётка: %d\n", student.number);
                        printf("Фамилия: %s\n", student.sec_name);
                        printf("Имя: %s\n", student.name);
                        printf("Отчество: %s\n", student.patronym);
                        printf("Средняя оценка: %.2lf\n", student.Smark);
                        system("pause");
                        num++;
                        student.number = num;
                        num--;

                    }
                    else {
                        printf("\n\nТакого джедая у нас в сопротивлении нет!Посмотрите у империи!\n");
                        num = 5;
                        break;
                    }
                }
        }
    }
        if (flag == 1) {
            system("pause");
            printf("\n\nТакого джедая у нас в сопротивлении нет!Посмотрите у империи!\n");
        }




    /*int poi = -1;
    while(poi != student.number) {
        poi = student.number;
        fscanf(fp, "%d%s%s%s%s%s%s%s%d%d%d%d%f", &student.number, &student.sec_name, &student.name, &student.patronym, &student.discp[0], &student.discp[1], &student.discp[2], &student.discp[3], &student.mark[0], &student.mark[1], &student.mark[2], &student.mark[3], &student.Smark);
        student.Smark = (student.mark[0] + student.mark[1] + student.mark[2] + student.mark[3]) / 4.0;

        if (p == student.Smark) {
            result = 0;
            printf("%d %s %s %s %s %s %s %s %d %d %d %d %.2f \n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.discp[1],  student.discp[2], student.discp[3], student.mark[0], student.mark[1], student.mark[2], student.mark[3], student.Smark);
        }
    }
    fclose(fp);

    if (flag == 1) {
        printf("\nТакого джедая у нас в сопротивлении нет!Посмотрите у империи!\n");
    }*/

    printf("\nЖмякай уже что-нить!...");
    getch();

}

////////ВЫВОД ВСЕХ СТУДЕНТОВ/////////


int all_students() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Все жертвы: \n");
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
        printf("%d %s %s %s\nПредметы   Оценки \n%s -       %d\n%s -      %d\n%s -     %d\n%s -     %d\nСредняя оценка:  %.2f \n\n\n", student.number, student.sec_name, student.name, student.patronym, student.discp[0], student.mark[0], student.discp[1], student.mark[1],  student.discp[2], student.mark[2], student.discp[3], student.mark[3], student.Smark);
    }
    fclose(fp);

    printf("\nЖмякай уже что-нить!...");
    getch();
    return 0;
}

