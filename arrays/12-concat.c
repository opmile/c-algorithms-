#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void toUpper(char *str) {
    str[0] = toupper(str[0]);
}

char *toCamelCase(char *str) {
    int len = strlen(str) + 1;

    // cppcheck-suppress cstyleCast
    char *copy = (char*)malloc(len);
    if (!copy) return NULL;
    strcpy(copy, str);

    // cppcheck-suppress cstyleCast
    char *result = (char*)malloc(len * 2);
    if (!result) {
        free(copy);
        return NULL;
    }
    result[0] = '\0'; // inicializa a string vazia

    char *token = strtok(copy, " \n");

    bool first = true;
    while (token) {
        if (first) {
            strcat(result, token);
            first = false;
        } else {
            toUpper(token);
            strcat(result, token);
        }
        token = strtok(NULL, " \n");
    }
    free(copy);
    return result;
}

int main() {
    char string[] = "minha string original";
    char *strCamelCase = toCamelCase(string);
    printf("%s\n", strCamelCase);

    free(strCamelCase);
    return 0;
}