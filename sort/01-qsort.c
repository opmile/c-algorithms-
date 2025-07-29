#include <stdio.h>
#include <stdlib.h>

void imprimirInt(int *arr, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}

void imprimirFloat(float *arr, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%.1f", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}

int compara_int_crescente(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    
    return x - y;
}

int compara_float_decrescente(const void *a, const void *b) {
    float x = *(float*)a;
    float y = *(float*)b;

    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int compara_char(const void *a, const void *b) {
    char x = *(char*)a;
    char y = *(char*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int arrInt[] = {5, 2, 1, 6, 4, 8, 3, 9};
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);

    imprimirInt(arrInt, nInt);
    qsort(arrInt, nInt, sizeof(int), compara_int_crescente);
    imprimirInt(arrInt, nInt);

    float arrFloat[] = {8.5, 5.5, 5.1, 6.2, 7.9, 8.2, 4.3, 2.7, 9.9};
    int nFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);

    imprimirFloat(arrFloat, nFloat);
    qsort(arrFloat, nFloat, sizeof(float), compara_float_decrescente);
    imprimirFloat(arrFloat, nFloat);

    char caracteres[] = {'b', 'f', 'j', 'm', 'a', 'e', 'k'};
    int nChar = sizeof(caracteres) / sizeof(caracteres[0]);

    printf("%s\n", caracteres);
    qsort(caracteres, nChar, sizeof(char), compara_char);
    printf("%s\n", caracteres);

    return 0;
}