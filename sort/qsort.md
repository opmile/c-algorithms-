# ordenação de arrays em C com `qsort`
`qsort` é uma função da lib padrão de C (`stdlib.h`) que serve para ordenar qualquer tipo de array, desde que você forneça uma função de comparação que explique como os elementos devem ser comparados

ela usa o algorimo **quicksort** internamente - que é rápido na média O(n log n)

```c
void qsort(void *base, size_t total_amout, size_t size, int (*compare)(const void *, const void *));
```
* `base`: ponteiro para o primeiro elemento do array
* `total_amount`: número de elementos no array
* `size`: tamanho de cada elemento, geralmente `sizeof(tipo)`
* `compare`: ponteiro para função que compara dois elementos

ex)
```c
qsort(ar, n, sizeof(int), compara_crescente);
```
note que não tem parênteses em `compara_crescente`
porque você não quer chamar a função naquele momento. você quer passar seu endereço para o `qsort`, para que ele possa chamá-la depois
chamar sem parênteses significa passar a referência da função: um ponteiro
chamar a função significa chamar com `()`, isso só faz sentido se você está usando a função agora

## ex) ordenar um array de inteiros em ordem crescente

**criando a função de comparação**
```c
#include <stdio.h>
#include <stdlib.h>

int compara_crescente(const void *a, const void *b) {
    int x  = *(int*)a;
    int y = *(int*)b;

    return x - y;
}
```
a função `qsort` foi feita pra ser genérica: ela precisa funcionar com qualquer tipo de dado (seja `int`, `float`, `struct`, etc.)
como ela não sabe que tipo de dado você está ordenando, ela chama a sua função de comparação passando dois ponteiros genéricos - `void *`
> `void *` é um tipo de ponteiro que pode apontar para qualquer coisa. é como dizer: "não sei o que tem aqui, mas você sabe, então se vira aí"

como *você* sabe que está lidando com inteiros, então na sua função de comparação, você diz:
```c
int x = *(int*)a;
```
1. **`(int*)a`**
> "compilador, esse ponteiro que chegou aqui como `void*` na real aponta para um `int`
estamos fazendo um **cast** (conversão de tipo)

2. ***`*(int*)a`**
agora você está fazendo a desreferenciação do ponteiro, e acessando o valor inteiro que está no endereço apontado por `a`

3. `const` está ali porque `qsort` garante que não vai alterar os elmentos, e espera que você também não altere na sua função de comparação. você está ali só pra comparar, não pra mudar, então não tente fazer, por exemplo, `*(int*)a = 999`, isso é errado e perigoso

> `a` e `b` são recebidos na função endereços genéricos (`void *`), e você os transforma em `int*` pra poder acessar os valores que eles apontam

**integrando com `qsort`**
```c
#include <stdio.h>
#include <stdlib.h>

int compara_crescente(const void *a, const void *b) {
    int x  = *(int*)a;
    int y = *(int*)b;

    return x - y;
}

int main() {
    int arr[] = {5, 9, 3, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compara_crescente);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
```
* função `compara_crescente` pega dois ponteiro genéricos `void`, os converte para `int*`, desreferencia e compara
* o retorno segue a regra
    * se `<0`, `a < b`
    * se `>0`, `a < b`
    * se `0`, `a == b`

### ordenação decrescente
só muda a função de comparação (é ela que define a forma de comparação do seu `qsort`)
```c
int compara_decrescente(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return y - x;
}
```
* o retorno segue a regra
    * se `<0`, `b < a`
    * se `>0`, `b > a`
    * se `0`, `b == a`


### dicas
* se você errar na função de comparação (por exemplo, retornar `x - y` onde `x` e `y` `unsigned` grandes), pode causar overflow e bugs sutis
* sempre que possível, use `if` ao invés de retornar direto a subtração
```c
int compara(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (x < y) return -1; // então x vem antes de y
    if (x > y) return 1; // então x vem depois de y
    return 0;
}
```

## ex) ordenar pares e depois ímpares
queremos que o array seja ordenado colocando os números pares primeiro e depois os ímpares, dentro de cada grupo em ordem crescente
```c
int arr[] = {9, 2, 5, 8, 1, 6};
```
esperado:
```c
[2, 6, 8, 1, 5, 9] // pares em ordem crescente, depois ímpares em ordem crescente
```

a função de comparação que faz isso
```c
int compara_pares_primeiro(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    int par_x = x % 2 == 0;
    int par_y = y % 2 == 0;

    if (par_x && !par_y) return -1; // x é par e y é ímpar - x vem antes
    if (!par_x && par_y) return 1; // x é ímpar e y é par - x vem depois

    return x - y; // se ambos s'ao pares ou ambos são ímpares - ordem crescente
}
```
1. pega os valores `a` e `b`, transforma os ponteiros genéricos em `int*` e acessa seus valores

2. verifica se são pares
```c
int par_x = x % 2 == 0;
int par_y = y % 2 == 0;
```
* `par_x` será `1` (true) se `x` for par, senão será `0`
* `par_y`será `1` (true) se `y` for par, senão será `0`

3. regras de ordenação baseadas em paridade
```c
if (par_x && !par_y) return -1;
```
* se `x` é par e `y` é ímpar, então x vem antes de y

```c
if (!par_x && par_y) return 1;
```
* se `x` é ímpar e `y` é par, então x vem depois de y

se os dois são do mesmo grupo `return x - y`
* se os dois são pares, ordena em ordem crescente
* se os dois são ímpares, também ordena em ordem crescente

*obs*
```c
int compara_float_decrescente(const void *a, const void *b) {
    float x = *(float*)a;
    float y = *(float*)b;

    // return y - x; PROBLEMA!!
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}
```
perceba que estamos construindo uma função de comparação para ordenar em ordem decrecente números do tipo `float`, mas mesmo assim, nossa função de comparação continua a retornar tipo `int`
* `qsort` não está interessado na diferença numérica exata entre os valores - ele só quer saber qual deles é maior, menor ou se são iguais
* ou seja, o `qsort` espera que sua função de comparação retorne um valor inteiro que indique uma dessas três opções
| resultado de `compar(a, b)` | significado            |
| --------------------------- | ---------------------- |
| `< 0`                       | `a < b` (a vem antes)  |
| `== 0`                      | `a == b` (são iguais)  |
| `> 0`                       | `a > b` (a vem depois) |
então o retorno precisa ser um `int` compatível com essa convenção - não precisa nem ser a diferença real entre a e b, só precisa indicar a ordem relativa

`// return y - x; PROBLEMA!!`
como x e y são float, então x - y será um float. mas a função está prometendo retornar `int`, então o compulador vai tentar converter implicitamente - o que pode gerar comportamentos estranhos ou perda de precisão, além de não bater com o tipo exigido pelo `qsort`

## atenção

ordenação crescente
```c
if (x < y) return -1; // x vem antes
if (x > y) return 1; // x vem depois
return 0;
```
* se você já tem a comparação crescente, só basta inverter (decrescente) os retornos

ordenação decrescente
```c
if (x < y) return 1; 
if (x > y) return -1; 
```