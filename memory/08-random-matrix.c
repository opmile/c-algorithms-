#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandom(int min, int max);

void printMatrix(int **matrix, int lns, int cols);

int main() {
    srand(time(NULL));

    int lns;
    int cols;

    printf("digite o número de linhas: ");
    scanf("%d", &lns);

    getchar();

    printf("digite o número de colunas: ");
    scanf("%d", &cols);

    int **matrix = malloc(lns * sizeof(int*));

    for (int i = 0; i < lns; i++) {
        matrix[i] = malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom(0, 100);
        }
    }

    printMatrix(matrix, lns, cols);

    for (int i = 0; i < lns; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printMatrix(int **matrix, int lns, int cols) {
    printf("{\n");
    for (int i = 0; i < lns; i++) {
        printf("  { ");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf(" }%s\n", i < lns - 1 ? "," : "");
    }
    printf("}\n");
}