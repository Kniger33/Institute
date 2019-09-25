#include <stdlib.h>

/**
* Функция возвращает длину строки
*
* @param char *str Указатель на строку
*
* @return int size Длина строки
*/

int size_string(char *str)
{
    int size = 0;
    while (*(str++) != 0)
    {
        size++;
    }
    return size;
}

/**
* Функция объединяет две строки в первой
*
* @param char *str Указатель на первую строку
* @param char *str_plus Указатель на вторую строку
*
* @return char *ret_str Указатель на первую строку
*/

char *cat_string(char *str, char *str_plus)
{
    char *ret_str = str;
    str += size_string(str);
    while (*str_plus != 0 )
    {
        *(str++) = *(str_plus++);
    }
    *str = 0;
    return ret_str; 
}

/**
* Функция вставляет в строку определенное кол-во символов второй строки
*
* @param char *str Указатель на первую строку
* @param char *str_plus Указатель на вторую строку
* @param int n Кол-во символов второй строки
*
* @return char *ret_str Указатель на первую строку
*/

char *cat_string_n(char *str, char *str_plus, int n)
{
    char *ret_str = str;
    str += size_string(str);
    while ((*str_plus != 0) && (n-- > 0))
    {
        *(str++) = *(str_plus++);
    }
    *str = 0;
    return ret_str; 
}

/**
* Функция копирует содержимое второй строки в первую
*
* @param char *to_copy Указатель на первую строку
* @param char *from_copy Указатель на вторую строку
*
* @return char *ret_str Указатель на первую строку
*/

char *copy_string(char *to_copy, char *from_copy)
{
    char *ret_str = to_copy;
    while (*from_copy != 0)
    {
        *(to_copy++) = (*from_copy++);
    }
    *to_copy = 0;
    return ret_str;
}

/**
* Функция копирует в первую строку определённое кол-во символов второй строки
*
* @param char *to_copy Указатель на первую строку
* @param char *from_copy Указатель на вторую строку
* @param int n Кол-во символов второй строки
*
* @return char *ret_str Указатель на первую строку
*/

char *copy_string_n(char *to_copy, char *from_copy, int n)
{
    char *ret_str = to_copy;
    while ((*from_copy != 0) && (n-- > 0))
    {
        *(to_copy++) = (*from_copy++);
    }
    return ret_str;
}

/**
* Функция лексикографически сранвнивает две строки
*
* @param char *str1 Указатель на первую строку
* @param char *str2 Указатель на вторую строку
*
* @return int result Если строки равны, то возвращает 0
* Если первая строка лексикографически больше, то возвращает число > 0
* Иначе число < 0
*/

int cmp_string(char *str1, char *str2)
{
    int result = 0;
    while ((result == 0) && *str1 != 0 && *str2 != 0)
    {
        char cstr1 = (*str1 >= 'a') ? (*str1 - ('a' - 'A')) : *str1;
        char cstr2 = (*str2 >= 'a') ? (*str2 - ('a' - 'A')) : *str2;
        str1++;
        str2++;
        result = cstr1 - cstr2;
    }
    if (result == 0)
    {
        if (*str1 > 0)
        {
            result++;
        }
        if (*str2 > 0)
        {
            result--;
        }
        
    }
    return result;
}

/**
* Функция лексикографически сранвнивает первые n символов двух строк
*
* @param char *str1 Указатель на первую строку
* @param char *str2 Указатель на вторую строку
* @param int n Кол-во символов
*
* @return int result Если строки равны, то возвращает 0
* Если первая строка лексикографически больше, то возвращает число > 0
* Иначе число < 0
*/

int cmp_string_n(char *str1, char *str2, int n)
{
    int result = 0;
    while ((result == 0) && (*str1 != 0) && (*str2 != 0) && (n-- > 0))
    {
        char cstr1 = (*str1 >= 'a') ? (*str1 - ('a' - 'A')) : *str1;
        char cstr2 = (*str2 >= 'a') ? (*str2 - ('a' - 'A')) : *str2;
        str1++;
        str2++;
        result = cstr1 - cstr2;
    }
    if (result == 0 && n != 0)
    {
        if (*str1 > 0)
        {
            result++;
        }
        if (*str2 > 0)
        {
            result--;
        }
        
    }
    return result;
}

/**
* Функция заполняет строку определённым символом
*
* @param char *str Указатель на строку
* @param char symb Символ которым нужно заполнить строку
*
* @return char *ret_str Указатель на строку
*/

char *set_string(char *str, char symb)
{
    char *result = str;
    while(*str != 0)
    {
        *(str++) = symb;
    }
    return result;
}

/**
* Функция заполняет первые n символов строки определённым символом
*
* @param char *str Указатель на строку
* @param char symb Символ которым нужно заполнить строку
* @param int n Кол-во символов
*
* @return char *ret_str Указатель на строку
*/

char *set_string_n(char *str, char symb, int n)
{
    char *result = str;
    while(*str != 0 && n-- > 0)
    {
        *(str++) = symb;
    }
    return result;
}