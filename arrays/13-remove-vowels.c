#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    

char *removeVowels(char *str) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    int i = 0;
    int pos = 0;

    while (str[i]) {
        bool vowel = false;

        for (int j = 0; j < 5; j++) {
            if (str[i] == vowels[j]) { // se sao iguais
                vowel = true;
                break; //  caractere atual é vogal
            }
        }

        if (!vowel) {
            str[pos] = str[i];
            pos++;
        }

        i++;
    }
    str[pos] = '\0';

    // cppcheck-suppress cstyleCast
    char *temp = (char*)realloc(str, pos);
    if (!temp) return NULL;
    str = temp;

    return str;
}
/*
se lembre! uma string é um array de char que termina com um terminador nulo. as funções da lib padrão dependem desse terminador para saber onde a string acaba
* sempre que modificar uma string ou construir strings manualmente, você é totalmente responsável por colocar o terminador nulo
*/

int main() {
    return 0;
}