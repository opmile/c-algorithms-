#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN_CHAR 50

typedef struct {
    char text[LEN_CHAR];
    int cnt;
} Word;

void countWords(const char *frase) {
    Word *array = NULL;
    int len = 0;

    char *copy = malloc(strlen(frase) + 1);
    if (copy == NULL) {
        printf("impossível alocar memória para cópia");
        return;
    }
    strcpy(copy, frase);

    char *token = strtok(copy, " \n");

    while (token != NULL) {
        
        // verificar se já existe no vetor
        bool found = false;
        for (int i = 0; i < len; i++) {
            if (strcmp(array[i].text, token) == 0) {
                found = true;
                array[i].cnt++;
                break;
            }
        }

        // se não encontrada, adicionar ao vetor
        if (!found) {
            Word *temp = realloc(array, (len + 1) * sizeof(Word));
            if (temp == NULL) {
                printf("impossível realocar memória");
                free(array);
                free(copy);
            }
            array = temp;

            strcpy(array[len].text, token);
            array[len].cnt = 1;
            len++; // não incrementamos len antes porque queriamos usar ele para acessar o último elemento adicionado
        }

        token = strtok(NULL, " \n");
    }

    // imprimir resultado
    printf("palavras encontradas \n");
    for (int i = 0; i < len; i++) {
        printf("%s - %d\n", array[i].text, array[i].cnt);
    }

    free(copy);
    free(array);
}

int main() {
    char frase[50];
    printf("digite uma frase: ");
    fgets(frase, LEN_CHAR, stdin);

    countWords(frase);

    return 0;
}