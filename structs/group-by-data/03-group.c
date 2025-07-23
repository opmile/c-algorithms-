#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITULO 50
#define MAX_GENERO 30

typedef struct {
    char titulo[MAX_TITULO];
    char genero[MAX_GENERO];
} Filme;

typedef struct {
    char nome[MAX_GENERO];
    Filme *filmes;
    int qtd;
} Genero;

char **extrairGeneros(Filme *f, int totalFilmes, int *outCount);

void agruparPorGenero(Filme *f, int totalFilmes) {
    int totalGeneros;
    char **nomesGeneros = extrairGeneros(f, totalFilmes, &totalGeneros);

    Genero *generos = malloc(totalGeneros * sizeof(Genero));
    if (!generos) {
        printf("não foi possível alocar memória");
        return;
    }

    for (int i = 0; i < totalGeneros; i++) {
        strcpy(generos[i].nome, nomesGeneros[i]);
        generos[i].filmes = NULL;
        generos[i].qtd = 0;
    }

    for (int i = 0; i < totalFilmes; i++) {
        for (int j = 0; j < totalGeneros; j++) {
            if (strcmp(f[i].genero, generos[j].nome) == 0) {
                int pos = generos[j].qtd;
                Filme *temp = realloc(generos[j].filmes, (pos + 1) * sizeof(Filme));
                if (!temp) {
                    printf("não foi possível realocar memória");
                    return;
                }

                generos[j].filmes = temp;
                generos[j].filmes[pos] = f[i];
                generos[j].qtd++;
                break;
            }
        }
    }

    for (int i = 0; i < totalGeneros; i++) {
        printf("\n gênero: %s ---- %d\n", generos[i].nome, generos[i].qtd);
        for (int j = 0; j < generos[i].qtd; j++) {
            printf(" - %s\n", generos[i].filmes[j].titulo);
        }
    }

    // libera vetor de generos
    for (int i = 0; i < totalGeneros; i++) {
        free(generos[i].filmes);
    }
    free(generos);

    // libera vetor de nomes dos generos extraidos
    for (int i = 0; i < totalGeneros; i++) {
        free(nomesGeneros[i]);
    }
    free(nomesGeneros);
}

char **extrairGeneros(Filme *f, int totalFilmes, int *outCount) {
    char **nomesGeneros = NULL;
    int qtd = 0;

    for (int i = 0; i < totalFilmes; i++) { // para cada filme
        bool achou = false;

        for (int j = 0; j < qtd; j++) { // verifica se já está no vetor 
            if (strcmp(nomesGeneros[j], f[i].genero) == 0) {
                achou = true;
                break;
            }
        }

        if (!achou) {
            char **temp = realloc(nomesGeneros, (qtd + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar memória");
                break;
            }
            nomesGeneros = temp;

            nomesGeneros[qtd] = malloc(strlen(f[i].genero) + 1);
            strcpy(nomesGeneros[qtd], f[i].genero);
            qtd++;
        }
    }

    *outCount = qtd;
    return nomesGeneros;
}


int main() {
    Filme filmes[] = {
        {"Interestelar", "ficção científica"},
        {"Matrix", "ficção científica"},
        {"O Poderoso Chefão", "drama"},
        {"Forrest Gump", "drama"},
        {"Vingadores", "ação"},
        {"Homem-Aranha", "ação"},
        {"A Chegada", "ficção científica"},
        {"Gladiador", "épico"},
        {"O Senhor dos Anéis", "fantasia"},
        {"Harry Potter", "fantasia"}
    };

    int n = sizeof(filmes) / sizeof(filmes[0]);

    agruparPorGenero(filmes, n);

    return 0;
}