#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOMES 4
#define TAM_NOME 100

int countVowels(char *name, int len);

void toLowerCase(char *name, int len);


int main() {
    char **names = malloc(MAX_NOMES * sizeof(char*));

    if (names == NULL) {
        perror("erro ao locar memória");
        return 1;
    }

    for (int i = 0; i < MAX_NOMES; i++) {
        names[i] = malloc(TAM_NOME * sizeof(char));

        if (names[i] == NULL) {
            perror("erro ao locar memória");
            return 1;
        }

        printf("digite um nome: ");
        fgets(names[i], TAM_NOME, stdin);

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    for (int i = 0; i < MAX_NOMES; i++) {
        int len = strlen(names[i]);
        printf("vogais em %d: %d\n", i, countVowels(names[i], len));
    }

    for (int i = 0; i < MAX_NOMES; i++) {
        free(names[i]);
    }
    free(names);
    
    return 0;
}

void toLowerCase(char *name, int len) {
    for (int i = 0; i < len; i++) {
        name[i] = tolower(name[i]);
    }
}

int countVowels(char *name, int len) {
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int lenVowels = 5;

    toLowerCase(name, len);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < lenVowels; j++) {
            if (name[i] == vowels[j]) {
                count++;
            }
        }
    }
    return count;
}