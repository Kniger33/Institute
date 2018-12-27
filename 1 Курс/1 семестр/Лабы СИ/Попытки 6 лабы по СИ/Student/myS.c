#include "myS.h"
#include <malloc.h>


//Strlen
int myStrlen (char *str) {

    int dlina = 0, i = 0;

    while (str[i] != '\0') {
        dlina++;
        i++;
    }
    return dlina;
}

char reg_check (char *str) {
    char current_symbol;
    int i;
    for (i = 0; current_symbol; i++) {
        current_symbol = str[i];

        if (current_symbol >= 65 && current_symbol <= 90) {
            current_symbol += 32;
        }

        str[i] = current_symbol;
    }

    return str;
}


//Strcat
char *myStrcat (char *str1, char *str2) {

    int i = 0, j = 0, dlina = 0, poz;
    char *str3;


    dlina = myStrlen(str1);
    str3 = (char*)malloc(dlina * sizeof(char));
    for (i = 0; i < dlina; i++) {
        str3[i] = str1[i];
    }
    poz = dlina;

    i = 0;

    dlina = myStrlen(str2);

    str3 = (char*)realloc(str3, dlina * sizeof(char));

    for (i = poz; i < dlina; i++) {
        str3[i] = str2[j];
        j++;
    }
    str3[dlina] = '\0';

    return str3;
}


//Strncat
char *myStrncat (char *str1, char *str2, int n) {

    int i = 0, j = 0, dlina = 0, poz;
    char *str3;

    dlina = myStrlen(str1);

    str3 = (char*)malloc((dlina + n) * sizeof(char));

    for (i = 0; i < dlina; i++) {
        str3[i] = str1[i];
    }
    poz = dlina;
    dlina += n;

    j = 0;

    for (i = poz; i < dlina; i++) {
        str3[i] = str2[j];
        j++;
    }

    str3[dlina] = '\0';

    return str3;

}


//Strcpy
char *myStrcpy (char *str1, char *str2) {

    int i = 0;
    while ((str1[i] != '\0') && (str2[i] != 0)) {
        str1[i] = str2[i];
        i++;
    }

    return str1;
}


//Strncpy
char *myStrncpy (char *str1, char *str2, int n) {

    int i = 0;
    while ((str1[i] != '\0') && (str2[i] != 0) && (i < n)) {
        str1[i] = str2[i];
        i++;
    }

    return str1;
}


//Strcmp
int myStrcmp (char *str1, char *str2) {

    int rezult = 0, i;
    if (myStrlen(str1) == myStrlen(str2)) {
            for (i = 0; i < myStrlen(str1); i++) {
                if (str1[i] != str2[i]) {
                    rezult = 1;
                    break;
                }
            }
        }
    else {
        rezult = 1;
    }

    return rezult;
}


//Strncmp
int myStrncmp(char *str1, char *str2, int n) {

    int length1, length2, rezult = 0, i;
    length1 = myStrlen(str1);
    length2 = myStrlen(str2);

    if ((n <= length1) && (n <= length2)) {
        for (i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                rezult = 1;
            }
        }
    }
    else {
        rezult = 1;
    }

    return  rezult;
}


//Strset
char *myStrset (char *str1, char symb) {

    int i = 0;
    while (str1[i] != '\0') {
            str1[i] = symb;
            i++;
    }

    return str1;
}


//Strnset
char *myStrnset (char *str1, char symb, int n) {

    int i = 0;
    while ((i < n) && (str1[i] != '\0')) {
            str1[i] = symb;
            i++;
    }

    return str1;
}

