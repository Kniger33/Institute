#ifndef MY_STRING_H
#define MY_STRING_H

int size_string(char*);
char *cat_string(char*, char*);
char *cat_string_n(char*, char*, int);
char *copy_string(char*, char*);
char *copy_string_n(char*, char*, int);
int cmp_string(char*, char*);
int cmp_string_n(char*, char*, int);
char *set_string(char*, char);
char *set_string_n(char*, char, int);

#endif
