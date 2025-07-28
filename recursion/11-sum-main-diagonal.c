#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumArray(int *array, int len) {
    if (len == 0) return 0;

    return array[0] + sumArray(array + 1, len - 1);
}

int sumMainDiagonal1(int **matrix, int lns, int cols) {
    int sum = 0;

    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == matrix[i][i]) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int generateRandom() { // 
    return rand() % 10 + 1; // 1 a 10
}

void fillMatrix(int **matrix, int lns, int cols) {
    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom();
        }
    }
}

void printMatrix(int **matrix, int lns, int cols) {
    printf("{\n");
    for (int i = 0; i < lns; i++) {
        printf("  {");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("}%s\n", (i < lns - 1) ? ", " : "");
    }
    printf("}\n");
}

/*
se a diagonal principal é aquela em que ln = col, então seu elemento estará sempre em matrix[i][i] -> o índice será igual!
a ideia é fixar um índice atual da diagonal e pensar que podemos somar matrix[i][i] com o próximo elemento da janela atual incrementando i a cada chamada recursiva
atingimos o case base quando i == tamanho da matrix (número de linhas)
*/

int sumMainDiagonal2(int **matrix, int n, int i) {
    if (i == n) return 0; // chegamos ao fim 

    return matrix[i][i] + sumMainDiagonal2(matrix + 1, n - 1, i); 
}

int main() {
    srand(time(NULL));
    int lns;
    int cols;

    do {
        printf("crie uma matriz quadrada nxn\n");

        printf("número de linhas: ");
        scanf("%d", &lns);

        printf("número de colunas: ");
        scanf("%d", &cols);

        if (lns != cols) {
            printf("essa não é uma matriz quadrada!\n");
        }

    } while (lns != cols);

    int **matrix = malloc(lns * sizeof(int*));
    if (!matrix) {
        printf("impossível alocar ponteiro externo da matriz");
        return 1;
    }

    for (int i = 0; i < lns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("impossível alocar ponteiro interno %d da matriz", i + 1);
            return 1;
        }
    }

    fillMatrix(matrix, lns, cols);
    printMatrix(matrix, lns, cols);
    int sum = sumMainDiagonal2(matrix, lns, 0); // o primeiro elemento da diagonal principal começa sempre em [0][0]
    printf("soma da diagonal principal: %d\n", sum);

    return 0;
}