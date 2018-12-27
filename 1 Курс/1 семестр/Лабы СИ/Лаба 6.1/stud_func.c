#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud_func.h"
#include <ctype.h>
#include <windows.h>
#include <locale.h>

//КОЛИЧЕСТВО СТУДЕНТОВ В БАЗЕ
Student *read_student_base(int *size_of_base, char *way) {


    FILE *q;
    printf("%s\n", way);

    if ((q = fopen(way, "a+")) == NULL) {
        printf("Невозможно создать или открыть файл\n");
        system("pause");
        exit(-1);
    }

    fscanf(q, "%d", size_of_base);

    Student *base = (Student*)malloc(*size_of_base * sizeof(Student));

    char cur_first_name[100];
    char cur_second_name[100];
    char cur_patronym[100];
    int i;

    for (i = 0; i < *size_of_base; i++) {

        fscanf(q, "%s", cur_second_name);
        fscanf(q, "%s", cur_first_name);
        fscanf(q, "%s", cur_patronym);

        base[i].second_name = (char*)malloc((strlen(cur_second_name) + 1) * sizeof(char));
        strcpy(base[i].second_name, cur_second_name);
        base[i].first_name = (char*)malloc((strlen(cur_first_name) + 1) * sizeof(char));
        strcpy(base[i].first_name, cur_first_name);
        base[i].patronym = (char*)malloc((strlen(cur_patronym) + 1) * sizeof(char));
        strcpy(base[i].patronym, cur_patronym);

        fscanf(q,"%d", &base[i].rb);
        fscanf(q,"%lf", &base[i].average_mark);
        fscanf(q,"%d", &base[i].math);
        fscanf(q,"%d", &base[i].rus_lang);
        fscanf(q,"%d", &base[i].eng_lang);
        fscanf(q,"%d", &base[i].history);
    }

    fclose(q);

    return base;
}

//
void write_student_in_base(Student *base, int size_of_base, char *way) {

    FILE *q;

    if ((q = fopen(way, "w")) == NULL) {
        printf("Невозможно открыть файл\n");
        system("pause");
        exit(-1);
    }

    fprintf(q, "%d\n", size_of_base);

    int i;

    for (i = 0; i < size_of_base; i++) {

        fprintf(q, "\nФИО: %s ", base[i].second_name);
        fprintf(q, "%s ", base[i].first_name);
        fprintf(q, "%s\n", base[i].patronym);
        fprintf(q, "Номер зачётки: %d\n", base[i].rb);
        fprintf(q, "Средняя оценка: %lf\n", base[i].average_mark);
        fprintf(q, "Математика: %d\n", base[i].math);
        fprintf(q, "Русский: %d\n", base[i].rus_lang);
        fprintf(q, "Английский: %d\n", base[i].eng_lang);
        fprintf(q, "История: %d\n", base[i].history);
    }

    fclose(q);
}

//ПОИСК ПО НОМЕРУ ЗАЧЁТКИ
Student *select_RB(Student *base, int rb, int size_of_base) {

    int i;

    for(i = 0; i < size_of_base; i++) {

        if(base[i].rb == rb) {
            return base + i;
        }
    }

    return NULL;
}

//ПОИСК ПО ФИО
void select_FIO(Student *base, int size_of_base, char *cur_first_name, char *cur_sec_name, char *cur_patr) {

    int i, c_f_n = -1, c_s_n = -1, c_p = -1, founded = 0;

    for (i = 0; i < size_of_base; i++) {

        c_f_n = strcmp(base[i].first_name, cur_first_name);
        c_s_n = strcmp(base[i].second_name, cur_sec_name);
        c_p = strcmp(base[i].patronym, cur_patr);

        if (!c_f_n && !c_s_n && !c_p) {
            print_student(base + i);
            founded = 1;
        }
    }

    if (founded == 0) {
        printf("Студент не найден\n");
    }
}

//ПОИСК ПО СРЕДНЕЙ ОЦЕНКЕ
void select_average_mark(Student *base, int size_of_base, double cur_average_mark) {

    int i, founded = 0;

    for (i = 0; i < size_of_base; i++) {

        if (base[i].average_mark == cur_average_mark) {
            print_student(base + i);
            founded = 1;
        }
    }

    if (founded == 0) {
        printf("Студент не найден\n");
    }
}

//ПОИСК ПО ОЦЕНКЕ, БОЛЬШЕЙ ИЛИ РАВНОЙ ВВЕДЁННОЙ
void select_average_mark_more(Student *base, int size_of_base, double cur_average_mark) {

    int i, founded = 0;

    for (i = 0; i < size_of_base; i++) {

        if (base[i].average_mark >= cur_average_mark) {
            print_student(base + i);
            founded = 1;
        }
    }

    if (founded == 0) {
        printf("Студент не найден\n");
    }
}

//ПОИСК ПО ОЦЕНКЕ, МЕНЬШЕЙ ИЛИ РАВНОЙ ВВЕДЁННОЙ
void select_average_mark_less(Student *base, int size_of_base, double cur_average_mark) {

    int i, founded = 0;

    for (i = 0; i < size_of_base; i++) {

        if (base[i].average_mark <= cur_average_mark) {
            print_student(base + i);
            founded = 1;
        }
    }

    if (founded == 0) {
        printf("Студент не найден\n");
    }
}

