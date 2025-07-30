#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_TITULO 50

typedef struct {
    char titulo[MAX_TITULO];
} Livro;

// uso da ténica sliding window
// frase e palavra são ponteiros que apontam para o primeiro caractere de um array de char

bool contemPalavra(const char *frase, const char *palavra) {
    while (*frase) {
        const char *p1 = frase; // ponteiro que aponta para a frase 
        const char *p2 = palavra; // ponteiro que aponta para a palavra

        // enquanto frase e palavra não chegaram ao terminador nulo e foram iguais
        while (*p1 && *p2 && tolower(*p1) == tolower(*p2)) { // garante case insensitive
            p1++;
            p2++; // avança os ponteiros
        }

        if (*p2 == '\0') { // se p2 chegou ao fim, significa correspondencia exata
            return true;
        }

        frase++; // se não achou correspondencia, move para o proximo caractere da frase
    }
    return false;
}

void buscarPalavra(Livro *livros, int totalLivros, const char *chave) {
    printf("Livros com \"%s\" no título: \n", chave);

    int j = 1;
    for (int i = 0; i < totalLivros; i++) {
        if (contemPalavra(livros[i].titulo, chave)) {
            printf("%d. %s\n", j++, livros[i].titulo);
        }
    }
}

int main() {
    Livro livros[] = {
        {"Algoritmos em C"},
        {"Estruturas de Dados"},
        {"Introdução aos Algoritmos"},
        {"Programação em Python"},
        {"O Algoritmo da Vida"},
        {"Teoria dos Grafos"}
    };
    int n = sizeof(livros) / sizeof(livros[0]);

    char chave[MAX_TITULO];
    printf("digite a chave de busca: ");
    fgets(chave, MAX_TITULO, stdin);
    chave[strcspn(chave, "\n")] = '\0';

    buscarPalavra(livros, n, chave);
    
    return 0;
}