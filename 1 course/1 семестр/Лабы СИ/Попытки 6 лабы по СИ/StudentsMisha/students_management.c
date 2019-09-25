#include <stdio.h>
#include <stdlib.h>
#include "students_management.h"
#include "my_string.h"

Student *read_student_base(int *size_base, char *path)
{
    FILE *f;
    printf("%s\n", path);
    if ((f = fopen(path, "a+")) == NULL) {
        printf("Can't create or open file\n");
        system("pause");
        exit(-1);
    }

    fscanf(f, "%d", size_base);

    Student *base = (Student*)malloc(*size_base * sizeof(Student));

    char f_name[100];
    char s_name[100];
    char t_name[100];
    int i;
    for (i = 0; i < *size_base; i++)
    {
        fscanf(f, "%s", s_name);
        fscanf(f, "%s", f_name);
        fscanf(f, "%s", t_name);

        (base + i)->second_name = (char*)malloc((size_string(s_name) + 1) * sizeof(char));
        copy_string((base + i)->second_name, s_name);
        (base + i)->first_name = (char*)malloc((size_string(f_name) + 1) * sizeof(char));
        copy_string((base + i)->first_name, f_name);
        (base + i)->third_name = (char*)malloc((size_string(t_name) + 1) * sizeof(char));
        copy_string((base + i)->third_name, t_name);

        fscanf(f, "%u", &((base + i)->id));
        fscanf(f, "%f", &((base + i)->average_mark));
        fscanf(f, "%u", &((base + i)->math));
        fscanf(f, "%u", &((base + i)->russian));
        fscanf(f, "%u", &((base + i)->english));
        fscanf(f, "%u", &((base + i)->programming));
        fscanf(f, "%u", &((base + i)->number_of_visits));
    }

    fclose(f);

    return base;
}

void write_student_base(Student *base, int size_base, char *path)
{
    FILE *f;

    if ((f = fopen(path, "w")) == NULL) {
        printf("Can't open file\n");
        system("pause");
        exit(-1);
    }

    fprintf(f, "%d\n", size_base);

    int i;
    for (i = 0; i < size_base; i++)
    {
        fprintf(f, "%s ", (base + i)->second_name);
        fprintf(f, "%s ", (base + i)->first_name);
        fprintf(f, "%s\n", (base + i)->third_name);
        fprintf(f, "%u\n", (base + i)->id);
        fprintf(f, "%f\n", (base + i)->average_mark);
        fprintf(f, "%u\n", (base + i)->math);
        fprintf(f, "%u\n", (base + i)->russian);
        fprintf(f, "%u\n", (base + i)->english);
        fprintf(f, "%u\n", (base + i)->programming);
        fprintf(f, "%u\n", (base + i)->number_of_visits);
    }

    fclose(f);
}

Student *select_ID(Student *base, int id, int size_base)
{
    int i;
    for (i = 0; i < size_base; i++)
    {
        if ((base + i)->id == id) {
            return (base + i);
        }
    }

    return NULL;
}

void select_FIO(Student *base, int size_base, char *f_n, char *s_n, char *t_n)
{
    int i, f1 = -1, f2 = -1, f3 = -1, founded = 0;
    for (i = 0; i < size_base; i++)
    {
        f1 = cmp_string((base + i)->first_name, f_n);
        f2 = cmp_string((base + i)->second_name, s_n);
        f3 = cmp_string((base + i)->third_name, t_n);
        if (!f1 && !f2 && !f3) {
            print_student((base + i));
            founded = 1;
        }
    }

    if (founded == 0) {
        printf("\nThe student is not found\n");
    }
}

void select_average(Student *base, int size_base, float av_mark)
{
    int i, founded = 0;
    for (i = 0; i < size_base; i++)
    {
        if ((base + i)->average_mark == av_mark) {
            print_student(base + i);
            founded = 1;
        }
    }
    if (founded == 0) {
        printf("\nThe student is not found\n");
    }
}

void select_average_more(Student *base, int size_base, float av_mark)
{
    int i, founded = 0;
    for (i = 0; i < size_base; i++)
    {
        if ((base + i)->average_mark >= av_mark) {
            print_student(base + i);
            founded = 1;
        }
    }
    if (founded == 0) {
        printf("\nThe student is not found\n");
    }
}

void select_average_less(Student *base, int size_base, float av_mark)
{
    int i, founded = 0;
    for (i = 0; i < size_base; i++)
    {
        if ((base + i)->average_mark <= av_mark) {
            print_student(base + i);
            founded = 1;
        }
    }
    if (founded == 0) {
        printf("\nThe student is not found\n");
    }
}

void add_student(Student **base, int *size_base)
{
    char f_name[100];
    char s_name[100];
    char t_name[100];

    *base = (Student*)realloc(*base, (*size_base + 1) * sizeof(Student));

    printf("\nEnter full name: ");
    scanf("%s", s_name);
    scanf("%s", f_name);
    scanf("%s", t_name);

    (*base + *size_base)->second_name = (char*)malloc((size_string(s_name) + 1) * sizeof(char));
    copy_string((*base + *size_base)->second_name, s_name);
    (*base + *size_base)->first_name = (char*)malloc((size_string(f_name) + 1) * sizeof(char));
    copy_string((*base + *size_base)->first_name, f_name);
    (*base + *size_base)->third_name = (char*)malloc((size_string(t_name) + 1) * sizeof(char));
    copy_string((*base + *size_base)->third_name, t_name);

    printf("Enter ID: ");
    scanf("%u", &((*base + *size_base)->id));
    if (select_ID(*base, (*base + *size_base)->id, *size_base) != NULL) {
        printf("This ID already exists\n");
        return;
    }

    printf("Enter average mark: ");
    scanf("%f", &((*base + *size_base)->average_mark));

    printf("Enter Math score: ");
    scanf("%u", &((*base + *size_base)->math));

    printf("Enter Russian score: ");
    scanf("%u", &((*base + *size_base)->russian));

    printf("Enter English score: ");
    scanf("%u", &((*base + *size_base)->english));

    printf("Enter Programming score: ");
    scanf("%u", &((*base + *size_base)->programming));

    printf("Enter the number of visits: ");
    scanf("%u", &((*base + *size_base)->number_of_visits));

    printf("\nAdded successful\n");

    *size_base += 1;
}

void delete_student(Student **base, int *size_base, int id)
{
    int index_student = -1;
    int i;
    for (i = 0; i < *size_base; i++)
    {
        if ((*base + i)->id == id) {
            index_student = i;
            break;
        }
    }

    if (index_student == -1) {
        printf("\nThe student is not found\n");
        return;
    }

    free((*base + index_student)->second_name);
    free((*base + index_student)->first_name);
    free((*base + index_student)->third_name);

    *size_base -= 1;

    for (i = index_student; i < *size_base; i++)
    {
        *(*base + i) = *(*base + i + 1);
    }

    *base = (Student*)realloc(*base, *size_base * sizeof(Student));

    printf("Deleted successful\n");
}

void print_student(Student *man)
{
    printf("\nFull name: %s %s %s\n", man->second_name, man->first_name, man->third_name);
    printf("ID: %u\n", man->id);
    printf("Average mark: %.1f\n", man->average_mark);
    printf("Math: %u\n", man ->math);
    printf("Russian: %u\n", man->russian);
    printf("English: %u\n", man->english);
    printf("Programming: %u\n", man->programming);
    printf("The number of visits: %u\n\n", man->number_of_visits);
}
