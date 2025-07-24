#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char letra;
    int freq;
} LetraFreq;

void contarFrequencia(char *str, int len);

int main() {
    char frase[] = "hoje eu fui pra faculdade e aprendi algoritmos legais";
    int len = sizeof(frase) / sizeof(frase[0]);

    contarFrequencia(frase, len);

    return 0;
}

void contarFrequencia(char *str, int len) {
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int lenAlpha = sizeof(alphabet) / sizeof(alphabet[0]);

    LetraFreq *vetor = malloc(lenAlpha * sizeof(LetraFreq));
    for (int i = 0; i < lenAlpha; i++) {
        vetor[i].letra = alphabet[i]; // como vetor[i].letra e alphabet[i] são char a comparação é feita como um tipo de dado normal, sem operadores de strings (strcpy)
        vetor[i].freq = 0;
    }

    int pos = 0;

    int strLen = strlen(str) + 1;
    char *copia = malloc(strLen);
    if (!copia) {
        printf("não foi possível alocar memória");
        return;
    }
    strcpy(copia, str);

    for (int i = 0; i < len; i++) {
        copia[i] = toupper(copia[i]);
    }

    char *token = strtok(copia, " \n");

    while (token != NULL) {

        for (int i = 0; i < lenAlpha; i++) {
            if (token[0] == vetor[i].letra) { // podemos comparar char com char assim, sem precisar de um comparador de strings (strcmp)
                vetor[i].freq++;
                break;
            }
        }

        token = strtok(NULL, " \n");
    }

    for (int i = 0; i < lenAlpha; i++) {
        if (vetor[i].freq > 0) {
            printf("\n Letra: %c\n -- %d\n", vetor[i].letra, vetor[i].freq);
        }
    }

    free(vetor);
    free(copia);
}