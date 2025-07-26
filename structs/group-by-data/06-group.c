#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50
#define MAX_MARCA 30

typedef struct {
    char nome[MAX_NOME];
    char marca[MAX_MARCA];
} Produto;

typedef struct {
    char nome[MAX_MARCA];
    Produto *produtos;
    int qtd;
} Marca;

char **extrairMarcas(Produto *p, int totalProdutos, int *outCount);
void agruparPorMarca(Produto *p, int totalProdutos);

int main() {
    Produto produtos[] = {
        {"iPhone", "Apple"},
        {"MacBook", "Apple"},
        {"Galaxy S22", "Samsung"},
        {"TV QLED", "Samsung"},
        {"ThinkPad", "Lenovo"},
        {"Moto G", "Motorola"},
        {"AirPods", "Apple"},
        {"Galaxy Watch", "Samsung"},
        {"Ideapad", "Lenovo"},
        {"Razr", "Motorola"}
    };
    int totalProdutos = sizeof(produtos) / sizeof(produtos[0]);

    agruparPorMarca(produtos, totalProdutos);
    
    return 0;
}

char **extrairMarcas(Produto *p, int totalProdutos, int *outCount) {
    char **nomesMarcas = NULL;
    int qtd = 0;

    for (int i = 0; i < totalProdutos; i++) {
        char *atual = p[i].marca;
        bool found = false;

        for (int j = 0; j < qtd; j++) {
            if (strcmp(atual, nomesMarcas[j]) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            char **temp = realloc(nomesMarcas, (qtd + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar memória");
                break;
            }

            nomesMarcas = temp;
            nomesMarcas[qtd] = malloc(strlen(atual) + 1);
            strcpy(nomesMarcas[qtd], atual);
            qtd++;
        }
    }

    *outCount = qtd; // preencher o valor do ponteiro em seu endereço
    return nomesMarcas;
}

void agruparPorMarca(Produto *p, int totalProdutos) {
    int totalMarcas;
    char **nomesMarcas = extrairMarcas(p, totalProdutos, &totalMarcas);

    Marca *marcas = malloc(totalMarcas * sizeof(Marca));
    for (int i = 0; i < totalMarcas; i++) {
        strcpy(marcas[i].nome, nomesMarcas[i]);
        marcas[i].produtos = NULL;
        marcas[i].qtd = 0;
    }

    for (int i = 0; i < totalProdutos; i++) {
        for (int j = 0; j < totalMarcas; j++) {
            if (strcmp(p[i].marca, marcas[j].nome) == 0) {
                int pos = marcas[j].qtd;
                Produto *temp = realloc(marcas[j].produtos, (pos + 1) * sizeof(Produto));
                if (!temp) {
                    printf("não foi possível realocar memória");
                    return;
                }
                marcas[j].produtos = temp;

                marcas[j].produtos[pos] = p[i];
                marcas[j].qtd++;
                break;
            }
        }
    }

    for (int i = 0; i < totalMarcas; i++) {
        printf("\n marca: %s - %d\n", marcas[i].nome, marcas[i].qtd);
        for (int j = 0; j < marcas[i].qtd; j++) {
            printf("%d - %s\n", j + 1, marcas[i].produtos[j].nome);
        }
    }

    for (int i = 0; i < totalMarcas; i++) {
        free(nomesMarcas[i]);
        free(marcas[i].produtos);
    }
    free(nomesMarcas);
    free(marcas);
}