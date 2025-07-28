#include <stdio.h>
#include <string.h>

void swapNumber(int *arr, int len, int numberTarget, int numberSwap) {
    if (len == 0) return;

    if (arr[0] == numberTarget) {
        arr[0] = numberSwap;
    }

    swapNumber(arr + 1, len - 1, numberTarget, numberSwap);
}

void swapLetter(char *str, int strLen, char target, char swap) {
    if (strLen == 0) return;

    if (str[0] == target) {
        str[0] = swap;
    }

    swapLetter(str + 1, strLen - 1, target, swap);
}

int main() {
    int array[] = {1, 2, 3, 4};
    int len = sizeof(array) / sizeof(array[0]);

    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");

    swapNumber(array, len, 4, 1);

    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");

    char string[] = "sol";
    int strLen = strlen(string);

    printf("%s\n", string);

    swapLetter(string, strLen, 's', 'p');
    swapLetter(string, strLen, 'l', 'o');

    printf("%s\n", string);

    return 0;
}