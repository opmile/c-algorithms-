#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSort2(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void imprimir(int *arr, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    int arr[] = {5, 2, 6, 1, 3, 7, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    imprimir(arr, n);

    bubbleSort2(arr, n);
    imprimir(arr, n);
    
    return 0;
}