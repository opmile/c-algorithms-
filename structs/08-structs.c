#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Pessoa;

// 01 - qsort - usa internamente o algoritmo QuickSort -- MUITO eficiente O(n log n);
int comparar_por_idade(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    // return x - y -- ordena de forma crescente
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
} // se estivessemos recebendo apenas valores inteiros

int comparar_por_idade_struct(const void *a, const void *b) {
    // usando const para indicar que não vamos alterar o conteúdo da struct
    const Pessoa *p1 = (const Pessoa*)a;
    const Pessoa *p2 = (const Pessoa*)b;

    return p1->idade - p2->idade; // ordena de forma crescente
    // p2->idade - p1->idade -- ordena de forma decrescente
}

// 02 - BubbleSort - implementação simples mas pouco eficiente O(n^2)
void bubbleSort(Pessoa *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(p[j].nome, p[j + 1].nome) > 0) { // se o primeiro nome for maior que o segundo
                Pessoa temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    Pessoa pessoas[] = {
        {"bruno", 22},
        {"ana", 18},
        {"matheus", 15},
        {"milena", 19},
        {"felipe", 34},
        {"sienna", 1},
        {"thiago", 38}
    };
    int n = sizeof(pessoas) / sizeof(pessoas[0]);

    bubbleSort(pessoas, n);
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
    }
}