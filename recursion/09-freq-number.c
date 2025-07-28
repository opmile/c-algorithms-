#include <stdio.h>
#include <stdlib.h>

// contar as ocorrencias de um numero
int countOccurrences(int arr, int len, int x) {
    if (len == 0) return 0;

    int count = (arr[0] == x) ? 1 : 0;
    return count + countOccurrences(arr + 1, len - 1, x);
}

// contar e apontar o índice das ocorrências de um número no vetor
/*
a chave desse exercício é entender que podemos usar a contagem para determinar o tamanho do vetor dinâmico e, a cada correspondência, incrementamos a variável de modo que ela agora corresponde ao novo tamanho a ser realocado

arr: vetor original
idx: índice atual no vetor
len: tamanho total
x: valor buscado
out: vetor dinâmico de índices (realocado conforme necessário)
count: ponteiro que armazena a quantidade de vezes que x foi encontrado

caso base: se o índice atual no vetor chegou ao tamanho do array -> significa que já percorreos todo o array

caso normal: verifica que o elemento que ocupa o idx atual é igual a x
    se achamos correspondencia
        incrementamos a contagem
        realocamos o vetor de índices para comportar o novo valor da contagem
        com a contagem atualizada ela agora corresponde ao novo tamanho do vetor
        o elemento que ocupa a ultima posição desse vetor (que está em count - 1) é igual ao índice atual do vetor idx
    
    chamada recursiva: o único estado que muda é o incremento do índice atual idx 

*/
void findIndices(int *arr, int idx, int len, int x, int **out, int *count) {
    if (idx == len) return;

    if (arr[idx] == x) {
        (*count)++; // se encontramos x, incrementa o contador
        int *temp = realloc(*out, (*count) * sizeof(int));
        if (!temp) {
            printf("erro de alocação\n");
            exit(1);
        }
        *out = temp;
        (*out)[(*count) - 1] = idx; // salva o indice
    }

    findIndices(arr, idx + 1, len, x, out, count);
}

/*
essa função é uma interface limpa (função principal) para o usuário usar sem se preocuapr com ponteiro duplo, contador ou índice atual
ou seja: ela esconde a bagunça de alteração do estado da recursão (que muitas vezes precisa de muitos parâmetros) e te entrega tudo pronto
*/
int *getAllIndices(int *arr, int len, int x, int *count) {
    int *indices = NULL;
    *count = 0;

    findIndices(arr, 0, len, x, indices, count);

    return indices;
}

int main() {
    return 0;
}