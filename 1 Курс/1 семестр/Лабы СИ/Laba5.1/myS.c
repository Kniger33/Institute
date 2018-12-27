	#include "myS.h"
char str3[100], str4[100];

int dlinaStroki(char *str) { //strlen
	int dlina = 0, i = 0;
	while (str[i] != '\0') {
		dlina++;
		i++;
	}
	return dlina;
}

char *strashnoe_slovo(char *str1, char *str2) { // strcat
	int i;
	int l1 = dlinaStroki(str1);
	int l2 = dlinaStroki(str2);
	int j = 0;

	for (i = 0; i < l1; i++) {
		*(str3 + i) = *(str1 + i);
	}

	for (i = l1; i < (l1 + l2); i++) {
		*(str3 + i) = *(str2 + j);
		j++;
	}
	str1 = str3;
	return str1;
}

char *strashnoe_slovo_v2(char *str1, char *str2, int n) { // strncat
	int i;
	int l1 = dlinaStroki(str1);
	int l2 = dlinaStroki(str2);
	printf("%d\n", n);

	for (i = 0; i < l1; i++) {
		*(str4 + i) = *(str1 + i);
	}

	for (i = 0; i < n; i++) {
		*(str4 + i + l1) = *(str2 + i);
	}
	str1 = str4;
	return str1;
}

char *strashnoe_slovo_v3(char *str1, char *str2) { //strcpy
	str1 = str2;
	return str1;
}

char *strashnoe_slovo_v4(char *str1, char *str2, int n) { //strncpy
	int i;
	int l2 = dlinaStroki(str2);
	for (i = 0; i < n; i++) {
		*(str1 + i) = *(str2 + i);
	}
	return str1;
}

int *sravnenie_strok(char *str1, char *str2){ //strcmp
    int i;
	int l1 = strlenght(str1);
    int l2 = strlenght(str2);
    int count = 0, rez;
    if (l1 == l2){
        for(i = 0; i < l1; i++ ){
            if(str1[i] == str2[i]) {
                count++;
            }
        }
        if (count == l1){
            rez = 0;
        }
        else {
            rez = 1;
        }
    }
    else {
        rez = 1;
    }
    return rez;
}

int *sravnenie_strok_v2(char *str1, char *str2, int a){ //strncmp
    int i;
	int l1 = strlenght(str1);
    int l2 = strlenght(str2);
    int count = 0, rez;
    if (l1 == l2){
        for(i = 0; i < a; i++ ){
            if(str1[i] == str2[i]) {
                count++;
            }
        }
        if (count == a){
            rez = 0;
        }
        else {
            rez = 1;
        }
    }
    else {
        rez = 1;
    }
    return rez;
}

char *zapolnenie(char* str1, char a){ // strset
    int i;
	for(i = 0; i < dlinaStroki(str1); i++){
        str1[i] = a;
    }
     return str1;
}

char *zapolnenie_v2(char* str2, char a, int x){ //strnset
    int i;
	for(i = 0; i < x; i++){
        str2[i] = a;
    }
     return str2;
}

