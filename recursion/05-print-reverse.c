/*
aqui é essencial entender a alma da recursão: o jeito como o programa empilha chamadas até o fundo e só depois começa a executar "de fato" o que vem após a chamada recursiva

quando você chama uma função recursivamente, o compilador guarda todas essas chamadas em uma pilha de execução (call stack)
cada vez que a função chama a si mesma, ela ainda não terminou sua execução, e fica esperando o retorno da nova chamada para continuar
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int min, int max);
void printArr(int *arr, int len);
void printReverse(int *arr, int len);
void printSecondHalf(int *arr, int len);

int main() {
    srand(time(NULL));

    int len;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &len);
    int *arr = malloc(len * sizeof(int));
    
    for (int i = 0; i < len; i++) {
        *(arr + i) = generateRandom(1, 10);
    }

    printArr(arr, len);

    printReverse(arr, len);
    printf("\n");
    printSecondHalf(arr, len);

    return 0;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", *(arr + i));
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

void printReverse(int *arr, int len) {
    if (len == 0) {
        return;
    }
    printReverse(arr + 1, len - 1);
    
    printf("%d ", arr[0]);
}

/*
vetor {1, 2, 3}

execução:
1. primeira chamada: 
arr = {1, 2, 3}, len = 3
chama printReverse({2, 3}, 2) e espera

2. segunda chamada
arr = {2, 3}, len = 2
chama printReverse({3}, 1) e espera

3. terceira chamada
arr = {3}, len = 1
chama printReverse({}, 0) e espera

4. quarta chamada 
len == 0 -> caso base, retorna imediatamente
agora a pilha começa a voltar recursivamente e as funções vão sendo desempilhadas
--

5. terceira chamada continua 
arr = {3}, agora imprime arr[0] = 3

6. segunda chamada continua
arr = {2, 3}, imprime arr[0] = 2

7. primeira chamada continua
arr = {1, 2, 3}, imprime arr[0] = 1

arr[0] funciona quando cada chamada recebe um ponteiro diferente porque arr + 1 a cada passo, então a cada chamada ele aponta para um elemento diferente
* arr = &array[0] → arr[0] = 1
* arr = &array[1] → arr[0] = 2
* arr = &array[2] → arr[0] = 3
ou seja, você sempre imprime o elemento atual da versão local do vetor da chamada, na ordem inversa, porque a impressão só acontece na volta da recursão
*/

void printSecondHalf(int *arr, int len) {
    if (len == 0) return;

    int half = len / 2;
    printReverse(arr + half, len - half);
}