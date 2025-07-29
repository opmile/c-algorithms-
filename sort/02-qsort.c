#include <stdio.h>
#include <stdlib.h>

int compara_pares_impares(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    int par_x = x % 2 == 0;
    int par_y = y % 2 == 0;

    if (par_x && !par_y) return -1; //  se x é par e y é ímpar, x vem antes
    if (!par_x && par_y) return 1; //  se x é ímpar e y é par, x vem depois

    if (par_x && par_y) { // se ambos são pares -> ordem crescente
        if (x > y) return 1;
        if (x < y) return -1;
        return 0;
    }

    if (!par_x && !par_y) { // se ambos são ímpares -> ordem decrescente
        if (x > y) return -1;
        if (x < y) return 1;
        return 0;
    }

    return 0; // casos improváveis
}

int main() {
    int arr[] = {3, 2, 6, 10, 3, 5, 4, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    qsort(arr, n, sizeof(int), compara_pares_impares);
    
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}