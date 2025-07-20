### Recursão em C — Do Básico ao Avançado**

#### AQUECIMENTO – Fundamentos e Fixação

#### 1. **Fatorial Recursivo**

> Clássico dos clássicos.
> `int fatorial(int n)` — sem laços, só com chamadas recursivas.

---

#### 2. **Soma Recursiva de Vetor**

> Dado um vetor de inteiros, some todos os elementos recursivamente.
> Protótipo: `int soma(int *vet, int tamanho)`

---

#### 3. **Potência com Recursão**

> Calcule `a^b` sem usar `pow()` e sem laços.
> Otimize para dividir pela metade quando possível (`a^b = (a^(b/2))^2`)

---

#### 4. **Fibonacci com Recursão**

> Não apenas calcule o n-ésimo termo, mas **conte quantas chamadas recursivas ocorrem**.
> Ajuda a entender a complexidade **explosiva** da recursão ingênua.

---

#### 5. **Imprimir Vetor ao Contrário**

> Dado um vetor, imprima seus elementos **na ordem inversa**, usando recursão.
> Nada de índices invertidos — a recursão faz o trabalho.

---

#### 🚀 NÍVEL INTERMEDIÁRIO – Aplicando em Strings, Arrays e Algoritmos

---

#### 6. **String Palíndromo com Recursão**

> Verifique se uma `char*` é um palíndromo, comparando primeiro e último caractere, avançando recursivamente.

---

#### 7. **Busca Linear Recursiva**

> Dado um array de inteiros e um valor `x`, retorne o índice da primeira ocorrência.
> Protótipo: `int buscar(int *vet, int tamanho, int x)`

---

#### 8. **Contar Ocorrências de um Número**

> Conte quantas vezes um valor aparece em um vetor.
> Bônus: retorne todos os índices onde aparece, usando ponteiro duplo.

---

#### 9. **Substituir Letras em uma String**

> Recursivamente percorra uma string substituindo todas as ocorrências de uma letra por outra.
> Exemplo: `'banana'` com `'a' → 'x'` → `'bxnxnx'`

---

#### 10. **Soma Diagonal Recursiva de Matriz**

> Receba uma matriz quadrada `n x n` e retorne a soma da diagonal principal, usando chamada recursiva com os índices.
> `soma(matriz, i)` → soma elemento `matriz[i][i]` até `i == n`

---

#### 🧩 AVANÇADO – Criatividade, Backtracking e Combinações

---

#### 11. **Gerar Permutações de String**

> Receba uma string e imprima **todas as permutações possíveis** (sem bibliotecas de string).
> Use troca de caracteres (`swap`) e chamadas recursivas.

---

#### 12. **Números Binários com n Dígitos**

> Gere todos os números binários possíveis com `n` dígitos.
> Ex: `n = 2` → `00 01 10 11`
> Use uma função recursiva para construir cada número caractere por caractere.

---

#### 13. **Soma de Subconjuntos (Subset Sum)**

> Dado um array de inteiros e um valor alvo, diga se é possível formar esse valor com a **soma de um subconjunto** dos elementos.
> Recursão com inclusão/remoção de cada elemento.

---

#### 14. **Resolver Labirinto (Backtracking)**

> Receba uma matriz 2D representando um labirinto com `0` (livre) e `1` (parede).
> Ache um caminho do canto superior esquerdo até o canto inferior direito.
> Marque o caminho percorrido e use backtracking para recuar se bater numa parede.

---

#### 15. **Número de Caminhos em uma Matriz**

> Conte quantos caminhos possíveis existem do topo até a base de uma matriz `m x n`, podendo andar apenas para **direita ou para baixo**.
> Protótipo: `int caminhos(int i, int j, int m, int n)`

---

#### 16. **Parênteses Balanceados**

> Dada uma string com apenas `'('` e `')'`, use recursão para verificar se os parênteses estão corretamente balanceados.

---

#### 17. **Torre de Hanoi**

> Resolva a Torre de Hanoi com `n` discos.
> Mostre cada movimento. Clássico obrigatório em provas de domínio com recursão.

---

#### 18. **Caminhos sem Repetir Letras**

> Dada uma matriz de letras, encontre **todos os caminhos únicos** que não repitam letras.
> (Backtracking + memória para marcar letras usadas).

---

