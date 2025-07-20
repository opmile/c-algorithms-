#include <stdio.h>
#include <stdlib.h>

int* cloneArr(int *arr, int len);

int main() {
    int len = 10;
    int *arr = malloc(len * sizeof(int));

    int value = 1;
    for (int i = 0; i < len; i++) {
        *(arr + i) = value++;
    }

    int *clone = cloneArr(arr, len);

    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", *(clone + i));
        if (i < len - 1) printf(", ");
    }
    printf("}\n");

    free(arr);
    free(clone);

    return 0;
}

int* cloneArr(int *arr, int len) {
    int *clone = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        *(clone + i) = *(arr + i);
    }
    return clone;
}