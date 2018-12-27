#include "MyStringFunction.h"
#include <malloc.h>

////STRLEN////
int myStrlen (char *str)
{
    int dlina = 0, i = 0;

    while (*(str + i) != '\0')
    {
        dlina++;
        i++;
    }
    return dlina;
}

////STRCAT////
char *myStrcat (char *str1, char *str2)
{
    int i = 0, j = 0, dlina = 0, pozition;
    char *str3;

    while (*(str1 + i) != '\0')
    {
        dlina++;
        i++;
    }
    str3 = (char*)malloc(dlina * sizeof(char));
    for (i = 0; i < dlina; i++)
    {
        *(str3 + i) = *(str1 + i);
    }
    pozition = dlina;

    i = 0;
        while (*(str2 + i) != '\0')
    {
        dlina++;
        i++;
    }
    str3 = (char*)realloc(str3, dlina * sizeof(char));

    for (i = pozition; i < dlina; i++)
    {
        *(str3 + i) = *(str2 + j);
        j++;
    }
    *(str3 + dlina) = '\0';
    return str3;
}

////STRNCAT////
char *myStrncat (char *str1, char *str2, int n)
{
    int i = 0, j = 0, dlina = 0, pozition;
    char *str3;

    while (*(str1 + i) != '\0')
    {
        dlina++;
        i++;
    }
    str3 = (char*)malloc((dlina + n) * sizeof(char));
    for (i = 0; i < dlina; i++)
    {
        *(str3 + i) = *(str1 + i);
    }
    pozition = dlina;
    dlina += n;

    j = 0;

    for (i = pozition; i < dlina; i++)
    {
        *(str3 + i) = *(str2 + j);
        j++;
    }
    *(str3 + dlina) = '\0';

    return str3;
    free(str3);
}

////STRCPY////
char *myStrcpy (char *str1, char *str2)
{
    int i = 0;
    while ((*(str1 + i) != '\0') && (*(str2 + i) != 0))
    {
        *(str1 + i) = *(str2 + i);
        i++;
    }
    return str1;
}

////STRNCPY////
char *myStrncpy (char *str1, char *str2, int n)
{
    int i = 0;
    while ((*(str1 + i) != '\0') && (*(str2 + i) != 0) && (i < n))
    {
        *(str1 + i) = *(str2 + i);
        i++;
    }
    return str1;
}

////STRCMP////
int myStrcmp (char *str1, char *str2)
{
    int length1 = 0, length2 = 0, rez = 0, i;
    while (*(str1 + length1) != '\0')
    {
        length1++;
    }
        while (*(str2 + length2) != '\0')
    {
        length2++;
    }
    if (length1 == length2)
    {
        for (i = 0; i < length1; i++)
        {
            if (*(str1 + i) != *(str2 + i))
            {
                rez = 1;
            }
        }
    } else
        {
            rez = 1;
        }
    return rez;
}

////STRNCMP////
int myStrncmp(char *str1, char *str2, int n)
{
    int length1 = 0, length2 = 0, rez = 0, i;
    while (*(str1 + length1) != '\0')
    {
        length1++;
    }
        while (*(str2 + length2) != '\0')
    {
        length2++;
    }
    if ((n <= length1) && (n <= length2))
    {
        for (i = 0; i < n; i++)
        {
            if (*(str1 + i) != *(str2 + i))
            {
                rez = 1;
            }
        }
    } else
        {
            rez = 1;
        }
    return  rez;
}

////STRSET////
char *myStrset (char *str, char symbol)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
            *(str + i) = symbol;
            i++;
    }
    return str;
}

////STRNSET////
char *myStrnset (char *str, char symbol, int n)
{
    int i = 0;
    while ((i < n) && (*(str + i) != '\0'))
    {
            *(str + i) = symbol;
            i++;
    }
    return str;
}
