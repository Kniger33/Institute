#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

//Добавить участника
int add_student();

//Удалить участника
int delete_student();

//Вывод участников, занявших 1-3 места
void search_students();

//Вывод в виде таблицы
int print_table();

//Вывод информации об участниках(КОД, ФИО, ПОЛ, БАЛЛЫ, СУММА БАЛЛОВ)
int print_students();

//Количество участников мужского пола, родившихся в 2003г.
int male_func();

//Средний возраст участников олимпиады
double average_age();

#endif // STUD_H_INCLUDED
