#include <stdio.h>
#include <stdlib.h>

void changeToZero(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }
}

/*
1 - duas travessias - tempo O(n), espaço O(1)
* manter um ponteiro de escrita (pos): vai armazenar a contagem de elementos diferentes de zero e indicar onde deve ser escrita o próximo elemento no array
* percorrendo todo o array, devemos analisar se o elemento atual em i é diferente de zero
    * se for diferente de zero, ele deverá ser escrito em pos e pos deve ser incrementado para apontar para a próxima posição do array
    * se for igual a zero, nenhuma escrita será feita e pos permanece no mesmo lugar, armazenando um elemento igual a zero aguardando para ser sobrescrito 
* depois da primeira travessia, todos os elementos diferentes de zero estão sendo armazenados no início 
* na segunda travessia, devemos preencher o que sobrou do array com elementos 0. isso poderá ser feito porque pos agora aponta para onde o primeiro elemento 0 deve ser posto. agora só iteramos até pos ser menor que o tamanho do array
*/
void shiftZeros1(int *arr, int len) {
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    while (pos < len) {
        arr[pos] = 0;
        pos++;
    }

}

/*
2 - uma travessia - tempo O(n), espaço O(1)
muito similar com a ideia de duas travessias, mas agora para eliminar a necessidade de mais uma travessia para preencher com os zeros, implementamos a ideia de troca entre os elementos
* ainda temos o ponteiros de escrita (pos) que armazena a quantidade de números diferentes de zero até o momento e que realiza a sobrescrita de um elemento para aquela posição
* percorrendo o array em uma travessia, o elemento atual i será checado
    * se o elemento atual i for diferente de zero, trocamos ele com pos
    * se o elemento atual i for igual a zero, nenhuma troca será feita
 vai garantir que, se tivermos algum zero em arr[pos], ele será empurrado para o fim do array e não será sobrescrito
ex)
int[] arr = {1, 2, 0, 4, 3, 0, 5, 0};
int pos = 0;

como arr[0] = 1, trocar(arr[pos], arr[i]) = trocar(arr[0], arr[0])
incrementamos pos para 1

como arr[1] = 2, trocar(arr[pos], arr[i]) = trocar(arr[1], arr[1])
incrementamos pos para 2

como arr[2] = 0, nenhuma troca será feita
pos permanece em 2

como arr[3] = 4, trocar(arr[pos], arr[i]) = trocar(arr[2], arr[3])
incrementamos pos para 3

como arr[4] = 3, trocar(arr[pos], arr[i]) = trocar(arr[3], arr[4])
incrementamos pos para 4

como arr[5] = 0, nenhuma troca será feita
pos permanece em 4

como arr[6] = 5, trocar(arr[pos], arr[i]) = trocar(arr[4], arr[6])
incrementamos pos para 5

como arr[7] = 0, nenhuma troca é feita
pos permanece em 5
*/
void shiftZeros2(int *arr, int len) {
    int pos = 0;
    
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = arr[pos];

            pos++;
        }
    }
}

int main() {
    return 0;
}