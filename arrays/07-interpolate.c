#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *interpolate(int *arr1, int len1, int *arr2, int len2, int *newLen) {
    *newLen = len1 + len2;
    int *result = malloc((*newLen) * sizeof(int));

    int j = 0;
    for (int i = 0; i < *newLen; i++) { // precisamos de um loop para duas incrementações
        result[j++] = arr1[i];
        result[j++] = arr2[i];
    }

    return result;
}

int *interpolateDiffSize(int *arr1, int len1, int *arr2, int len2, int *newLen) {
    *newLen = len1 + len2;
    int *result = malloc((*newLen) * sizeof(int));

    int min = fmin(len1, len2);

    int j = 0;
    for (int i = 0; i < min; i++) {
        result[j++] = arr1[i];
        result[j++] = arr2[i];
    }

    // se arr1 for o maior array
    for (int i = min; i < len1; i++) {
        result[j++] = arr1[i];
    }

    // se arr2 for o maior array
    for (int i = min; i < len2; i++) {
        result[j++] = arr2[i];
    }

    return result;
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}


int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int len = sizeof(arr1) / sizeof(arr1[0]);

    int newLen1;
    int *result1 = interpolate(arr1, len, arr2, len, &newLen1);
    printArr(result1, newLen1);
    free(result1);

    int arr3[] = {1, 3, 5, 7, 9};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    int arr4[] = {2, 4, 6, 8};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);

    int newLen2;
    int *result2 = interpolateDiffSize(arr3, len3, arr4, len4, &newLen2);
    printArr(result2, newLen2);
    free(result2);

    return 0;
}