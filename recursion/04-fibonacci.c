/*
a sequência de fibonacci é uma sequência em que cada número corresponde a soma dos seus dois anteriores

seq = 
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
0 + 1 = 1
    1 + 1 = 2
        2 + 1 = 3
            3 + 2 = 5
                5 + 3 = 8
                    ...

construiremos uma função que recebe como parâmetro a posição p e retorna o número naquela posição

casos base:
* se p == 1 (primeiro elemento na sequencia) -> retorna 0
* se p == 2 (segundo elemento na sequencia) -> retona 1
aqui construimos os casos mínimos (os dois primeiros elmentos)

caso normal: (chamada recursiva)
a função deve retornar a soma dos dois números anterioes da sequencia
ex) f(3) + f(4) = f(5)
ex) f(1) + f(2) = f(3)
*/
#include <stdio.h>
#include <stdlib.h>

int count;
int countOt;

int fibonacci(int p); // 01
int fib(int n, int *memo); // 02

int main() {
    // 01
    printf("elemento na 8a posição na sequência de fibonacci: %d\n", fibonacci(8));
    printf("total de chamadas recursivas: %d\n", count);

    // 02
    int n;
    printf("escolha o termo de fibonacci: ");
    scanf("%d", &n);

    // cria vetor e inicializa com -1
    int *memo = malloc((n + 1) * sizeof(int)); // indices de 0 a n
    for (int i = 0; i <= n; i++) { // iterar inclusive até o índice n
        memo[i] = -1;
    }

    // n-1 para ajustar a sequência - se o usuário pede f(5), internamente estamos calculando f(4) (memo é um array que começa com índice 0!!)
    printf("fibonacci(%d) = %d\n", n, fib(n - 1, memo));
    printf("número de chamadas recursivas: %d\n", countOt);

    free(memo);

    return 0;
}

int fibonacci(int p) { // 01
    count++;
    if (p == 1) {
        return 0;
    }
    if (p == 2) {
        return 1;
    }
    return fibonacci(p - 1) + fibonacci(p - 2);
}

/*
complexidade exponencial O(2^n)
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1)
│   │   │   └── fib(0)
│   │   └── fib(1)
│   └── fib(2)
│       ├── fib(1)
│       └── fib(0)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1)
    │   └── fib(0)
    └── fib(1)
muitos termos se repetem! algoritmo recursivo ingênuo

vamos resolver agora implementando uma otimização de memoization: guardar os resultados já calculados numa estrutura (vetor), para evitar recálculos
*/

int fib(int n, int *memo) { // 02 
    countOt++;

    if (memo[n] != -1) {
        return memo[n];
    } // se fib(n) já foi calculado, estará guardado

    // casos base
    if (n == 0) return memo[0] = 0;
    if (n == 1) return memo[1] = 1;

    // caso normal: fib(n) ainda não foi calculado
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

