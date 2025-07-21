# o que é programação dinâmica
é uma técnic ade otimização usada para resolver problemas que:
1. têm subproblemas sobrepostos - você resolve os mesmos subproblemas várias vezes
2. têm estrutura ótima - a solução do problema maior depende das soluções ótimas dos subproblemas

em vez de recalcular uma resposta todas vez que você precisa dela (como na recursão pura), você guarda o resultado (memoriza!) e reaproveita depois. isso evita trabalhos repetido, e o programa fica MUITO mais rápido, com menor complexidade

## qual a relação com recursão?
a relação é tão íntima quanto arroz e feijão

**recursão resolve um problema dividindo-o em subproblemas menores**
mas pode se tornar ineficiente, porque recalcula as mesmas coisas várias vezes

**programação dinâmica entra para otimizar a recursão**
ela lembra das respostas usando *momoização* (PD top-down com cache) ou tabelas (PD botton up)

*memoização* é uma técnica de armazenamento de resultados intermediários de chamdas de função para evitar repetir cálculas desnecessários

**top-down**: "de cima para baixo"
você começa pelo problema maior e vai descendo recursivamente até os menores
* a memoização é aplicada dentro da recursão, com um cache (geralmente um array ou map) que guarda dos resultados
```c
int memo[100];

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```
* aqui você salva o resultado de cada `fib(n)` e reutiliza
* complexidade `O(n)`

**bottom-up**: de baixo para cima
você começa pelos problemas menores e vai subindo até o problema maior
* não usa recursão, usa laços
* uso de tabela (array/tabulação) como estrutura auxiliar
```c
int fib(int n) { // seja n a posição desejada (1 - n)
    int dp[n+1]; //  cria a tabela/array 
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```
* aqui você constrói a solução de baixo para cima
* também `O(n)`, mas sem recursão
