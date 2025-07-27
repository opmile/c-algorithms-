#include <stdio.h>

// dado um array de inteiros e um valor `x`, retorne o índice da primeira ocorrência
/*
1. caso base 1
    if (len == 0) return -1;

    se o comprimento chegou a 0, significa que não há mais elementos apra analisar e isso só pode acontecer quando a busca linear não achou o número e esse array está vazio

2. case base 2 -  verifica se x está na primeira posição do array atual
    if (arr[0] == x) return 0;

    se o número que estamos procurando está logo na primeira posição, encontramos o índice - só que relativo ao array atual
    retornamos 0 pois x está no índice 0 desse trecho do array

3. passo recursivo - não achou aqui? recorre ao restante do array
    int index = searchForX(arr + 1, len - 1, x);
    * chamada recursiva:
        arr + 1 -> o array a partir do próximo elemento relativo a sua posição atual
        len - 1 -> pois o agora o array analisado tem um elemento a menos
    se não encontramos o x em arr[0], verificamos se ele aparece em algum lugar no restando do array

4. tratamento do resultado recursivo
    if (index == -1) return -1;
    else return index + 1;

    se ela retornou -1, quer dizer que já percorremos todo o array, ele agora está vazio e mesmo assim não achamos nenhuma correspodência com x
    se ela retornou algum índice k, então
        * k é relativo ao subarray que começava em arr + 1
        * para que ele seja relativo ao array original, precisamos somar 1, porque o subarray que consultamos estava deslocado em uma posição
        quando acharmos o valor as funções começam a desempilhar com retorno, cada chamada vai precisar somar +1 ao que recebeu debaixo para reconstruir o índice do array original
*/

int searchForX(int *arr, int len, int x) {
    if (len == 0) return -1; // não encontrou o elemento
    if (arr[0] == x) return 0;

    int index = searchForX(arr + 1, len - 1, x);
    if (index == -1) return -1;
    return index + 1; // ajusta o índice à posição relativa original
}

int main() {
    return 0;
}