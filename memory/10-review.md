## **crie um sistema de listas dinâmicas em 2D:**
   * comece com uma matriz `n x m` inicial.
   * o usuário pode:

     * adicionar linhas (`realloc` do ponteiro externo).
     * adicionar colunas em uma linha específica (`realloc` do ponteiro interno).
   * sempre que a matriz mudar, imprima o novo estado.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom() {
    return rand() % 10; // 0 a 10;
}

int **addLns(int **matrix, int *lns, int cols, int add) {
    newLns = *lns + add;

    // realocar o tamanho da matriz para comportar + add linhas
    // os ponteiros criados a mais devem ser inicializados
    // devemos preencher o novo espaço da matriz do espaço já preenchido ao espaço não preenchido

    int **temp = realloc(matrix, newLns * sizeof(int*));
    if (!temp) {
        printf("não foi possível realocar matrix");
        return;
    }
    matrix = temp;

    for (int i = *lns; i < newLns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("não foi possível alocar memória para a linha %d\n", i);
            continue;
        }

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom();
        }
    }

    *lns = newLns; // atualiza o numero de linhas
    return matrix; // retorna o ponteiro caso o realloc mudou o endereço
}

void addCols(int **matrix, int lns, int *cols, int add) {
    int newCols = cols + add;

    // realocar espaço para comportar mais + add elementos para cada linha
    // como os ponteiros já foram inicializados, só precisamos preencher do espaço não preenchido ao espaço preenchido

    for (int i = 0; i < lns; i++) { //  para cada linha
        int *temp = realloc(matrix[i], newCols * sizeof(int));
        if (!temp) {
            printf("não foi possível alocar memória para a linha %d\n", i);
            continue;
        }
        matrix[i] = temp;

        for (int j = *cols; j < newCols; j++) {
            matrix[i][j] = generateRandom();
        }
    }

    *cols = newCols;
}

int main() {
    srand(time(NULL));
    
    return 0;
}

````