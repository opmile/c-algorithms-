#include <stdio.h>
#include <stdlib.h>

// é uma matriz de permutação se em cada linha e em cada coluna tenha-se n-1 elementos nulos e um elemento igual a 1

/*
para conferir se uma matriz é de permutação, temos que varrer a matriz em dois sentidos: em suas linhas, e em suas colunas
* na primeira, o loop maior percorre pelas linhas e o loop menor percorre pelas colunas
* na segunda, o loop maior percorre pelas colunas e o loop menos percorre pelas linhas
*/

int **cria_matrix(int n) {
    // cppcheck-suppress cstyleCast
    int **matriz = (int**)malloc(n * sizeof(int*));
    if (!matriz) {
        printf("impossível alocar memória para linhas da matriz");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        // cppcheck-suppress cstyleCast
        matriz[i] = (int*)malloc(n * sizeof(int));
        if (!matriz[i]) {
            printf("impossível alocar memória para colunas da matriz");
            return NULL;
        }
    }

    return matriz;
}

void destroi_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}


int somaMatrix(int **matriz, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matriz[i][j];
        }
    }
    return sum;
}


int verificaPermutacao(int **matriz, int n, int *soma) {
    // imprime a dimensão
    printf("%d\n", n);

    // verificar as linhas
    for (int i = 0; i < n; i++) {
        int count1 = 0;
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                count1++;
            } else if (matriz[i][j] != 0) {
                printf("NAO E PERMUTACAO");
                *soma = somaMatrix(matriz, n);
                printf("%d\n", *soma);

                return 0;
            }
        }
        if (count1 != 1) {
            printf("NAO E PERMUTACAO");
            *soma = somaMatrix(matriz, n);
            printf("%d\n", *soma);

            return 0;
        }
    }


    // verifica as colunas
    for (int j = 0; j < n; j++) {
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (matriz[i][j] == 1) {
                count1++;
            } else if (matriz[i][j] != 0) {
                printf("NAO E PERMUTACAO");
                *soma = somaMatrix(matriz, n);
                printf("%d\n", *soma);

                return 0;
            }
        }
        if (count1 != 1) {
            printf("NAO E PERMUTACAO");
            *soma = somaMatrix(matriz, n);
            printf("%d\n", *soma);    

            return 0;
        }
    }

    printf("PERMUTACAO\n");

    // imprime  a soma
    *soma = somaMatrix(matriz, n);
    printf("%d\n", *soma);

    return 1;
}

