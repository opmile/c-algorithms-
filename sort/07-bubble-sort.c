#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ordenar_pares(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) count++;
    }

    int *pares = malloc(count * sizeof(int));
    int *indices = malloc(count *sizeof(int));

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            pares[j] = arr[i];
            indices[j] = i;
            j++;
        }
    }

    bubbleSort(pares, count);

    for (int i = 0; i < count; i++) {
        arr[indices[i]] = pares[i];
    }

    free(pares);
    free(indices);
}

int main() {
    int arr[] = {1, 8, 4, 3, 5, 1, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    ordenar_pares(arr, n);

    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}