#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int min, int max);

void printArr(int *arr, int len);

int main() {
    srand(time(NULL));

    int len = 4;
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        *(arr + i) = generateRandom(0, 100);
    }

    printArr(arr, len);

    arr = realloc(arr, 2 * len * sizeof(int));

    int j = len;
    while (j < 2 * len) {
        *(arr + j) = -1;
        j++;
    }

    printArr(arr, 2 * len);

    free(arr);
    return 0;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", *(arr + i));
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}