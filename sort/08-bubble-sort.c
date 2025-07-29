#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ordenação em ordem alfabetica de um array de strings
void bubbleSortStr(char **strings, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) { // se a primeira for maior que a segunda
                char *temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *nomes[] = {"milena", "ana", "rafaela", "luiza", "bruna"};
    int n = sizeof(nomes) / sizeof(nomes[0]);

    bubbleSortStr(nomes, n);
    
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%s", nomes[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}