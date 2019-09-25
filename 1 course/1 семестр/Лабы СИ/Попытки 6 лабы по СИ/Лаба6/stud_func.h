#ifndef STUD_FUNC_H_INCLUDED
#define STUD_FUNC_H_INCLUDED

typedef struct {

    char *first_name;
    char *second_name;
    char *patronym;
    int rb;
    double average_mark;
    int math;
    int rus_lang;
    int eng_lang;
    int history;
} Student;
//���������� ��������� � ����
Student *read_student_base(int*, char*);

//
void write_student_base(Student *, int , char *);

//����� �� ������ ��ר���
Student *select_RB(Student *, int , int );

//����� �� ���
void select_FIO(Student *, int , char *, char *, char *);

//����� �� ������� ������
void select_average_mark(Student *, int , double );

//����� �� ������, ������� ��� ������ ���Ĩ����
void select_average_mark_more(Student *, int , double );

//����� �� ������, ������� ��� ������ ���Ĩ����
void select_average_mark_less(Student *, int , double );

//���������� ��������
void add_student(Student **, int *);

//�������� ��������
void delete_student(Student **, int *, int );

//����� ��������
void print_student(Student*) ;

#endif

