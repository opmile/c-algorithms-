/*
dado um array de structs com int nota, ordene apenas os alunos com nota ≥ 5, mantendo o resto no lugar

quando queremos ordenar somente alguns elementos de um array, o qsort não faz isso sozinho. ele sempre vai assumir que tudo pode ser reordeanado, então precisamos controlar essa sessão fora do comparador

1. definir uma função de comparador comum, que ordena valores inteiros em ordem crescente
    * esse comparador vai receber ponteiros genéricos e convertê-los em ponteiros para struct

2. precisamos criar uma função a parte, que vai extrair apenas os alunos aprovados (nota >=5) com a posição dos seus índices originais
    * precismos primeiro saber quantos foram os alunos aprovados
    * com essa contagem, alocamos memória para o tamanho dos alunos aprovados
    * criamso um vetor auxiliar que carrega as informações dos índices dos alunos aprovados

3. depois de ordenar com qsort precisamos reinserir os elementos (alunos aprovados) em sua nova ordem, e podem os faze isso justamente com os índices guardados

4. lembre-se de liberar a memória alocada

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int nota;
} Aluno;

int compara_por_nota(const void *a, const void *b) {
    const Aluno *a1 = (const Aluno*)a;
    const Aluno *a2 = (const Aluno*)b;

    return a1->nota - a2->nota;
}

void ordenar_por_aprovados(Aluno *alunos, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (alunos[i].nota >= 5) {
            count++;
        }
    }

    Aluno *aprovados = malloc(count * sizeof(Aluno));
    int *indices = malloc(count * sizeof(int));

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (alunos[i].nota >=5) {
            aprovados[j] = alunos[i];
            indices[j] = i;
            j++;
        }
    }

    qsort(aprovados, count, sizeof(Aluno), compara_por_nota);

    for (int i = 0; i < count; i++) {
        alunos[indices[i]] = aprovados[i];
    }

    free(aprovados);
    free(indices);
}

void imprimir_alunos(Aluno *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - nota: %d\n", a[i].nome, a[i].nota);
    }
}

int main() {
    Aluno alunos[] = {
        {"milena", 10},
        {"calos", 3},
        {"joão", 8},
        {"alice", 7},
        {"bruno", 4},
        {"luis", 1},
        {"eduardo", 5}
    };
    int n = sizeof(alunos) / sizeof(alunos[0]);

    imprimir_alunos(alunos, n);
    printf("\n");

    ordenar_por_aprovados(alunos, n);

    imprimir_alunos(alunos, n);
    
    return 0;
}