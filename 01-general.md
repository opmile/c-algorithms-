# exercícios 3 `OK`

## exercícios gerais

1. **soma de diagonal principal de matriz dinâmica**
* aloca uma matriz nxn com `int**`
* preenche com valores
* soma a diagonal principal
extra: faça o mesmo com a diagonal segundária

2. **clonar vetor dinâmico**
* dado um vetor alocado com `malloc`, escreva uma função que retorna uma cópia exata desse vetor em uma nova região da memória
* resolva tudo com aritmética de ponteiros

3. **função que modifica struct por ponteiro**
```c
typedef struct {
  char nome[100];
  int idade;
} Pessoa;
```
* crue uma função que recebe um `Pessoa*` e altera a idade 
* em `main` verifique se a modificação persistiu

4. **soma de cmapos em vetor de structs**
* crie um vetor de `Pessoa`, como acima
* escreva uma função que recebe um ponteiro para esse vetor e o número de elementos, e retorna a soma das idades

4. **soma recursiva dos elementos de um vetor**
escreva uma função recursiva que recebe um ponteiro para vetor e seu tamanho e retorna a soma total dos elementos

5. **maior elemento usando ponteiro**
escreva uma função `int* maiorElemento(int* vetor, int n)` que retorna o endereço do maior valor do vetor
depois, altere esse valor diretamente usando o ponteiro retornado

6. **função que recebe `int**` e preenche**
escreva uma função `void preencher(int **m, int linhas, int colunas)` que recebe uma matriz previamente alocada e a preenche com `i + j`

7. **remover ímpares de vetor dinâmico**
dado um vetor dinâmico de inteiros, crie uma função que remove os ímpares, realocando o vetor para novo tamanho

8. **recrie `strlen()`**
crie uma função que recebe um `char*` e retorna o tamanho da string sem usar nenhuma função da lib

9. **contador de vogais em vetor de strings**
recebe um `char** nomes` e `int n` e conta quantas vogais há no total de todas as strings

10. **soma dos quadrados com ponteiro**
recebe um vetor `int*` e retorna a soma dos quadrados de todos os elementos (use só aritmética de ponteiros)

11. **verificar palíndromo com ponteiro**
receba um `char*` e verifique se a string é palíndromo sem usar índices `[]`

