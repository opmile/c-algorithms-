#include <stdio.h>
#include <stdlib.h>

int sumMainDiagonal(int **matrix, int lns, int cols);

int main() {
    int lns = 2;
    int cols = 3;

    int **matrix = malloc(lns * (sizeof(int*)));
    for (int i = 0; i < lns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    int value = 1;
    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    int sum = sumMainDiagonal(matrix, lns, cols);
    printf("a soma da diagonal principal da matriz é: %d\n", sum);

    for (int i = 0; i < lns; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int sumMainDiagonal(int **matrix, int lns, int cols) {
    int sum = 0;

    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}