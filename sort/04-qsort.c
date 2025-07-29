/*
queremos ordenar um vetor de Pessoa por idade crescente
a mágina de ordenação sempre vai acontecer na função de comparação
se lembre que a o qsort vai passar valores para a comparação, ponteiros genéricos void* que correspondem aos elementos do array
cabe a você indicar qual o tipo de dado que está sendo recebido para que o qsort faça o trabalho
você deve sempre passar o endereço daquele elemento!

se temos um vetor de inteiros, precisamos passar o endereço do elemento inteiro (int*)
inx x = *(int*)a;
inx y = *(int*)b;

se temos um vetor de strings, precisamos passar o endereço da string (char**)
const char *str1 = *(const char**)a;
const char *str2 = *(const char**)b;

se temos um vetor de struct, precisamos passar o endereço do elemento struct (struct)
const Pessoa *p1 = (const Pessoa*)a;
const Pessoa *p2 = (cosnt Pessoa*)b;
* se lembre que estamos recebendo ponteiros do qsort! podemos sim, usar só p1 e p2, sem ser ponteiros, mas daí estaríamos lendo os dados e acessando a struct inteira do vetor Pessoas (faz uma cópia para a variável p1)
* sem que possível temos que evitar trabalhar com cópias do struct e usar os ponteiros que apontam para a struct isolada

* quando trabalhamos com strings e struct, é bom declarar as variáveis de comparação como const. isso marca que não vamos alterar o conteúdo, vamos apenas comparar os elementos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Pessoa;

int comparar_por_idade(const void *a, const void *b) {
    const Pessoa *p1 = (const Pessoa *)a;
    const Pessoa *p2 = (const Pessoa *)b;

    return p1->idade - p2->idade;
}

int comparar_por_nome(const void *a, const void *b) {
    const Pessoa *p1 = (const Pessoa*)a;
    const Pessoa *p2 = (const Pessoa*)b;

    strcmp(p1->nome, p2->nome);
}

int comparar(const void *a, const void *b) {
    const Pessoa *p1 = (const Pessoa*)a;
    const Pessoa *p2 = (const Pessoa*)b;

    if (p1->idade < p2->idade) return 1;
    if (p1->idade > p2->idade) return -1;
    if (p1->idade == p2->idade) {
        return strcmp(p1->nome, p2->nome);
    }

    return 0;
}

void imprimir_pessoas(Pessoa *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", p[i].nome, p[i].idade);
    }
    printf("\n");
}

int main() {
    Pessoa pessoas[] = {
        {"Alice", 30},
        {"Bruno", 22},
        {"Carla", 40},
        {"Daniel", 25},
        {"Eva", 35},
        {"Fábio", 22}
    };
    int n = sizeof(pessoas) / sizeof(pessoas[0]);
    
    //printf("ordenar por idade\n");
    //qsort(pessoas, n, sizeof(Pessoa), comparar_por_idade);
    //imprimir_pessoas(pessoas, n);

    //printf("ordenar por nome\n");
    //qsort(pessoas, n, sizeof(Pessoa), comparar_por_nome);
    //imprimir_pessoas(pessoas, n);

    qsort(pessoas, n, sizeof(Pessoa), comparar);
    imprimir_pessoas(pessoas, n);
}