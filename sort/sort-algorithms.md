## 🟢 PARTE 1: Exercícios com `qsort`

### 🟢 Nível 1 — Fixação de sintaxe

1. **Ordene um array de inteiros em ordem crescente usando `qsort`.**
2. **Ordene um array de floats em ordem decrescente.**
3. **Ordene um array de caracteres em ordem alfabética.**

### 🟢 Nível 2 — Adicionando lógica personalizada

4. **Ordene um array de inteiros colocando os pares primeiro (em ordem crescente), depois os ímpares (em ordem decrescente).**
5. **Ordene um array de strings em ordem crescente de comprimento.**

### 🟢 Nível 3 — Trabalhando com structs

6. Dado:
   ```c
   typedef struct {
       char nome[50];
       int idade;
   } Pessoa;
   ```
   **Ordene um vetor de `Pessoa` por idade crescente.**
   
7. **Ordene o vetor anterior por nome (ordem alfabética).**
8. **Ordene por idade decrescente e, em caso de empate, por nome crescente.**

### 🟢 Nível 4 — Misto com lógica e ponteiros

9. **Dado um array de ponteiros para strings, ordene-o em ordem alfabética.**
10. **Dado um array de structs com `float nota`, ordene apenas os alunos com nota ≥ 5, mantendo o resto no lugar.**

---

## 🔵 PARTE 2: Exercícios com Bubble Sort (implementação manual)

### 🔵 Nível 1 — Implementação básica

1. **Implemente o bubble sort para ordenar um array de inteiros em ordem crescente.**
2. **Modifique o algoritmo para ordenar em ordem decrescente.**

### 🔵 Nível 2 — Lógica condicional

3. **Ordene apenas os números pares de um array (em ordem crescente), mantendo os ímpares nas posições originais.**
4. **Ordene um array de strings (array de `char*`) usando bubble sort com `strcmp`.**

### 🔵 Nível 3 — Structs e manipulação

5. Com a struct `Pessoa`, implemente bubble sort para ordenar por:
   * Idade crescente.
   * Nome crescente (`strcmp`).

6. **Implemente bubble sort para ordenar structs por múltiplos critérios.**
   Ex: primeiro por idade, depois por nome.

### 🔵 Nível 4 — Otimizações e reflexões

7. **Implemente uma versão otimizada do bubble sort (com verificação de troca).**
8. **Implemente o bubble sort para ordenar os elementos de uma coluna de uma matriz `int mat[5][5]`.**

---




