#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) ((x) * (x))

int squareSum(int *arr, int len);

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    printf("a soma dos quadrados de todos os elementos é: %d\n", squareSum(numbers, len));

    return 0;
}

int squareSum(int *arr, int len) {
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += SQUARE(*(arr + i));
    }
    return sum;
}