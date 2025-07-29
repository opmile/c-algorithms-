# bubble sort
bubble sort ("ordenação por bolha") é baseado em uma ideia bem visual
> **comparar pares de elementos adjacentes e trocá-los se estiverem na ordem errada**
> faz isso várias vezes até que nenhuma troca seja necessária

entre os algoritmos de ordenação, é o mais ineficiente, com complexidade O(n^2)

**analogia da bolha:**
pense nos maiores valores como bolhas que sobem para o topo (final do array), a cada passada completa

*lógica básica*:
> comparo pares, troco se estiver errado, e vou empurrando os maiores pro final

## ex) vetor [5, 3, 8, 4, 2]:

*primeira passada (i = 0):*
5 > 3 → troca → [3, 5, 8, 4, 2]
5 < 8 → ok
8 > 4 → troca → [3, 5, 4, 8, 2]
8 > 2 → troca → [3, 5, 4, 2, 8] ← 8 subiu (bubbled)

*segunda passada (i = 1):*
3 < 5 → ok
5 > 4 → troca → [3, 4, 5, 2, 8]
5 > 2 → troca → [3, 4, 2, 5, 8] ← 5 subiu

continua até que tudo esteja ordenado
https://www.youtube.com/watch?v=xli_FI7CuzA&ab_channel=MichaelSambol

## implementação do bubble sort
```c
void bubbleSort(int **vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // troca os elementos
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
```
**`i` controla quantas passadas já foram feitas**

* porque a condição de iteração `i < n - 1` no laço de fora?
quantas passagens são necessárias, no pior caso, para ordenar `n` números?
-> `n-1` passagens!
ex) com 3 elementos:
primeira passada: o maior vai pro final
segunda passada: o segundo maior vai pro meio
pronto! o menor já está na posição correta
com `n = 3`, você só precisa de 2 passadas (`i = 0`, `i = 1`)
então o laço externo roda enquando `i < n - 1`

**`j` percorre os elementos de 0 até o penúltimo não ordenado**
* `n - 1 - i`: a cada passada, o último `i` elementos já estão ordenados, então não precisamos mais trocar neles, então é isso que impede que fiquemos comparando as posições já ordenadas no final do vetor
`i = 0` (primeira passada), ainda nenhum elemento foi fixado, então você faz `j = 0` até `j < n - 1`
`i = 1` (segunda passada), o maior já está certo no final, então não precisa mais comparar o último par
`i = 2`, dois maiores já estão fixos no final, e por aí vai...

* o `- 1` está em `n - 1 - i` porque estamos comparando pares vizinhos `v[j]` e `v[j+1]`
nunca podemos deijar `j+1` ultrapassar o tamanho do vetor!
se `j` pudesse ir até `n-1`, `v[j+1]` seria `v[n]` -> índice inválido!
com `n = 3`, `j` iria até `2`
`v[j+1] = v[3]` ERRO! fora do vetor


## comparação com outros algoritmos
| algoritmo          | lógica básica                                          | diferença em relação ao Bubble Sort                       |
| ------------------ | ------------------------------------------------------ | --------------------------------------------------------- |
| **Bubble Sort**    | troca elementos vizinhos se estiverem fora de ordem    | muitas trocas. lento, mas simples de entender             |
| **Selection Sort** | seleciona o menor elemento e coloca na posição correta | menos trocas. você sempre troca 1x por iteração externa   |
| **Insertion Sort** | insere elementos em uma sublista já ordenada           | ideal para vetores quase ordenados. lógica de "encaixe"   |
| **Quick Sort**     | escolhe pivô e divide o vetor em menores e maiores     | muito mais rápido, mas envolve recursão e partições       |
| **Merge Sort**     | divide o vetor até unidades e depois junta ordenado    | baseado em recursão. muito eficiente, mas mais trabalhoso |


