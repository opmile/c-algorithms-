#include <stdio.h>
#include <stdlib.h>

/*
a lista encadeada funciona como uma sequência de blocos, onde cada bloco aponta para o próximo
* o primeiro elemento é o início da lista
* cada elemento sabe apeas que vem depois dele
* o último elemento aponta para NULL
*/


typedef struct {
    int valor;
    Elemento *prox; // ponteiro que aponta para o próximo elemento da lista
} Elemento;

/*
1. criar um novo nó (malloc)
2. colocar o valor dentro dele
3. se a lista estiver vazia (*elementos == NULL), esse nó deve virar o primeiro elemento da lista
4. se não, percorrer até o fim e colocar esse nó no final
*/

// precisamos passar o endereço da lista porque ela pode alterar o ponteiro do primeiro elemento (caso a lista esteja vazia)
// Elemento* representa um nó, Elemento** representa a própria lista
void inserirFinal(Elemento **elementos, int valor) {
    Elemento *novo = malloc(sizeof(Elemento));
    if (!novo) {
        printf("erro de alocação\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (!(*elementos)) {
        *elementos = novo;
    } else {
        Elemento *atual = *elementos;
        while (atual->prox != NULL) {
            atual = atual->prox; // vai até o fim
        }
        atual->prox = novo;
    }
}

void imprimirLista(Elemento *elementos) {
    Elemento *atual = elementos;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}