#ifndef STUDENTS_MANAGEMENT_H_INCLUDED
#define STUDENTS_MANAGEMENT_H_INCLUDED
#define MAX_LEN 35

typedef struct {
    char *first_name;
    char *second_name;
    char *third_name;
    unsigned int id;
    float average_mark;
    unsigned int math;
    unsigned int russian;
    unsigned int english;
    unsigned int programming;
    unsigned int number_of_visits;
} Student;

Student *read_student_base(int*, char*);

void write_student_base(Student*, int, char*);

void print_student(Student*);

Student *select_ID(Student*, int, int);

void select_FIO(Student*, int, char*, char*, char*);

void select_average(Student*, int, float);

void select_average_more(Student*, int, float);

void select_average_less(Student*, int, float);

void add_student(Student**, int*);

void delete_student(Student**, int*, int);

#endif
