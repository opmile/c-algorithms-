### 📚 **Lista Intermediária de Exercícios de Lógica com C**

**Foco:** Algoritmos, memória, e raciocínio aplicado

---

#### 1. **Agrupamento por Frequência**

> Dado um array de inteiros, crie uma função que agrupe os elementos com base em sua frequência, colocando os elementos mais frequentes primeiro.
> Exemplo de entrada: `{4, 5, 6, 5, 4, 3}`
> Saída esperada: `{4, 4, 5, 5, 6, 3}`

---

#### 2. **Verificação de Anagramas com Ponteiros**

> Escreva uma função que receba dois `char*` e retorne 1 se forem anagramas um do outro, e 0 caso contrário.
> Faça isso sem usar bibliotecas externas além de `stdio.h` e `stdlib.h`.
> **Restrições**: não pode usar `strlen`, `strcpy`, `strcmp` etc. Tudo na unha.

---

#### 3. **Submatriz de Soma Máxima (Kadane 2D)**

> Dada uma matriz de inteiros (alocação dinâmica), encontre a submatriz retangular com a **maior soma de elementos**.
> Se estiver fácil demais, aumente: imprima também as coordenadas dessa submatriz.

---

#### 4. **Remoção de Palavras de String**

> Dada uma string e um array de strings com "palavras proibidas", escreva uma função que retorne uma nova string com todas as palavras proibidas removidas.
> Exemplo:
> Entrada: `"hoje o sol está quente"`, proibidas: `["sol", "quente"]`
> Saída: `"hoje o está"`

---

#### 5. **Compressão de String (RLE)**

> Implemente a compactação de string por contagem de caracteres repetidos (Run Length Encoding).
> `"aaabbccccd"` → `"a3b2c4d1"`
> Faça isso com alocação dinâmica para a string final.

---

#### 6. **Transposição Dinâmica**

> Escreva uma função que **transponha uma matriz dinâmica de inteiros**, realocando o espaço e mantendo a integridade dos dados.
> Entrada: `int** matriz` de tamanho m x n
> Saída: nova matriz n x m

---

#### 7. **Strings Alternadas**

> Escreva uma função que verifica se uma string pode ser dividida em dois grupos intercalados iguais.
> Exemplo: `"abab"` → **Sim**
> Exemplo: `"abcabc"` → **Não**
> Desafio bônus: aloque os dois grupos separadamente usando `malloc`.

---

#### 8. **Sistema de Alunos com Notas Dinâmicas**

> Crie um sistema em que o usuário possa cadastrar um número qualquer de alunos e cada aluno tenha um número variável de notas.
> Faça uma função para:
>
> * Cadastrar alunos
> * Inserir notas
> * Calcular média de cada aluno
> * Remover um aluno
> * Imprimir ranking dos melhores alunos

---

#### 9. **Rotação Circular de Array**

> Crie uma função que rotacione um array circularmente para a direita `k` vezes, sem usar um array auxiliar do mesmo tamanho.
> Dica: use reversão de trechos e lógica modular.

---

#### 10. **Filtragem de Elementos Duplicados com Ponteiros**

> Dado um array dinâmico de inteiros, elimine todos os elementos duplicados. Retorne o novo array realocado e o novo tamanho via ponteiro.

---

#### 11. **Verificação de Sudoku**

> Receba uma matriz 9x9 preenchida e determine se é uma solução válida de Sudoku.
> Use vetores auxiliares para checar colunas, linhas e submatrizes 3x3.

---

#### 12. **Palíndromos em Substrings**

> Dada uma string, imprima todas as substrings que são palíndromos.
> Exemplo: `"abba"` → `"a", "b", "b", "a", "bb", "abba"`

---

#### 13. **Diagonal Mágica**

> Uma matriz quadrada é dita **diagonal mágica** se a soma da diagonal principal for igual à soma da diagonal secundária.
> Implemente essa verificação. Faça a entrada ser dinâmica (alocada com `malloc`).

---

#### 14. **Mesclagem de Arrays Dinâmicos Ordenados**

> Dado dois arrays dinâmicos **já ordenados**, mescle-os em um terceiro array também ordenado, sem usar funções prontas como `qsort`.

---

#### 15. **Inversão com Ponteiros Triplos**

> Receba uma matriz alocada com `int ***` (como uma lista de arrays de arrays) e implemente a função que inverte a ordem das linhas e colunas, sem quebrar o acesso.

---

