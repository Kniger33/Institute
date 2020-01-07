#include <stdio.h>
#include <regex.h>

int main() {
    FILE *f = fopen("/home/sergei/University/tranlsators/lab1/text.txt", "r");
    char *string = "";
    regex_t regex_numbers, regex_floats, regex_id;

    if (!regcomp(&regex_numbers, "^-?[1-9][0-9]+$", 0)) {
        printf("compiled for numbers\n");
    }
    if (!regcomp(&regex_id, "^_[0-9a-zA-Z]+$", 0)) {

    }

    while (fscanf(f, "%s", &string) != EOF) {
        int res = regexec(&regex_numbers, string, 0, NULL, 0);
        if (res == 0) {
            printf("%s - number\n", string);
        } else if (((string[0] >= 'a' && string[0] <= 'z') || (string[0] >= 'A' && string[0] <= 'Z') || string[0] == '_')) {
            printf("%s - id\n", string);
        }
    }

    return 0;
}