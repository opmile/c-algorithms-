### Recursão em C

#### AQUECIMENTO – fundamentos e fixação

#### 1. **fatorial recursivo**
> clássico dos clássicos.
> `int fatorial(int n)` — sem laços, só com chamadas recursivas.

#### 2. **soma recursiva de vetor**
> dado um vetor de inteiros, some todos os elementos recursivamente.
> protótipo: `int soma(int *vet, int tamanho)`

#### 3. **potência com Recursão**
> calcule `a^b` sem usar `pow()` e sem laços.
> otimize para dividir pela metade quando possível (`a^b = (a^(b/2))^2`)

#### 4. **fibonacci com recursão**
> não apenas calcule o n-ésimo termo, mas **conte quantas chamadas recursivas ocorrem**.
> ajuda a entender a complexidade **explosiva** da recursão ingênua.

#### 5. **imprimir vetor ao contrário**
> dado um vetor, imprima seus elementos **na ordem inversa**, usando recursão.
> nada de índices invertidos — a recursão faz o trabalho.


#### NÍVEL INTERMEDIÁRIO – aplicando em strings, arrays e algoritmos

#### 6. **string palíndromo com recursão**
> verifique se uma `char*` é um palíndromo, comparando primeiro e último caractere, avançando recursivamente.

#### 7. **busca linear recursiva**
> dado um array de inteiros e um valor `x`, retorne o índice da primeira ocorrência.

#### 8. **contar ocorrências de um número**
> conte quantas vezes um valor aparece em um vetor.
> Bônus: retorne todos os índices onde aparece, usando ponteiro duplo.

---

#### 9. **substituir letras em uma string**
> recursivamente percorra uma string substituindo todas as ocorrências de uma letra por outra.
> Exemplo: `'banana'` com `'a' → 'x'` → `'bxnxnx'`

---

#### 10. **soma siagonal recursiva de matriz**
> receba uma matriz quadrada `n x n` e retorne a soma da diagonal principal, usando chamada recursiva com os índices.
> `soma(matriz, i)` → soma elemento `matriz[i][i]` até `i == n`

---

#### AVANÇADO – criatividade, backtracking e combinações

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

