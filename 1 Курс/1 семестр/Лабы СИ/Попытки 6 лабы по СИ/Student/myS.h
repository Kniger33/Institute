#define myS.h included
#ifndef myS.h included

//Strlen
int myStrlen (char *str);


char reg_check (char *str);


//Strcat
char *myStrcat (char *str1, char *str2);


//Strncat
char *myStrncat (char *str1, char *str2, int n);


//Strcpy
char *myStrcpy (char *str1, char *str2);


//Strncpy
char *myStrncpy (char *str1, char *str2, int n);


//Strcmp
int myStrcmp (char *str1, char *str2);


//Strncmp
int myStrncmp(char *str1, char *str2, int n);


//Strset
char *myStrset (char *str1, char symb);


//Strnset
char *myStrnset (char *str1, char symb, int n);

#endif

