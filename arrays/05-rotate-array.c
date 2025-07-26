/*
rotacionar um array significa mover os elementos da sua posição original para uma nova posição de forma circular
* rotação para direita -> clockwise (sentido horário)
* rotação para esquerda -> counter clockwise (sentido anti-horário)

adotando a implementação de melhor análise assintótica:
algoritmo de reversão com tempo O(n) e espaço O(1)
* tipo de solução in-place

para direita:
* inverte os últimos d elementos
* inverte os primeiros n - d elementos
* inverte todo o array 
aqui invertemos os últimos elementos para gerar o efeito horário 

para esquerda:
* inverte os primeiros d elementos
* inverte os últimos n - d elementos
* inverte todo o array
aqui invertemos os primeiros elementos para gerar o efeito anti-horário

OBS
* rotação à direita permite duas ordens de reversão válidas (tudo por último ou tudo primeiro)
* rotação à esquerda só permite uma (tudo por último) -> problema de simetria
    * ao inverter todo o array você quebra a localização natural do ponte de ponte (d)
    * na rotação à esquerda, o ponto de corte está no início do array, então inverter tudo bagunça esse corte irreversivelmente
    * na rotação à direita, o ponto de corte está no fim do array, mesmo que você inverta tudo, o ponto de corte ainda está "alinhado" com o que você precisa separar
*/
#include <stdio.h>

void reverse(int *arr, int len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void reverseFrom(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotateRight(int *arr, int len, int d) {
    if (d <= 0) return;
    d %= len;

    /* 
    invertendo tudo por último: 
    reverseFrom(arr, len - d, len - 1);
    reverseFrom(arr, 0, len - d - 1);
    reverseFrom(arr, 0, len - 1);
    */

    // invertendo tudo primeiro: 
    reverseFrom(arr, 0, len - 1);
    reverseFrom(arr, 0, d - 1); // inverte os primeiros d elementos primeiro
    reverseFrom(arr, d, len - 1); // inverte os últimos
    
}

void rotateLeft(int *arr, int len, int d) {
    if (d <= 0) return;
    d %= len;

    // sempre inverter tudo por último (ponto de corte no começo)
    reverseFrom(arr, 0, d - 1);
    reverseFrom(arr, d, len - 1);
    reverseFrom(arr, 0, len - 1);
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, len);

    //rotateRight(arr, len, 2);
    rotateLeft(arr, len, 2);

    printArr(arr, len);

    return 0;
}