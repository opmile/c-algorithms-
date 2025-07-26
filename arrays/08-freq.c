#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
força bruta = tempo (On^2) e espaço O(n):
* devolveremos um ponteiro para ponteiro para estruturar uma matriz dinâmica em que cada linha corresponde a um array com o elemento único seguido da sua frequência 
    * para isso, devemos começar definindo o ponteiro de ponteiro no início da função, 
* iteramos o array de inteiros em um loop e para cada elemento, devemos checar se ele já foi conferido/contado em iterações anteriores
* faremos isso com um array de elementos booleanos checked (todos começam com false) para manter controle se o número naquela posição já foi checado
    * nesse ponto, também precisaremos de uma variável de contagem, para manter controle da frequência de elementos que aparecem no array
* se o elemento daquela posição checked[i] retorna false, temos que checá-lo com todos os outros elementos do array em um segundo loop, iterando com o ponteiro j
    * se retorna true, significa que já foi checado anteriormente, então devemos continuar para a próxima iteração com continue
* o ponteiro j deve começar uma posição à frente de i, isso porque teremos um condicional que checa de elemento atual (i) é igual a algum dos outros elementos do array (j), e se i e j começam na mesma posição, isso sempre retornará true
* para o elemento atual, iteramos até achar a correspondência, se ela for efetiva, então checked[j] = true; e iteramos a contagem
* agora devemos realocar espaço para caber mais uma linha dentro da matriz criada anteriormente (linhas + 1)
    * como criamos um ponteiro dentro da matriz, devemos inicializá-lo, alocando memória para 2 elementos
    * com espaço alocado para os elementos, devemos acessar a matriz na linha atual correspondente e inserir os dois elementos a partir de seus índices (0 e 1)
*/
int **contarFrequencia(int *arr, int len, int *lenMatrix) {
    int lns = 0;
    int **matriz = NULL;
    
    bool *checked = malloc(len * sizeof(bool));
    for (int i = 0; i < len; i++) {

        if (checked[i]) {
            continue;
        }
        int count = 1;

        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                checked[j] = true;
                count++;
            }
        }

        int **temp = realloc(matriz, (lns + 1) * sizeof(int*));
        if (!temp) {
            printf("não foi possível realocar memória para nova linha");
            return NULL;
        }
        matriz = temp;

        int cols = 2;
        matriz[lns] = malloc(cols * sizeof(int));
        if (!matriz[lns]) {
            printf("não foi possível alocar memória para armazenar elementos");
            return NULL;
        }

        matriz[lns][0] = arr[i];
        matriz[lns][1] = count;
        lns++;
    }
    free(checked);
    *lenMatrix = lns;
    return matriz;
}

int main() {
    int arr[] = {1, 2, 1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 2, 1, 3, 5, 6, 1, 2, 1, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int lenMatriz;
    int **matriz = contarFrequencia(arr, len, &lenMatriz);

    printf("{\n");
    for (int i = 0; i < lenMatriz; i++) {
        printf("{ ");
        for (int j = 0; j < 2; j++) {
            printf("%d", matriz[i][j]);
            if (j < 1) printf(", ");
        }
        printf(" }%s\n", (i < lenMatriz - 1) ? ", " : " ");
    }
    printf("}\n");
    
    return 0;
}