#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CATEGORIA 30

typedef struct {
    char titulo[MAX_NOME];
    char categoria[MAX_CATEGORIA];
} Livro;

typedef struct {
    char nome[MAX_NOME];
    Livro *livros; // vetor de livros daquela categoria
    int qtd; // quantidade de livros daquela categoria
} Categoria;

void agruparPorCategoria(Livro *l, int totalLivros);

int main() {
    Livro livros[] = {
        {"1984", "ficção"},
        {"O Hobbit", "ficção"},
        {"Steve Jobs", "biografia"},
        {"Aventuras de Pi", "aventura"},
        {"Sherlock Holmes", "suspense"},
        {"Romeu e Julieta", "romance"}
    };

    int n = sizeof(livros) / sizeof(livros[0]);

    agruparPorCategoria(livros, n);

    return 0;
}

void agruparPorCategoria(Livro *l, int totalLivros) {
    const char *nomesCategoria[] = {"ficção", "romance", "biografia", "aventura", "suspense"};
    int totalCategorias = sizeof(nomesCategoria) / sizeof(nomesCategoria[0]);
    
    Categoria *categorias = malloc(totalCategorias * sizeof(Categoria));
    if (!categorias) {
        printf("não foi possível alocar memória");
        return;
    }

    for (int i = 0; i < totalCategorias; i++) {
        strcpy(categorias[i].nome, nomesCategoria[i]);
        categorias[i].livros = NULL;
        categorias[i].qtd = 0;
    }

    for (int i = 0; i < totalLivros; i++) {
        for (int j = 0; j < totalCategorias; j++) {
            if (strcmp(l[i].categoria, categorias[j].nome) == 0) {
                int pos = categorias[j].qtd;
                Livro *temp = realloc(categorias[j].livros, (pos + 1) * sizeof(Livro));
                if (!temp) {
                    printf("não foi possível realocar memória");
                    return;
                }

                categorias[j].livros = temp;
                categorias[j].livros[pos] = l[i];
                categorias[j].qtd++;
                break;
            }
        }
    }

    for (int i = 0; i < totalCategorias; i++) {
        printf("\n categoria: %s --- %d\n", categorias[i].nome, categorias[i].qtd);
        for (int j = 0; j < categorias[i].qtd; j++) {
            printf(" - %s\n", categorias[i].livros[j].titulo);
        }
    }

    for (int i = 0; i < totalCategorias; i++) {
        free(categorias[i].livros);
    }
    free(categorias);
}