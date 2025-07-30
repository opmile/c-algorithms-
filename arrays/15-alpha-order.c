#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSortString(char **strs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(strs[j], strs[j + 1]) > 0) {
                char *temp = strs[j];
                strs[j] = strs[j + 1];
                strs[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *strings[] = {
        "banana",
        "abacaxi",
        "laranja",
        "morango",
        "amora",
        "uva",
        "mamão",
        "maçã"
    };
    int n = sizeof(strings) / sizeof(strings[0]);

    bubbleSortString(strings, n);

    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%s", strings[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}