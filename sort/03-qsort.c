#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara_por_comprimento(const void *a, const void *b) {
    const char *str1 = *(const char**)a;
    const char *str2 = *(const char**)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // == return strlen(str1) - strlen(str2);
    return len1 - len2;
}

int compara_alfabeticamente(const void *a, const void *b) {
    const char *str1 = *(const char**)a;
    const char *str2 = *(const char**)b;

    return strcmp(str1, str2);
}

int main() {
    /*
    char *strings[] = {"eu", "sou", "a", "milena"};
    int n = sizeof(strings) / sizeof(strings[0]);

    qsort(strings, n, sizeof(char*), compara_por_comprimento);

    for (int i = 0; i < n; i++) {
        printf("%s ", strings[i]);
        if (i < n - 1) printf(", ");
    }
    */

    char *nomes[] = {"alice", "bruno", "alberto", "milena", "carlos", "roberta", "roberto"};
    int lenNomes = sizeof(nomes) / sizeof(nomes[0]);

    qsort(nomes, lenNomes, sizeof(char*), compara_alfabeticamente);

    for (int i = 0; i < lenNomes; i++) {
        printf("%s", nomes[i]);
        if (i < lenNomes - 1) printf(", ");
    }
    printf("\n");

    return 0;
}