#include <stdio.h>
#include <stdlib.h>
#include "myS.h"

//Запускать через F9

int main() {
	int num, num2;
	char stroka1[] = "What is";
	char stroka2[] = " love?";

    printf("Stroka1: %s\nStroka2: %s\n", stroka1, stroka2);
    printf("Length of s1: %d and s2: %d\n", dlinaStroki(stroka1), dlinaStroki(stroka2));
	printf("Enter symbols for add(b) and copy(m) symbols: ");
	scanf("%d%d", &num, &num2);


	char *pesnya = myStrcat(stroka1, stroka2);
	char *strashnaya_pesnya = myStrncat(stroka1, stroka2, num);
	char *ochen_strashnaya_pesnya = myStrcpy(stroka1, stroka2);
	char *super_strashnaya_pesnya = myStrncpy(stroka1, stroka2, num2);
	int *rez_sravneniya = myStrcmp(stroka1, stroka2);

    printf("Enter number(k) of symbols for compare: ");
    scanf("%d", &num);
    int *rez_sravneniya_v2 = myStrncmp(stroka1, stroka2, num);


	printf("\nAdd s2 to s1: %s\n", pesnya);
	printf("Add b symbols to s1 from s2: %s\n", strashnaya_pesnya);
	printf("Copy s2 in s1: %s\n", ochen_strashnaya_pesnya);
	printf("Copy m symbols of s2 in s1: %s\n", super_strashnaya_pesnya);
	printf("Compare strings(1 if s1 != s2 and 0 if reverse): %d\n", rez_sravneniya);
    printf("Compare symbols of strings(1 if s1(k) != s2(k) and 0 if reverse): %d\n", rez_sravneniya_v2);


    char c;

    printf("\nEnter symbols for set: ");
    getchar();
    scanf("%c", &c);

    printf("\nBefore set: %s\n", stroka1);
    char *func8 = myStrset(stroka1, c);
    printf("After set: %s\n", func8);

    char d;
    int n;

    printf("Enter number of symbols for set and which will set:\n");
    scanf("%d",&n);
    getchar();
    scanf("%c", &d);

    printf("Before nSet: %s\n", stroka2);
    char *func9 = myStrnset(stroka2, n, d);
    printf("After nSet: %s", func9);

	return 0;
}


