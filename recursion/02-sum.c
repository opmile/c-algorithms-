#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int n); // 01
int sumArr(int *arr, int len); // 02
int sumEvenArr(int *arr, int len); // 03
int randomNumber(int min, int max);

int main() {
    // 01
    int number = 5;
    printf("soma dos números formados pelo intervalo de 0 a %d é: %d\n", number, sum(number));

    // 02
    int nums[] = {1, 5, 10, 15, 20};
    int len = sizeof(nums) / sizeof(nums[0]);
    printf("a soma dos elementos do vetor (recursivamente) é: %d\n", sumArr(nums, len));

    // 03
    int numsEven[] = {1, 2, 3, 4, 5, 6, 7};
    int lenEven = sizeof(numsEven) / sizeof(numsEven[0]);
    printf("a soma dos elementos pares do vetor é: %d\n", sumEvenArr(numsEven, lenEven));

    // 04
    srand(time(NULL));

    int n;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("não foi possível alocar espaço dinâmico");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        *(arr + i) = randomNumber(0, 10);
    }

    printf("vetor alocado dinamicamente: \n");
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", *(arr + i));
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    printf("soma dos elementos do vetor dinâmico: %d\n", sumArr(arr, n));
    printf("soma dos elementos pares do vetor dinâmico: %d\n", sumEvenArr(arr, n));


    return 0;
}

int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}

int sumArr(int *arr, int len) {
    if (len == 0) {
        return 0;
    } else {
        return arr[0] + sumArr(arr + 1, len - 1);
    }
}

/*
decompor o vetor até o tamanho ser 0 (caso base), e ir somando elemento por elemento na volta da recursão
* caso base: se tamanho == 0, a soma é 0
* passo recursivo: arr[0] + sumArr(arr + 1, len - 1)

arr[0] é o primeiro elemento da "visão atual" do vetor: elemento atual que está sendo somado naquele nível da recursão
pense em arr como uma janela móvel que enxerga apenas um pedaço do vetor original

a cada passo recursiva:
* a função pega o primeiro valor visível (vet[0])
* e chama recursivamente a mesma função para o resto do vetor (vet + 1)
*/

int sumEvenArr(int *arr, int len) {
    if (len == 0) {
        return 0;
    } 

    if (arr[0] % 2 == 0) {
        return arr[0] + sumEvenArr(arr + 1, len - 1);
    }
    return sumEvenArr(arr + 1, len - 1);
}

int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}