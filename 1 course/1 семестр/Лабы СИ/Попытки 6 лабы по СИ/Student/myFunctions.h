#ifndef myFunctions included
#define myFunctions included

////ADD Student
int add_student(int count, struct data *student);


////DEL Student
int del_student(int count, struct data *student);

////SELECT zachyotka
void select_zachyotka(int count, struct data *student);


////SELECT NAME
void select_name(int count, struct data *student);


////SELECT srednyaya_otsenka
void select_srednyaya_otsenka(int count, struct data *student);

////view_students
void view_students(int count, struct data *student);


////VVOD Studenta
void vvod_studenta(int i, struct data *student);

#endif // myFunctions
