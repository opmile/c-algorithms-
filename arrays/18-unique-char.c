#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
com dois loops
o primeiro para avaliar o caractere atual
o segundo para comparar o atual com cada caracter
    o segundo tem que começar em i + 1
        em i por que se começar do início, vai fazer comparações já feitas anteiormente, e também porque em algum momento i = j, e aí na comparação sempre da 0
se com strcmp der 0, o caractere atual não é unico -> false
se não der strcmp, continua iterando até todos os outros caracteres
quando essa iteração terminar, 
*/

bool compareChar(char *str) {
    int len = strlen(str) + 1;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    char str[] = "banana";
    
    if (compareChar(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}