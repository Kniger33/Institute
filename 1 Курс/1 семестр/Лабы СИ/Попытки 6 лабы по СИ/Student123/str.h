#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

int str_len( char *st0);
char *str_ct(char *st, char *st1);
char *strn_ct(char *st2, char *st3, int n);
int *str_copy(char *st4, char *st5);
char *strn_copy(char *st6, char *st7, int n);
int str_cmp(char *st, char *st1);
int strn_cmp(char *st, char *st1, int n);
char *str_set(char *st, char x);
char *strn_set(char *st, char x, int n);

#endif // STR_H_INCLUDED
