#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

int *removeDuplicates1(int *arr, int len, int *newLen) {
    // a ideia aqui é armazenar um array temporário de mesmo tamanho do array original (espaço O(n))
    // a variável count guarda, ao final do programa, quantos são os elementos não duplicados
    // usamos dois loops: para cada elemento do array, analisamos se ele tem correspondência com algum dos elementos do array temporário
    // se o elemento atual já está ali, break
    // se ao percorrer todos os elementos não achamos correspondência, então certamente j se tornou igual a count pelas incrementações sucetivas
    // count é fundamental na nossa lógica porque também se comporta como um ponteiro onde escreveremos o próximo elemento do array resultado
    // isso porque sua incrementação é manual, e não faz parte do loop

    int *result = malloc(len * sizeof(int));
    if (!result) {
        printf("não foi possível alocar memória");
        return NULL;
    }
    int count = 0;

    int j;
    for (int i = 0; i < len; i++) {
        for (j = 0; j < count; j++) {
            if (arr[i] == result[j]) {
                break;
            }
        }

        if (j == count) {
            result[count] = arr[i];
            count++;
        }
    }

    int *temp = realloc(result, count * sizeof(int));
    if (!temp) {
        printf("impossível realocar memória");
        return NULL;
    }
    result = temp;

    *newLen = count; // preencher o valor do ponteiro em seu endereço
    return result;
}

int *removeDuplicates2(int *arr, int len, int *outCount) {
    // podemos usar quase a mesma lógica anterior para resolver o problema in-place (espaço O(1))
    // declaramos uma variável pos que servirá como ponteiro para escrever o próximo elemento, além de manter a contagem de quantos são elementos únicos
    // vamos usar dois loops: o elemento atual será comparada com cada um dos outros elementos já checados (j < pos), se for igual, break
    // se não for igual, j se torna igual a contagem de pos, porque percorrermos todos os outros elementos do array e não achamos correspondência
    // o elemento atual agora ocupa a posição pos, e incrementamos pos++ para não sobrescrever na próxima iteração

    int pos = 0;

    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < pos; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }

        if (j == pos) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    int *temp = realloc(arr, pos * sizeof(int));
    if (!temp) {
        printf("impossível realocar array para novo tamanho");
        return NULL;
    }
    arr = temp;

    *outCount = pos;
    return arr;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    int arrDuplicate[] = {1, 1, 2, 3, 1, 2, 2, 3, 4, 5, 1, 2};
    int len = sizeof(arrDuplicate) / sizeof(arrDuplicate[0]);

    printArr(arrDuplicate, len);

    int newLen;
    int *arrNoDuplicates = removeDuplicates1(arrDuplicate, len, &newLen);

    printArr(arrNoDuplicates, newLen);

    printf("\n");

    int len2 = 10;
    int *arrDuplicates2 = malloc(len2 * sizeof(int));
    for (int i = 0; i < len2; i++) {
        arrDuplicates2[i] = generateRandom(1, 4);
    }
    printArr(arrDuplicates2, len2);

    int count;
    int *arrNoDuplicates2 = removeDuplicates2(arrDuplicates2, len2, &count);
    
    printArr(arrNoDuplicates2, count);
    printf("quantidade de elementos únicos: %d\n", count);

    free(arrNoDuplicates2);
    
    return 0;
}