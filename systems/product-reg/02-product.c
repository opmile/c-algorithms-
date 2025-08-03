#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int id;
    float preco;
    int qtdEstoque;
} Produto;

// realocar produtos para caber mais um produto
// criar um ponteiro de produto que esta na última posição (qtdProduto)
// com o ponteiro, fazer as atribuições necessárias para inserir o novo produto no vetor
// incrementar qtd de produtos (recebido como ponteiro para ser atualizado fora da função)
Produto  *cadastrar(
    Produto *produtos,
    int *qtdProdutos,
    const char *nome,
    float preco,
    int qtdEstoque
) {
    // cppcheck-suppress cstyleCast
    Produto *temp = (Produto*)realloc(produtos, (*qtdProdutos + 1) * sizeof(Produto));
    if (!temp) {
        printf("erro de memória ao cadastrar produto!");
        return NULL;
    }
    produtos = temp;

    Produto *p = &produtos[*qtdProdutos];
    strcpy(p->nome, nome);
    // p->id = produtos[*qtdProdutos - 1].id + 1; causa segfault se *qtdProdutos == 0, porque produtos[-1] -- operador ternário facilita
    p->id = (*qtdProdutos == 0) ? produtos[*qtdProdutos - 1].id + 1 : 1;
    p->preco = preco;
    p->qtdEstoque = qtdEstoque;

    (*qtdProdutos)++;

    return produtos;
}

// percorrer todo o array de produtos procurando pelo id 
// se acharmos correspondênica, quebrar o loop e marcar achado como true
// i agora aponta exatamente para onde o produto deve ser retirado
// se achado é true, faremos o deslocamento para a esquerda de modo a "tapar o buraco" do elemento a ser removido
// agora é necessário realocar array para ocupar uma posição a menos
// decrementar a qtd de produtos cadastrados
Produto *remover (
    Produto *produtos, 
    int *qtdProdutos,
    int id
) {
    bool found = false;
    int i;

    for (i = 0; i < *qtdProdutos; i++) {
        if (produtos[i].id == id) {
            found = true;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *qtdProdutos - 1; j++) {
            produtos[j] = produtos[j + 1];
        }

        // cppcheck-suppress cstyleCast
        Produto *temp = (Produto*)realloc(produtos, (*qtdProdutos - 1) * sizeof(Produto));
        if (!temp && *qtdProdutos > 0) {
            printf("impossível redimensionar array após remoção");
            return NULL;
        }
        produtos = temp;
        (*qtdProdutos)--;
    }

    if (!found) {
        printf("o produto não existe na base de dados!\n");
        return NULL;
    }

    return produtos;
}

void listar(const Produto *produtos, int qtdProdutos) {
    for (int i = 0; i < qtdProdutos; i++) {
        printf("ID: %d -- %s -- %.2f -- ESTOQUE: %d\n", 
            produtos[i].id, 
            produtos[i].nome, 
            produtos[i].preco, 
            produtos[i].qtdEstoque
        );
    }
}

int buscarIndicePorId(const Produto *produtos, int qtdProdutos, int id) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) return i;
    }
    return -1;
}

void buscarPorId(const Produto *produtos, int qtdProdutos, int id) {
    int i = buscarIndicePorId(produtos, qtdProdutos, id);
    if (i == -1) {
        printf("produto de ID: %d não existe na base de dados!\n", id);
    }

    printf("ID: %d -- %s -- %.2f -- ESTOQUE: %d\n", 
        produtos[i].id, 
        produtos[i].nome, 
        produtos[i].preco, 
        produtos[i].qtdEstoque
    );
}

bool buscarPorNome(Produto *produtos, int qtdProdutos, const char *nome) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(nome, produtos[i].nome) == 0) {
            printf("ID: %d -- %s -- %.2f -- ESTOQUE: %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].qtdEstoque);
            return true;
        }
    }
    return false;
}

void atualizarPreco(Produto *produtos, int qtdProdutos, int id, float novoValor) {
    if (buscarIndicePorId(produtos, qtdProdutos, id) == -1) {
        printf("produto de ID: %d não existe na base de dados", id);
    }

    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) {
            produtos[i].preco = novoValor;
            break;
        }
    }

    printf("produto atualizado com sucesso!");
    buscarPorId(produtos, qtdProdutos, id);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
 
int main() {
    Produto *produtos = NULL;
    int qtdProdutos = 0;

    int op;

    do {
        printf("--- cadastro de produtos ---\n");
        printf("1 - cadastrar novo produto\n");
        printf("2 - listar produtos cadastrados\n");
        printf("3 - buscar produto por id\n");
        printf("4 - buscar produto por nome\n");
        printf("5 - remover produto\n");
        printf("0 - sair");
        scanf("%d", &op);

        switch (op) {
        case 1: {
            limparBuffer();
            
            char nome[MAX_NOME];
            printf("digite o nome: ");
            fgets(nome, MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            float preco;
            printf("digite o preço: ");
            scanf("%f", &preco);

            int qtdEstoque;
            printf("digite a quantidade em estoque: ");
            scanf("%d", &qtdEstoque);

            produtos = cadastrar(produtos, &qtdProdutos, nome, preco, qtdEstoque);
            printf("produto cadastrado com sucesso!\n");
            buscarPorNome(produtos, qtdProdutos, nome);

            break;
        }


        
        default:
            break;
        }

    } while (op != 0);

    return 0;
}