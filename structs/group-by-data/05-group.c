#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50
#define MAX_ESPECIE 30

typedef struct {
    char nome[MAX_NOME];
    char especie[MAX_ESPECIE];
} Animal;

typedef struct {
    char nome[MAX_ESPECIE];
    int qtd;
} Especie;

char **extrairEspecies(Animal *a, int totalAnimais, int *outCount) {
    char **nomesEspecies = NULL;
    int qtd = 0;

    // para cada animal, comparar se sua especie já foi adicionada no vetor
    for (int i = 0; i < totalAnimais; i++) {
        char *atual = a[i].especie;
        bool found = false;

        for (int j = 0; j < qtd; j++) {
            if (strcmp(atual, nomesEspecies[j]) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            char **temp = realloc(nomesEspecies, (qtd + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar memória");
                break;
            }

            nomesEspecies = temp;
            nomesEspecies[qtd] = malloc(strlen(atual) + 1);
            strcpy(nomesEspecies[qtd], atual);
            qtd++;
        }
    }
    *outCount = qtd;
    return nomesEspecies;
}

void contarEspecie(Animal *a, int totalAnimais) {
    Especie *especies = malloc(totalAnimais * sizeof(Animal));
    if (!especies) {
        printf("não foi possível alocar memória");
        return;
    }

    int totalEspecies;
    char **nomesEspecies = extrairEspecies(a, totalAnimais, &totalEspecies);

    for (int i = 0; i < totalEspecies; i++) {
        strcpy(especies[i].nome, nomesEspecies[i]);
        especies[i].qtd = 0;
    }

    for (int i = 0; i < totalAnimais; i++) {
        for (int j = 0; j < totalEspecies; j++) {
            if (strcmp(a[i].especie, especies[j].nome) == 0) {
                especies[j].qtd++;
                break;
            }
        }
    }

    printf("espécies contadas: \n");
    for (int i = 0; i < totalEspecies; i++) {
        printf("- %s -- freq.: %d\n", especies[i].nome, especies[i].qtd);
    }

    free(nomesEspecies);
    free(especies);
}

int main() {
    Animal animais[] = {
        {"Mimi", "gato"},
        {"Rex", "cachorro"},
        {"Bolinha", "gato"},
        {"Bob", "cachorro"},
        {"Piu", "passarinho"},
        {"Luna", "gato"},
        {"Pompom", "coelho"},
        {"Toby", "cachorro"}
    };

    int n = sizeof(animais) / sizeof(animais[0]);

    contarEspecie(animais, n);

    return 0;
}