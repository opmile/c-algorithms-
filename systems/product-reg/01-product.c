#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int id;
    float preco;
    int qtdEstoque;
} Produto;

Produto *adicionar(
    Produto *produtos,
    int *qtdProdutos,
    char *nome,
    int id,
    float preco,
    int qtdEstoque
);

int main() {
    
    Produto *produtos = NULL;
    int qtdProdutos = 0;

    int count = 1;
    int op;
    do {
        printf("\ndigite os dados do produto %d\n", count++);
        
        char nome[MAX_NOME];
        printf("nome do produto: ");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        int id;
        printf("id do produto: ");
        scanf("%d", &id);
        getchar();

        float preco;
        printf("preço do produto: ");
        scanf("%f", &preco);
        getchar();

        int qtdEstoque;
        printf("quantidade disponível no estoque: ");
        scanf("%d", &qtdEstoque);
        getchar();

        produtos = adicionar(
            produtos,
            &qtdProdutos,
            nome,
            id,
            preco,
            qtdEstoque
        );

        printf("deseja cadastrar novo? 1 - sim / 0 - não\n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);

    for (int i = 0; i < qtdProdutos; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("id: %d -- %s\n", produtos[i].id, produtos[i].nome);
        printf("R$%.2f\n", produtos[i].preco);
        printf("ESTOQUE: %d\n", produtos[i].qtdEstoque);
    }

    free(produtos);

    return 0;
}

Produto *adicionar(
    Produto *produtos,
    int *qtdProdutos,
    char *nome,
    int id,
    float preco,
    int qtdEstoque
) {
    Produto *temp = realloc(produtos, (*qtdProdutos + 1) * sizeof(Produto));
    if (!temp) {
        printf("não foi possível cadastrar novo produto");
        return NULL;
    }
    produtos = temp;

    Produto *p = &produtos[*qtdProdutos];
    strcpy(p->nome, nome);
    p->id = id;
    p->preco = preco;
    p->qtdEstoque = qtdEstoque;

    (*qtdProdutos)++;

    return produtos;
}