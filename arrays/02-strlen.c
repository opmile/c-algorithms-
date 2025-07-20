#include <stdio.h>

int stringLength1(char *str);

int stringLength2(char *str);

int main() {
    char *nome = "milena";
    char nome2[] = "milena";
    char nome3[30] = "milena";

    printf("tamanho 1: %d\n", stringLength1(nome));
    printf("tamanho 2: %d\n", stringLength2(nome2));
    printf("tamanho 3: %d\n", stringLength1(nome3));
    
    return 0;
}

int stringLength1(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int stringLength2(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

