#include <stdio.h>
#include <stdlib.h>

/*
para resolver esse exercícios, precisamos partir do entendimento que o total de subarrays gerados em um array n elementos corresposta a:
Σ(n-i) = n + (n-1) + (n-2) + ... + 1 = n * (n+1)/2
isso porque para cada possível índice inicial i temos n-i possíveis subarays começando daqui

1. força bruta - usando ponteiros i, j e k
a ideia parte de fixar índices de partida e chegada, e partir deles, imprimir todos os possíveis valores correspondentes
* i é o índice de partida, e ele pode ir de 0 a n-1, ou seja, percorrer todo o array
* j é o índice de chegada, e ele partirá sempre de i a n-1 marcando o término de cada subarray
* k imprime os elementos do subarray gerado

atenção! no loop de k, devemos garantir que k imprima todos os elementos, e para isso, k deve começar em i e iterar até que k seja MENOR OU IGUAL a j
    * isso porque, caso contrário, como k começa com k = i, quando j == i, o subarray contém apenas um elemento, mas esse subarray não é impresso se a condição de parada do loop for de k < j
*/
void generateSubarrays1(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
        for (int k = i; k <= j; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
  }
}

/*
essa resolução conta com a técnica de recursão como abordagem e ainda sim, usamos uma lógica parecida com a abordagem iterativa
a recursão desse exercício conta com a lógica de efeito colateral, porque a ação de impressão não requere valor de retorno (void)
como a recursão precisa de estado para avançar no passo recursiva, usamos como parâmetros ponteiros os ponteiros de partida e parada
1. caso base -> ponteiro de partida == tamanho do array
    * varremos todos os subarrays disponíveis de modo que a partir das incrementações sucessivas no ponteiro de partida, ele então se tornou equivalente ao tamanho do array 
    * encerramos o passo recursivo

2. se o ponteiro de chegada chegou ao fim do array, ajustamos o ponteiro de partida para a próxima posição e o ponteiro de chegada para uma posição à frente do ponteiro de partida

3. passo recursivo
    iteramos o subarray de parte de i e chega em j em um loop para imprimir cada um de seus elementos
    ao final do loop, o ponteiro de chegada deve ser incrementado para a próxima posição
*/
void generateSubarrays2(int *arr, int len, int start, int end) {
    if (start == len) return; //  se o ponteiro de partida se torna igual ao tamanho do array, encerra o passo recursivo

    if (end == len) { // se ponteiro de chegada se torna igual ao tamanho do array
        // varremos todas as possibilidades de subarrays que começam a partir daquele índice
        generateSubarrays2(arr, len, start + 1, start + 1); // avança as posições dos ponteiros
    }

    else {
        for (int i = start; i < end; i++) { // imprime os subarrays do poteiro de partida ao ponteiro de chegada
            printf("%d ", arr[i]);
        }
        generateSubarrays2(arr, len, start, end + 1); // avança o ponteiro de chegada para sua nova posição em relação ao ponteiro de partida
    }
}

int main() {
    int arr[] = {1, 2, 3};
    generateSubarrays1(arr, 3);


    return 0;
}