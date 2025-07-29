/*
refazendo agrupagem de livros por categoria
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50
#define MAX_CATEGORIA 30

typedef struct {
    char nome[MAX_NOME];
    char categoria[MAX_CATEGORIA];
} Livro;

typedef struct {
    char nome[MAX_CATEGORIA];
    Livro *livros;
    int qtd;
} Categoria;

char **extrairCategorias(Livro *l, int totalLivros, int *outCount);
void agruparPorCategoria(Livro *l, int totalLivros);

int main() {
    return 0;
}

char **extrairCategorias(Livro *l, int totalLivros, int *outCount) {
    char **nomesCategorias = NULL;
    int qtd = 0;

    for (int i = 0; i < totalLivros; i++) {
        bool found = false;
        for (int j = 0; j < qtd; j++) {
            
            if (strcmp(l[i].categoria, nomesCategorias[j]) == 0) {
                found = true;
                break;
            }

            if (!found) {
                char **temp = realloc(nomesCategorias, (qtd + 1) * sizeof(char*));
                if (!temp) {
                    printf("não foi possível identificar nova categoria");
                    return NULL;
                }
                nomesCategorias = temp;

                nomesCategorias[qtd] = malloc(strlen(l[i].categoria) + 1);
                strcpy(nomesCategorias[qtd], l[i].categoria);
                qtd++;
            }
        }
    }
    *outCount = qtd;
    return nomesCategorias;
}

/*
receber o vetor de nomes das categorias unicas e seu total
o vetor de categorias deve ter o mesmo tamanho que o total de categorias unicas disponiveis

precisamos inicializar as variaveis do vetor de categorias
o nome de cada categoria dentro do vetor deve corresponder a posição de cada categoria única identificada do vetor de nomes das categorias
cada vetor de livros dentro do vetor de categorias deve ser inicializdo com null
cada quantidade de livros dentro do vetor de cateogrias deve ser inicializado com zero

para cada livro, analisar correspondência com cada uma das categorias únicas identificadas
quando achar, precisamos realocar memória do vetor de livros que está dentro do vetor de categorias para comportar mais um livro

devemos agora realizar a operação de inserir esse livro na última posição do vetor de livros daquela categoria, isso pode ser feito usando a quantidade de livros daquela categoria para acessar a última posição do vetor
no final, devemos incrementar a quantidade de livros daquela categoria para que, quando acharmos mais um livro daquela categoria, tenhamos sempre a quantidade atualizada para fazer uma nova inserção
*/

void agruparPorCategoria(Livro *l, int totalLivros) {
    int totalCategorias;
    char **nomesCategorias = extrairCategorias(l, totalLivros, totalCategorias);

    Categoria *categorias = malloc(totalCategorias * sizeof(Categoria));
    if (!categorias) {
        printf("não foi possível alocar vetor de categorias");
        return;
    }

    for (int i = 0; i < totalCategorias; i++) {
        strcpy(categorias[i].nome, nomesCategorias[i]);
        categorias[i].livros = NULL;
        categorias[i].qtd = 0;
    }

    for (int i = 0; i < totalLivros; i++) {
        for (int j = 0; j < totalCategorias; j++) {
            if (strcmp(l[i].categoria, categorias[j].nome) == 0) {
                int pos = categorias[j].qtd;
                Livro *temp = realloc(categorias[j].livros, (pos + 1) * sizeof(Livro));
                if (!temp) {
                    printf("não foi possível inserir %s nessa categoria", l[i].nome);
                    return;
                }
                categorias[j].livros = temp;

                categorias[j].livros[pos] = l[i];
                categorias[j].qtd++;
                break; // já identifiquei qual categoria aquele livro pertence
            }
        }
    }

    for (int i = 0; i < totalCategorias; i++) {
        printf("\ncategoria: %s \n", categorias[i].nome);
        for (int j = 0; j < categorias[i].qtd; i++) {
            printf("%d - %s\n", j + 1, categorias[i].livros[j].nome);
        }
    }

    for (int i = 0; i < totalCategorias; i++) {
        free(categorias[i].livros);
    }
    free(categorias);
    free(nomesCategorias);
}