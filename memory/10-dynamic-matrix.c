#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int min, int max);
void fillMatrix(int **matrix, int lns, int cols);
void printMatrix(int **matrix, int lns, int cols);

int **addLns(int **matrix, int *lns, int cols, int add);
void addCols(int **matrix, int lns, int *cols, int add);

int main() {
    srand(time(NULL));

    int lns;
    printf("digite o número de linhas da matriz: ");
    scanf("%d", &lns);

    int cols;
    printf("digite o número de colunas da matriz: ");
    scanf("%d", &cols);

    int **matrix = malloc(lns * sizeof(int*));
    for (int i = 0; i < lns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    fillMatrix(matrix, lns, cols);
    printMatrix(matrix, lns, cols);

    int op;
    do {
        printf("1 - adicionar linhas\n");
        printf("2 - adicionar colunas\n");
        printf("3 - imprimir matriz\n");
        printf("0 - sair\n");
        scanf("%d", &op);

        switch (op) {
        case 1: {
            int addNewLines;
            printf("digite quantas linhas deseja adicionar: ");
            scanf("%d", &addNewLines);

            // não podemos ignorar o novo ponteiro que realloc pode ter retornado
            matrix = addLns(matrix, &lns, cols, addNewLines); 
            // não fazer isso implica que matrix do main() continue apontando para o antigo bloco de memória

            break;
        }
        case 2: {
            int addNewCols;
            printf("digite quantas colunas deseja adicionar: ");
            scanf("%d", &addNewCols);

            addCols(matrix, lns, &cols, addNewCols);

            break;
        }
        case 3: 
            printMatrix(matrix, lns, cols);
            break;
        
        case 0: 
            printf("encerrando...\n");
            break;
        
        default:
            printf("opção inválida");
            break;
        }
    } while (op != 0);

    for (int i = 0; i < lns; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fillMatrix(int **matrix, int lns, int cols) {
    for (int i = 0; i < lns; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom(0, 10);
        }
    }
}

void printMatrix(int **matrix, int lns, int cols) {
    printf("{\n");
    for (int i = 0; i < lns; i++) {
        printf("  { ");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf(" }%s\n", i < lns - 1 ? ", " : "");
    }
    printf("}\n");
}

int **addLns(int **matrix, int *lns, int cols, int add) {
    int newLns = *lns + add;

    int **temp = realloc(matrix, newLns * sizeof(int*));
    if (!temp) {
        printf("não foi possível realocar memória para as novas linhas");
        return matrix;
    }
    matrix = temp;

    for (int i = *lns; i < newLns; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("não foi possível alocar memória para a linhas %d\n", i);
            continue;
        }

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom(0, 10);
        }
    }

    *lns = newLns;
    printMatrix(matrix, *lns, cols);
    return matrix;
}

void addCols(int **matrix, int lns, int *cols, int add) {
    int newCols = *cols + add;

    for (int i = 0; i < lns; i++) {
        int *temp = realloc(matrix[i], newCols * sizeof(int));
        if (!temp) {
            printf("não foi possível realocar linha %d\n", i);
            continue;
        }
        matrix[i] = temp;

        for (int j = *cols; j < newCols; j++) {
            matrix[i][j] = generateRandom(0, 10);
        }
    }

    *cols = newCols;
    printMatrix(matrix, lns, *cols);
}

/*
cuidados:

1. diferenças entre int** e void das funções
addLns() precisa retornar a matrix porque você está realocando o ponteiro externo (ou seja, o vetor de ponteiros)
    * nessa realocação o endereço principal do vetor de linhas pode mudar
    * matrix pode agora apontar para outro lugar depois do ralloc
    * não retornar esse novo endereço no main vai fazer o main() segurar um ponteiro antigo - que agora pode estar inválido

addCols() cada linha é realocada individualmente
    * cada matrix[i] é realocado individualmente
    * como matrix já é um ponteiro para ponteiros, ele já permite acesso e alteração das linhas diretamente
    * logo, você não precisa retornar a matriz, pois o ponteiro matrix em si não mudou de endereço, só os inteiros mudaram (e esses você já está acessando diretamente)

2. o loop não pode iterar para preencher toda a matrix novamente! 
ele precisa iterar da posição preenchida para a posição não preenchida
* for (int i = lns; i < newLns; i++) e for (int j = cols, j < newCols; j++)

3. quando adicionamos novas linhas, precisamos alocar memória para cada nova linha antes de escrever nela! isso porque antes da alocação, ela é apenas um ponteiro apontando para lugar nenhum!
* operamos da mesma forma quando estamos criando uma matriz dinâmica

4. usamos ponteiros para lns e cols como parâmetros da função!
porque queremos que a função consifa modificar o número de linhas (lns) e colunas (cols) fora da função
* em C os parâmetros são passados por valor - ou seja, uma cópia! se você passase int lns ou int cols, qualquer modficiação interna não afetaria o valor original no main()

*/