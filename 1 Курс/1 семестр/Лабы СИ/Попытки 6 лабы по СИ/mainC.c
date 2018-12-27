#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char *f;
    char *i;
    char *o;

}data;

typedef struct{
    int math, OS, ISIT, KSE;
}subjects;

typedef struct{
    data FIO;
    int id;
    subjects sub;
}Student;

Student *students;

int checkID(int i, int id){
    int k;

    for (k = 0; k < i; k++){
        if ((students + k)-> id == id){
                return k;
            }
    }
    printf("Student not found\n");
    return -1;
}

int addStudent(int i){
    students = (Student*)realloc(students, (i + 1)*sizeof(Student));

    char buffer[128];
    int id, math, OS, ISIT, KSE;
    printf("Enter full name: ");

    scanf("%s", &buffer);
    (students + i)->FIO.f = (char*)malloc(strlen(buffer) +1);
    strcpy((students + i)->FIO.f, buffer);

    scanf("%s", &buffer);
    (students + i)->FIO.i = (char*)malloc(strlen(buffer) +1);
    strcpy((students + i)->FIO.i, buffer);

    scanf("%s", &buffer);
    (students + i)->FIO.o = (char*)malloc(strlen(buffer) +1);
    strcpy((students + i)->FIO.o, buffer);

    printf("id: ");
    scanf("%d", &id);

    if (checkID(i, id) != -1){
        printf("Student found\n");
        return i;
    }

    printf("math: ");
    scanf("%d", &math);

    printf("OS: ");
    scanf("%d", &OS);

    printf("ISIT: ");
    scanf("%d", &ISIT);

    printf("KSE: ");
    scanf("%d", &KSE);

    (students + i)->id = id;
    (students + i)->sub.math = math;
    (students + i)->sub.OS = OS;
    (students + i)->sub.ISIT = ISIT;
    (students + i)->sub.KSE = KSE;

    i++;
    writeStudents(students, i);
    return i;
}


/*void writeStudents(int k, char *name){
    FILE *g;
    int i;

    for(i = 0; i < k; i++){
        if ((g = fopen(name, "a")) == NULL)
        {
            printf("Error");
            exit (-1);

        } else{
            fprintf(g, "Name: %s ", (students + i)->FIO.f);
            fprintf(g, " %s ", (students + i)->FIO.i);
            fprintf(g, " %s \n", (students + i)->FIO.o);
            fprintf(g, "ID: %d\n",(students + i)->id );
            fprintf(g, "Math: %d ", (students + i)->sub.math );
            fprintf(g, "OS: %d ", (students + i)->sub.OS );
            fprintf(g, "ISIT: %d ", (students + i)->sub.ISIT );
            fprintf(g, "KSE: %d ", (students + i)->sub.KSE );

            fprintf(g, "%s\n", "");
            fprintf(g, "%s\n", "");

            i++;
            fclose(g);
        }
    }
}*/
int deleteStudent (int i){
    int id, k = 0;
    printf ("Enter id:");
    scanf("%d", &id);

    if (k = checkID(i, id)!= -1){
        for (k = checkID(i, id); k < i - 1; k++){
            *(students + k) = *(students + k + 1);
        }
        i--;
        free((students + i));
        printf("Student deleted\n");
    }

    return i;
}


void selectStudent (int i){
    double score;
    int k;

    printf("Write student's score:\n");
    scanf("%lf", &score);

    for (k = 0; k < i; k++){
        if ((double)((students + k)->sub.math + (students + k)->sub.OS +
            (students + k)->sub.KSE + (students + k)->sub.ISIT)/4 > score){
            printf("Students ID and F : %d %s\n", (students + k)->id, (students + k)->FIO.f);
        }
    }
}
void writeStudents( Student *students, const int k) {

    FILE *g;
    if ((g = fopen("test.txt", "w")) == NULL) {
        printf("Can't write file");
        return;
    }

    int i;
    for (i = 0; i < k; i++) {
        fprintf(g, "Name: %s ", (students + i)->FIO.f);
            fprintf(g, " %s ", (students + i)->FIO.i);
            fprintf(g, " %s \n", (students + i)->FIO.o);
            fprintf(g, "ID: %d\n",(students + i)->id);
            fprintf(g, "Math: %d ", (students + i)->sub.math );
            fprintf(g, "OS: %d ", (students + i)->sub.OS );
            fprintf(g, "ISIT: %d ", (students + i)->sub.ISIT );
            fprintf(g, "KSE: %d \n", (students + i)->sub.KSE );
    }

    fclose(g);
}
int readStudents(char *name) {
    FILE *f;
    char name1[100];
    char name2[100];
    char name3[100];
    char voidStr[50];
    int i=0;

    if ((f = fopen(name, "r")) == NULL) {
        printf("Can't open file");
        exit(-1);
    } else{


     while(!feof(f))
     {
        students = (Student*)realloc(students, (i + 1)*sizeof(Student));

        fscanf(f, "%s %s %s %s", voidStr, name1, name2, name3);

        (students + i)->FIO.f = (char*)malloc(strlen(name1)+1);
        (students + i)->FIO.i = (char*)malloc(strlen(name2)+1);
        (students + i)->FIO.o = (char*)malloc(strlen(name3)+1);

        strcpy((students + i)->FIO.f, name1);
        strcpy((students + i)->FIO.i, name2);
        strcpy((students + i)->FIO.o, name3);

        fscanf(f, "%s %d", voidStr, &((students + i) -> id));
        fscanf(f, "%s %d", voidStr, &((students + i) -> sub.math));
        fscanf(f, "%s %d", voidStr, &((students + i) -> sub.OS));
        fscanf(f, "%s %d", voidStr, &((students + i) -> sub.ISIT));
        fscanf(f, "%s %d", voidStr, &((students + i) -> sub.KSE));

        i++;
    }
}

    fclose(f);
    return i;
}
int main(int argc, char *argv[])
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
                i = readStudents(name);
                i--;
                i = addStudent(i);
                break;
            case 2:
                i = deleteStudent(i);
                writeStudents(students, i);
                break;
            case 3:
                selectStudent(i);
                break;
            case 4:
                writeStudents(students, i);
                int k;
                for (k = 0; k < i; k++) {
                    free((students + k) -> FIO.f);
                    free((students + k) -> FIO.i);
                    free((students + k) -> FIO.o);
                }
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
