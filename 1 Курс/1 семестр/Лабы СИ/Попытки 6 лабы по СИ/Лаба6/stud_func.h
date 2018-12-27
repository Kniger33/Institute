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
//йнкхвеярбн ярсдемрнб б аюге
Student *read_student_base(int*, char*);

//
void write_student_base(Student *, int , char *);

//онхяй он мнлепс гюв╗рйх
Student *select_RB(Student *, int , int );

//онхяй он тхн
void select_FIO(Student *, int , char *, char *, char *);

//онхяй он япедмеи нжемйе
void select_average_mark(Student *, int , double );

//онхяй он нжемйе, анкэьеи хкх пюбмни ббед╗ммни
void select_average_mark_more(Student *, int , double );

//онхяй он нжемйе, лемэьеи хкх пюбмни ббед╗ммни
void select_average_mark_less(Student *, int , double );

//днаюбкемхе ярсдемрю
void add_student(Student **, int *);

//сдюкемхе ярсдемрю
void delete_student(Student **, int *, int );

//бшбнд ярсдемрю
void print_student(Student*) ;

#endif

