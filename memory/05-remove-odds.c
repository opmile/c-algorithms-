#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int removeOdds(int *arr, int len);

bool isEven(int num);

void printArr(int *arr, int len);

int main() {
    
    int len = 6;
    int* arr = malloc(len * sizeof(int));

    int value = 1;
    for (int i = 0; i < len; i++) {
        arr[i] = value++;
    }

    printArr(arr, len);

    int newLen = removeOdds(arr, len); // sacada de mestre!

    printArr(arr, newLen);

    free(arr);
    
    return 0;
}

bool isEven(int num) {
    if (num % 2 == 0) {
        return true;
    }
    return false;
}

int removeOdds(int *arr, int len) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (isEven(arr[i])) {
            arr[count++] = arr[i];
        }
    }
    arr = realloc(arr, count * sizeof(int));
    return count; // forçar a função a retornar o novo tamanho
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", *(arr + i));
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}