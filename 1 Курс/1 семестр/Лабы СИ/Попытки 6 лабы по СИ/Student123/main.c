#include <stdio.h>
#include "str.h"
#include "stud.h"
#include <windows.h>


struct data {
    int number;
    char sname[15];
    char name[15];
    char oname[15];
    char predm[4][15];
    int point[4];
    double Spoint;
};

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int off = 1;
    while (off)
    {
        char func[1] = "";
        int res;
        printf("Select an option: \n Add - 1\n Delete - 2\n Search - 3\n All list - 4\n Close - 5\n >> ");
        scanf("%s", &func[0]);
        switch(func[0])
        {
            case '1': {
                res = studadd();
                if (res == 0) {
                    printf("Student successfully added.\n\n");
                } else if (res == 1) {
                    printf("A student with this number already exists.\n\n");
                } else {
                    printf("Error create or open file.\n\n");
                }
                break;
            }
            case '2': {
                res = studdel();
                if (res == 0) {
                    printf("Student successfully deleted.\n\n");
                } else if (res == 1) {
                    printf("Student not found.\n\n");
                } else {
                    printf("Error open file.\n\n");
                }
                break;
            }
            case '3': {
                char funcs[1] = "";
                printf("Search student:\n");
                printf("Select the search option: Number(1)/Name(2)/Rating(3) >> ");
                scanf("%s", &funcs[0]);
                switch(funcs[0])
                {
                    case '1': {
                        res = snum();
                        if (res == 0) {
                            printf("Student found.\n\n");
                        } else if (res == 1) {
                            printf("Student don't found.\n\n");
                        } else {
                            printf("Error create or open file.\n\n");
                        }
                        break;
                    }
                    case '2': {
                        res = sname();
                        if (res == 0) {
                            printf("Student found.\n\n");
                        } else if (res == 1) {
                            printf("Student don't found.\n\n");
                        } else {
                            printf("Error create or open file.\n\n");
                        }
                        break;
                    }
                    case '3': {
                        res = srait();
                        if (res == 0) {
                            printf("Student found.\n\n");
                        } else if (res == 1) {
                            printf("Student don't found.\n\n");
                        } else {
                            printf("Error create or open file.\n\n");
                        }
                        break;
                    }
                    default: {
                        printf("Unidentified function.\n");
                    }
                }
                break;
            }

            case '4': {
                studall();
                break;
            }
            case '5': {
                off = 0;
                break;
            }
            default: {
                printf("Unidentified function.\n");
            }
        }
    }
    return 0;
}
//FILE *fp = fopen("spisok.txt", "");
