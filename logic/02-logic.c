#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
criar um novo array para armazenar os elementos únicos que tem seu próprio valor de tamanho

percorrer todo o array com dois loops
o primeiro corresponde a analise do elemento atual
o segundo corresponde a analise dos elementos que já foram inseridos dentro do array de elmentos únicos
nesse segundo loop, analisamos a correspondência entre o elemento atual e todos os outros elementos já inserido no array
    se bater e forem iguais, o elemento atual é um elemento duplicado que não deve ser inserido no novo array. depois disso, temos que dar break porque já analisamos a correspondência do atual e já sabemos que é duplicado
    se não bater, significa que o elemento atual é um elemento único que deve ser inserido no array. 
        aqui devemos realocar memória dinamicamente para comportar mais um elemento, depois, adicionar o elemento atual na última posição do array e incrementar a frequencia de tamanho
        devemos atualizar o ponteiro que aponta pro tamanho atual do array com o tamanho dos elementos únicos
ao final, teremos um novo array com os elementos únicos
*/

int *removeDuplicates(int *arr, int *len) {
    int *uniques = NULL;
    int newLen = 0;

    bool found = false;

    for (int i = 0; i < *len; i++) {
        for (int j = 0; j < newLen; j++) {
            if (arr[i] == uniques[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            // cppcheck-suppress cstyleCast
            int *temp = (int*)realloc(uniques, sizeof(int));
            if (!temp) {
                printf("não foi possível realocar memória!");
                return NULL;
            }
            uniques = temp;

            uniques[newLen] = arr[i];
            newLen++;
        }
    }
    *len = newLen;
    return uniques;
}

int main() {
    return 0;
}