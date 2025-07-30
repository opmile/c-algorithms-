#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void bubbleSortIdade(Pessoa *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j].idade > p[j + 1].idade) {
                Pessoa temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void bubbleSortString(Pessoa *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(p[j].nome, p[j + 1].nome) > 0) { // ordem alfabética
                Pessoa temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

/*
função de comparação que ordena por múltiplos critérios = 
1. idade
2. nome (quando as idades são iguais)

critério primario
* se positivo, significa que p1 > p2 -> p1 vem depois -- bubble sort vai trocar de posição
* se der negativo p1 < p2 -> p1 vem antes -- não troca!
* se der zero, passa para o critério secundário

critério secundário -- usa a lógica já conhecida com strcmp
* se strcmp(p1->nome, p2->nome) > 0 -> p1 vem depois -- bubble sort vai trocar de posição
* se < 0 -> p1 vem antes -- não troca!
* se der zero, nomes são iguais -- não faz nada
*/
int comparaPessoas(Pessoa *p1, Pessoa *p2) {
    if (p1->idade != p2->idade) {
        return p1->idade - p2->idade; // critério primario
    } else {
        return strcmp(p1->nome, p2->nome); // critério secundário
    }
}

void bubbleSort(Pessoa *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (comparaPessoas(p[j], p[j + 1]) > 0) { // significa que atendeu a algum dos critérios
                Pessoa temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }   
        }
    }
}

void imprimir(Pessoa *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", p[i].nome, p[i].idade);
    }
    printf("\n");
}

int main() {
    Pessoa pessoas[] = {
        {"victor", 23},
        {"milena", 18},
        {"joão pedro", 21},
        {"matheus", 27},
        {"luiza", 19},
        {"ana", 24}
    };
    int n = sizeof(pessoas) / sizeof(pessoas[0]);

    bubbleSortIdade(pessoas, n);
    imprimir(pessoas, n);
    
    bubbleSortString(pessoas, n);
    imprimir(pessoas, n);

    
    
    return 0;
}