//ДОБАВЛЕНИЕ СТУДЕНТА
void add_student(Student **base, int *size_of_base) {

    char cur_first_name[100];
    char cur_second_name[100];
    char cur_patronym[100];

    *base = (Student*)realloc(*base, (*size_of_base + 1) * sizeof(Student));

    printf("\nВведите номер зачётки: ");
    scanf("%d", &((*base + *size_of_base)->rb));
    if(select_RB(*base, (*base + *size_of_base)->rb, *size_of_base) != NULL) {
        printf("Такой студент уже есть!\n");
        return;
    }

    printf("\nВведите ФИО: ");
    scanf("%s", cur_second_name);
    scanf("%s", cur_first_name);
    scanf("%s", cur_patronym);

    (*base + *size_of_base)->second_name = (char*)malloc((strlen(cur_second_name) + 1) * sizeof(char));
    strcpy((*base + *size_of_base)->second_name, cur_second_name);

    (*base + *size_of_base)->first_name = (char*)malloc((strlen(cur_first_name) + 1) * sizeof(char));
    strcpy((*base + *size_of_base)->first_name, cur_first_name);

    (*base + *size_of_base)->patronym = (char*)malloc((strlen(cur_patronym) + 1) * sizeof(char));
    strcpy((*base + *size_of_base)->patronym, cur_patronym);


	//int check = 0;
	int cur_mark;
	//while (!check){
		printf("\nВведите оценку по математике: ");
		scanf("%d", &cur_mark);

		//if (cur_mark[0] == '1' || cur_mark[0] == '2' || cur_mark[0] == '3' || cur_mark[0] == '4' || cur_mark[0] == '5' ) {
            //cur_mark = check_mark(cur_mark);
			((*base + *size_of_base)->math) = cur_mark;
			/*cur_mark[0] = '0';
			break;
		}
		else {
            printf("\nНеправильный введены данные:введено неправильное число или символ\n");
		}
	}*/

	//while (!check){
		printf("\nВведите оценку по русскому: ");
		scanf("%d", &cur_mark);

		//if (cur_mark[0] == '1' || cur_mark[0] == '2' || cur_mark[0] == '3' || cur_mark[0] == '4' || cur_mark[0] == '5' ) {
            //cur_mark = check_mark(cur_mark);
			((*base + *size_of_base)->rus_lang) = cur_mark;
			/*cur_mark = '0';
			break;
		}
		else {
            printf("\nНеправильный введены данные:введено неправильное число или символ\n");
		}
	}

	while (!check){*/
		printf("\nВведите оценку по английскому: ");
		scanf("%d", &cur_mark);

		//if (cur_mark[0] == '1' || cur_mark[0] == '2' || cur_mark[0] == '3' || cur_mark[0] == '4' || cur_mark[0] == '5' ) {
            //cur_mark = check_mark(cur_mark);
			((*base + *size_of_base)->eng_lang) = cur_mark;
			/*cur_mark[0] = '0';
			break;
		}
		else {
            printf("\nНеправильный введены данные:введено неправильное число или символ\n");
		}
	}

	while (!check){*/
		printf("\nВведите оценку по истории: ");
		scanf("%d", &cur_mark);

		//if (cur_mark[0] == '1' || cur_mark[0] == '2' || cur_mark[0] == '3' || cur_mark[0] == '4' || cur_mark[0] == '5' ) {
            //cur_mark = check_mark(cur_mark);
			((*base + *size_of_base)->history) = cur_mark;
			/*cur_mark[0] = '0';
			break;
		}
		else {
            printf("\nНеправильный введены данные:введено неправильное число или символ\n");
		}
	}
*/
    (*base + *size_of_base)->average_mark = ((double)(*base + *size_of_base)->math + (double)(*base + *size_of_base)->rus_lang + (double)(*base + *size_of_base)->eng_lang + (double)(*base + *size_of_base)->history) / 4;

    printf("\nСредняя оценка: %0.2lf",(*base + *size_of_base)->average_mark );

    printf("\n\nСтудент успешно добавлен\n\n");


    *size_of_base += 1;
}

//УДАЛЕНИЕ СТУДЕНТА
void delete_student(Student **base, int *size_of_base, int cur_rb) {

    int i, cur_rb_of_student = -1;

    for (i = 0; i < *size_of_base; i++) {

        if((*base + i)->rb == cur_rb) {
            cur_rb_of_student = i;
            break;
        }
    }

    if (cur_rb_of_student == -1) {
        printf("\nСтудента с таким номером зачётки нет\n");
        return;
    }

    free((*base + cur_rb_of_student)->second_name);
    free((*base + cur_rb_of_student)->first_name);
    free((*base + cur_rb_of_student)->patronym);

    *size_of_base -= 1;

    for (i = cur_rb_of_student; i < *size_of_base; i++) {

        *(*base + i) = *(*base + i + 1);
    }

    *base = (Student*)realloc(*base, *size_of_base * sizeof(Student));

    printf("Студент успешно удалён\n");
}

//ВЫВОД СТУДЕНТА
void print_student(Student *cur_student) {

    printf("\nФИО: %s %s %s\n", cur_student->second_name, cur_student->first_name, cur_student->patronym);
    printf("Номер зачётки: %u\n", cur_student->rb);
    printf("Средняя оценка: %.2f\n", cur_student->average_mark);
    printf("Математика: %d\n", cur_student->math);
    printf("Русский: %d\n", cur_student->rus_lang);
    printf("Английский: %d\n", cur_student->eng_lang);
    printf("История: %d\n", cur_student->history);
}
