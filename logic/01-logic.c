#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
agrupar os elementos de um array por frequência em ordem decrescente

primeiro, teremos que agrupar os valores com um struct Frequencia, que tem os campos valor, que indica o valor único do array, e a frequência que esse valor aparece 

a função de agrupagem funciona da seguinte forma:
vamos fazer uma verificação para cada elemento do array a partir de dois loops
o primeiro itera sobre os elementos do array, e indica o elemento atual de comparação
o segundo itera sobre um array de Frequencia, criado para armazenar os valores únicos, e analisa correspondência entre o elemento atual e cada um dos elementos unicos já inseridos no array de frequencias
    se houver corrspondência entre os elementos, esse valor único já foi inserido no array, então agora só devemos incrementar o valor de frequencia daquele numero. também precisamos dar break no segundo loop porque já achamos a correspondência do valor atual
    se não houver correspondência entre os elementos, esse valor único deve ser inserido na última posição do array, fazendo a devida atribuição do valor e indicando a frequência a partir do controle com uma variável auxiliar que indica quantos elementos unicos já foram adicionados. ao final, incremente!

depois de agrupar os elementos únicos, ordenamos com qsort e é aí que entra nossa função de comparação, que recebe dois ponteiros de Frequência
    como queremos que o número de maior frequência apareça primeiro, ordenamos pela frequencia em ordem crescente 
    se a frequência for a mesma, ordenamos por valor em ordem crescente

em seguida, reiserimos os elementos de volta no array original
*/

typedef struct {
    int valor;
    int freq;
} Frequencia;

int compara_frequencia(const void *a, const void *b) {
    // cppcheck-suppress cstyleCast
    const Frequencia *fa = (Frequencia*)a;
    // cppcheck-suppress cstyleCast
    const Frequencia *fb = (Frequencia*)b;

    if (fa->freq != fb->freq) {
        return fb->freq - fa->freq;
    } else {
        return fa->valor - fa->valor;
    }
    return 0;
}

void agrupaPorFrequencia(int *arr, int len) {
    Frequencia *frequencias = NULL;
    int lenFreq = 0;
    
    bool found = false;

    for (int i = 0; i < len; i++) {

        for (int j = 0; j < lenFreq; j++) {
            if (arr[i] == frequencias[j].valor) {
                found = true;
                frequencias[j].freq++;
                break;
            }
        }

        if (!found) {
            // cppcheck-suppress cstyleCast
            Frequencia *temp = (Frequencia*)realloc(frequencias, (lenFreq + 1) * sizeof(Frequencia));
            if (!temp) {
                printf("não foi possível realocar memória");
                return;
            }
            frequencias = temp;

            frequencias[lenFreq].valor = arr[i];
            frequencias[lenFreq].freq = 1;
            lenFreq++;
        }
    }

    qsort(frequencias, lenFreq, sizeof(Frequencia), compara_frequencia);

    int index = 0;
    for (int i = 0; i < lenFreq; i++) {
        for (int j = 0; j < frequencias[i].freq; j++) {
            arr[index++] = frequencias[i].valor;
        }
    }

    free(frequencias);
}

int main() {
    return 0;
}