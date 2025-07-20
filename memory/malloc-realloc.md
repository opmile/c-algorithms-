## exercícios - alocação e realocação dinâmica

### **nível 1 – fundamentos e controle de memória**

1. **crie um vetor dinâmico de `n` inteiros.**
   * o usuário informa `n`
   * preencha com números aleatórios entre 1 e 100
   * imprima e libere a memória

2. **realoque o vetor para o dobro do tamanho.**
   * preencha os novos espaços com `-1`
   * imprima novamente o vetor completo

3. **crie uma matriz dinâmica de `m x n` inteiros.**
   * o usuário fornece `m` e `n`
   * preencha a matriz com números aleatórios
   * imprima no formato de matriz
   * garanta que **nenhum vazamento de memória** ocorra

---

### **nível 2 – manipulação dinâmica real**

5. **crie um programa de cadastro de notas.**
   * o usuário define quantos alunos (`n`) e quantas notas por aluno (`m`)
   * use uma **matriz dinâmica** para armazenar as notas
   * permita que o usuário **adicione mais notas a um aluno** individualmente (use `realloc`)
   * exiba a média de cada aluno

--!
6. **crie um vetor de strings (char\*\*).**
   * o usuário informa quantos nomes serão cadastrados.
   * para cada nome, aloque memória suficiente com `malloc`.
   * após o preenchimento, **realoque um nome aleatório para ter o dobro do tamanho** e permita ao usuário editar.
   * libere tudo no final.

---

### 🧪 **Nível 3 – Casos mistos com realloc (desafiador)**

7. **Crie um sistema de listas dinâmicas em 2D:**

   * Comece com uma matriz `n x m` inicial.
   * O usuário pode:

     * Adicionar linhas (`realloc` do ponteiro externo).
     * Adicionar colunas em uma linha específica (`realloc` do ponteiro interno).
   * Sempre que a matriz mudar, imprima o novo estado.

8. **Faça um programa que simule um "editor de pixels":**

   * Cada pixel é um número inteiro.
   * Comece com uma matriz 2x2.
   * O usuário pode:

     * Inserir novas linhas ou colunas.
     * Alterar valores de pixels.
     * Remover linhas ou colunas com `realloc`.
   * Exiba sempre o estado atual.

---

### 💥 Bônus de fixação

9. **Crie um histórico de comandos com realloc:**

   * Crie um vetor dinâmico de strings.
   * O programa lê comandos (strings) do usuário.
   * Cada novo comando é adicionado com `realloc`.
   * Ao digitar `"sair"`, o programa mostra todo o histórico e libera a memória.

