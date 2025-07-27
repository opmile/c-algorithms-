# versão hardcore do exercício de gerar todos os subarrays possíveis
> gere todos os subarrays possíveis de um array de inteiros e armazene-os em uma matriz

a ideia central aqui será
* receber um array de inteiros
* gerar todos os subarrays possíveis (contíguos)
* armazenar cada subarray em uma matriz jagged, ou seja, um array de ponteiros para arrays de diferentes tamanhos (jagged array -> uma matriz em que cada linha apresenta um número distinto de colunas)
* alocar tudo dinamicamente com `malloc`
* usar `int **subarrays` como matriz de subarrays

1. **porque passo `***subarrays` e `**tamanhos` como parâmetro?**
* `***subarrays` é um ponteiro para um ponteiro para um ponteiro de int
```
***subarrays → endereço de **subarrays → endereço de *subarrays → vetor de inteiros
```
se lembre que no `main`, já teremos a declaração `int **subarrays`. esse `subarrays` será justamente nossa matriz jagged que queremos que nossa função retorne. mas a função é `void`!
se quer modificar esse `int **subarrays` dentro da função, e precisa que essa modificação seja refletida quando a função retornar, você deve passar o endereço dele, ou seja, `int ***subarrays`

* `**tamanhos` é um ponteiro para ponteiro um ponteiro int
da mesma forma, lá no `main` temos `int *tamanhos`, um array de inteiros e, como queremos modificar esse valor dentro da função de modo que no seu retorno a alteração seja refletida, passamos o endereço desse array de inteiros como parâmetro da função

* `*total` também tem quase o mesmo papel
ele representa o endereço de um valor inteiro passado como parâmetro da função justamente para que a função faça refletir sua modificação

como estamos trabalhando com ponteiros, se quisermos acessar seus valores, precisamos usar a desreferenciação (`*`) na frente do nome do ponteiro
* no caso de `subarrays`:
    * `subarrays` (o argumento) é um `int ***`
        * um ponteiro para um ponteiro para ponteiro de int
        * ou seja, o endereço da nossa matriz jagged (que é um `int **`) criada lá no `main`
    * `*subarrays` então é o `int **` real que está no main, ou seja, o valor original da variável
    * usamos então `*subarrays = malloc(...)` para modificar o valor do ponteiro original

2. **por que do uso de cast manual em funções de alocação?**
em C, as funções de alocação e realocação retornam sempre `void*`, um `ponteiro cru`
```c
void *malloc(size_t tamanho);
```
ou seja: o que ela retorna é um ponteiro para alguma coisa
* se lembre que a alocação apenas reserva bytes na memória, e não faz distinção de tipo
* então o compilador de C não sabe para que tipo de dado você quer apontar
* o tipo de dado que você aloca é o tipo do ponteiro, mas isso porque C fez o cast automaticamente pra você
* a conversão não é obrigatória em C! mas em C++ o cast é obrigatório, porque C++ é mais rigoroso com a tipagem

*então porque adotamos o uso de cast nesse caso?*
* por, principalmente, legibilidade de código. além de também poder evitar warnings em compiladores mistos e já prepara pra caso o código seja usado em C++ também
* pra ser sincera, se quer escrever código mais explícito e didático e, como nesse caso, queremos reforçar que estamos trabalhando com o valor que o endereço do ponteiro aponta


```c
void gerarSubarrays(int *array, int n, int ***subarrays, int **tamanhos, int *total) {
    *total = n * (n + 1) / 2; // indica o total de linhas da matriz subarrays
    // total de linhas = total de subarrays

    // alocar vetor de ponteiros para cada subarray
    *subarrays = (int**)malloc((*total) * sizeof(int*));
    // alocar vetor de inteiros para indicar o tamanho de cada subarray
    *tamanhos = (int*)malloc((*total) * sizeof(int*));

    int index = 0; // controla cada subarray

    for (int i = 0; i < n; i++) { // marca início do subarray
        for (int j = i; j < n; j++) { // marca fim do subarray
            int len = j - i + 1;

            (*subarrays)[index] = (int*)malloc(len * sizeof(int));
            (*tamanhos)[index] = len; // define o tamanho para aquela posição

            // copia os elementos do subarray
            for (int k = 0; k < len; k++) {
                (*subarrays)[index][k] = array[i + k];
            }

            index++
        }
    }
}

void liberarSubarrays(int **subarrays, int *tamanhos, int total) {
    for (int i = 0; i < total; i++) {
        free(subarrays[i]); // libera os ponteiros internos int
    }
    free(subarrays); // libera o ponteiro externo
    free(tamanhos)
}

int main() {
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);

    int **subarrays;
    int *tamanhos;
    int total;

    gerarSubarrays(array, n, &subarrays, &tamanhos, &total);

    printf("todos os subarrays:\n");
    for (int i = 0; i < total; i++) {
        printf("[");
        for (int j = 0; j < tamanhos[i]; j++) {
            printf("%d", subarrays[i][j]);
            if (j < tamanhos[i] - 1) printf(", ");
        }
        printf("]\n");
    }
    
    liberarSubarrays(subarrays, tamanhos, total);

    return 0;
}
```