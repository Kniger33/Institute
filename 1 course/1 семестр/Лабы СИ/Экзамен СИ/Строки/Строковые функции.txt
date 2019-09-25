#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

char *myStrcpy (char *str1, char *str2)
{
    int length1 = 0, length2 = 0, i;
    while (*(str1 + length1) != '\0')
    {
        length1++;
    }
        while (*(str2 + length2) != '\0')
    {
        length2++;
    }
    if (length1 >= length2)
    {
        for (i = 0; i < length2; i ++)
        {
            *(str1 + i) = *(str2 + i);
        }
    } else
        {
            for (i = 0; i < length1; i++)
            {

            }
        }
    return str1;
}

char *myStrncpy (char *str1, char *str2, int n)
{
    int i = 0;
    while (*(str1 + i) != '\0')
    {
        *(str1 + i) = *(str2 + i);
        i++;
    }
    *(str1 + i) = '\0';
    return str1;
}

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


int main()
{
    int n;

    char *string1 = "Hello, ";
    char *string2 = "World!1234";

    char string3[] = "String";
    char *string4 = "String";

    char *string5 = "Stping";
    printf("FFF");
    char x;
    scanf("%c", &x);

    int dlina = myStrlen(string1);
    printf("%d\n", dlina);

    char *rezString = myStrcat(string1, string2);
    printf("%s\n", rezString);

    n = 3;
    rezString = myStrncat(string1, string2, n);
    printf("%s\n", rezString);

    //rezString = myStrcpy(string1, string2);
    //printf("%s\n", rezString);

    int result = myStrcmp(string3, string4);
    printf("Result = %d\n", result);

    result = myStrncmp(string4, string5, n);
    printf("Result = %d\n", result);
    
  
    printf("RezDo:%s\n", string3);
    char *stringPosl = myStrset(string3, x);
    printf("RezPosle:%s\n", string3);

    return 0;
}
