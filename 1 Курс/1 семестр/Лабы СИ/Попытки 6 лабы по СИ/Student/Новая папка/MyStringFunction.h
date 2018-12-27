#ifndef MYSTRINGFUNCTION_H_INCLUDED
#define MYSTRINGFUNCTION_H_INCLUDED


int myStrlen (char *str);

char *myStrcat (char *str1, char *str2);

char *myStrncat (char *str1, char *str2, int n);

char *myStrcpy (char *str1, char *str2);

char *myStrncpy (char *str1, char *str2, int n);

int myStrcmp (char *str1, char *str2);

int myStrncmp(char *str1, char *str2, int n);

char *myStrset (char *str, char symbol);

char *myStrnset (char *str, char symbol, int n);


#endif // MYSTRINGFUNCTION_H_INCLUDED
