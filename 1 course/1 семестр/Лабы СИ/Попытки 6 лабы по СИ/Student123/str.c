#include "str.h"
int str_len( char *st0){

	int i;
	while(*(st0 + i) != '\0')
		i++;

	return i;
}

char *str_ct(char *st, char *st1){
	int i;
	int n = str_len(st);

	int m = str_len(st1);
	for(i = 0; i < m; i++)
		*(st + n + i) = *(st1 + i);

 	return 0;
}

char *strn_ct(char *st2, char *st3, int n){

	int i;
	int a = str_len(st2);

	for(i = 0; i < n; i++)
		*(st2 + i + a) = *(st3 + i);

 	return 0;
}

int *str_copy(char *st4, char *st5){
	int i, n = str_len(st4);

	for(i = 0; i < n; i++)
		*(st4 + i) = *(st5 + i);

	return 0;
}

char *strn_copy(char *st6, char *st7, int n){
	int i;

	for(i = 0; i < n; i++ )
		*(st6 + i) = *(st7 + i);

	return 0;
}

int str_cmp(char *st, char *st1){

    int i, c = 0;
	//int a = str_len(st), b = str_len(st1);

//	printf("%d %d\n", a,b);
    if (str_len(st) == str_len(st1)){
        for(i = 0; i < str_len(st); i++ ){
            if(*(st + i) == *(st1 + i)) {
                c++;
            }
        }
        if (c == str_len(st))
            return 0;//?????? ?????
        else
            return 1;//?????? ?? ?????
    }
    else
        return 1;//?????? ?? ?????

    return 1;
}

int strn_cmp(char *st, char *st1, int n){

    int i, c = 0, res;
	//int a = str_len(st), b = str_len(st1);

    if (str_len(st) == str_len(st1)){
        for(i = 0; i < n; i++ ){
            if(*(st + i) == *(st1 + i)) {
                c++;
            }
        }
        if (c == n)
            res = 0;//?????? ?????
        else
            res = 1;//?????? ?? ?????
    }
    else
        res = 1;//?????? ?? ?????

    return res;
}

char *str_set(char *st, char x){
    int i, a = str_len(st);

	for(i = 0; i < a; i++){
        *(st + i) = x;
    }

     return st;
}

char *strn_set(char *st, char x, int n){
    int i;

	for(i = 0; i < n; i++){
         *(st + i) = x;
    }

     return st;
}
