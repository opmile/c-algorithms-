#include <stdio.h>
#include <stdlib.h>

void fill(int **matrix, int lns, int cols);

int main() {
    int lns = 2;
    int cols = 3;
    
    int **matrix = malloc(lns * sizeof(int*));
    for (int i = 0; i < lns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    fill(matrix, lns, cols);

    printf("{\n");
    for (int i = 0; i < lns; i++) {
        printf("  { ");
        for (int j = 0; j < cols; j++) {
            printf("%d", *(*(matrix + i) + j));
            if (j < cols - 1) printf(", ");
        }
        printf(" }%s\n", i < lns - 1 ? "," : ""); 
    }
    printf("}\n");

    for (int i = 0; i < lns; i++) {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
}

void fill(int **matrix, int lns, int cols) {
    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = i + j;
        }
    }
}