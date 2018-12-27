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

typedef struct{
    name FIO;
    int zachyotka;
    predmeti pred;
}Student;

Student *students;

int check_zachyotka(int i, int num) {

    int g;

    for (g = 0; g < i; g++) {
        if(students[g].zachyotka == num) {
            return g;
        }
    }
    printf("Student doesn't exist!\n");
    return -1;
}

int add_student(int i) {

    students = (Student*) realloc(students, (i + 1)*sizeof(Student));

    char buf[200];
    int zachyotka, math, rus, eng, fizra;
    printf("Vvedite FIO:");

    scanf("%s", &buf);
    students[i].FIO.name = (char*)malloc(strlen(buf) + 1);
    strcpy(students[i].FIO.name, buf);

    getch();
    printf("Zachyotka: ");
    scanf("%d", &zachyotka);

    printf("Math: ");
    scanf("%d", &math);

    printf("Rus: ");
    scanf("%d", &rus);

    printf("Eng: ");
    scanf("%d", &eng);

    printf("Fizra: ");
    scanf("%d", &fizra);

    students[i].zachyotka = zachyotka;
    students[i].pred.math = math;
    students[i].pred.eng= eng;
    students[i].pred.rus = rus;
    students[i].pred.fizra = fizra;

    i++;
    write_students(students, i);
    return;
}

int delete_student (int i) {

    int zachyotka, k = 0;

    printf ("Enter zachyotka:");
    scanf("%d", &zachyotka);

    if (k = check_zachyotka(i, zachyotka)!= -1){
        for (k = check_zachyotka(i, zachyotka); k < i - 1; k++){
            students[k] = students [k + 1];
        }
        i--;

        printf("Student deleted\n");
    }

    return i;

}

void select_student (int i){

    double mark;
    int k;

    printf("Write student's mark:\n");
    scanf("%lf", &mark);

    for (k = 0; k < i; k++){
        if ((double)(students[k].pred.math + students[k].pred.rus +
            students[k].pred.eng + students[k].pred.fizra)/4 > mark){
            printf("Students zachyotka and FIO : %d %s\n", students[k].zachyotka, students[k].FIO.name);
        }
    }
}

void write_students(Student *students, const int k) {

    FILE *g;
    if ((g = fopen("test.txt", "w")) == NULL) {
        printf("Can't write file");
        return;
    }

    int i;
    for (i = 0; i < k; i++) {
            fprintf(g, "FIO: %s ", students[i].FIO.name);
            fprintf(g, "zachyotka: %d\n",students[i].zachyotka);
            fprintf(g, "Math: %d ", students[i].pred.math );
            fprintf(g, "Rus: %d ", students[i].pred.rus);
            fprintf(g, "Eng: %d ", students[i].pred.eng );
            fprintf(g, "Fizra: %d \n", students[i].pred.fizra );
    }

    fclose(g);
}

int read_students(char *name) {
    FILE *f;

    char name1[100];
    char voidStr[50];

    int i=0;

    if ((f = fopen(name, "r")) == NULL) {
        printf("Can't open file");
        exit(-1);
    }
    else{
         while(!feof(f))
         {
            students = (Student*)realloc(students, (i + 1)*sizeof(Student));

            fscanf(f, "%s %s %s %s", voidStr, name1);

            students[i].FIO.name = (char*)malloc(strlen(name1)+1);

            strcpy(students[i].FIO.name, name1);


            fscanf(f, "%s %d", voidStr, &(students[i].zachyotka));
            fscanf(f, "%s %d", voidStr, &(students[i].pred.math));
            fscanf(f, "%s %d", voidStr, &(students[i].pred.rus));
            fscanf(f, "%s %d", voidStr, &(students[i].pred.eng));
            fscanf(f, "%s %d", voidStr, &(students[i].pred.fizra));

            i++;
        }
    }

    fclose(f);
    return i;
}


