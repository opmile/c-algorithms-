### **Parte 1 — Lógica com Arrays (nível: intermediário para avançando)**

1. **Rotacionar um array para a direita/esquerda**

   * Exemplo: `[1,2,3,4,5]` rotacionado 2 vezes à direita vira `[4,5,1,2,3]`.
   * Tente fazer **sem criar um novo array** (dica: use swaps ou modularização de índices).

2. **Remover todos os elementos duplicados de um array**

   * Entrada: `[1, 2, 3, 2, 4, 1]`
   * Saída esperada: `[1, 2, 3, 4]`
   * Desafio: preserve a ordem original.

3. **Interpolar dois arrays ordenados em um novo array também ordenado**

   * Ideal para treinar merge de merge sort.
   * Exemplo: `[1, 3, 5] + [2, 4, 6] → [1, 2, 3, 4, 5, 6]`.

4. **Calcular a frequência de cada número em um array**

   * Exemplo: `[1,1,2,3,2,1,4] → 1:3, 2:2, 3:1, 4:1`

5. **Substituir todos os elementos negativos de um array por 0**

   * Simples, mas legal pra treinar iteração e condição.

---

### **Parte 2 — Manipulação de Strings (nível: médio para avançado)**

1. **Remover espaços duplicados de uma string**

   * Entrada: `"  isso   é   um    teste "`
   * Saída: `"isso é um teste"`
   * Dica: desloca caracteres manualmente com `for`.

2. **Verificar se uma string é um palíndromo (sem usar funções prontas)**

   * Exemplo: `"arara"`, `"socorram-me-subi-no-onibus-em-marrocos"`
   * Remove espaços e acentos antes de comparar (plus challenge!).

3. **Contar quantas vezes uma palavra aparece em uma string**

   * Entrada: `"hoje o dia está bonito, o céu está azul, o sol está forte"`
   * Palavra: `"o"` → Resultado: 3
   * Treina busca por substring manualmente (sem `strstr`!).

4. **Converter uma string para camelCase**

   * Entrada: `"meu primeiro nome"`
   * Saída: `"meuPrimeiroNome"`

5. **Remover todas as vogais de uma string**

   * Entrada: `"chatgpt é incrível"`
   * Saída: `"chtgpt é ncrvl"`

---

### **Parte 3 — Misto: arrays + strings (nível avançando)**

1. **Ordenar um array de strings lexicograficamente (sem `qsort`)**

   * Entrada: `["banana", "abacaxi", "laranja"]`
   * Saída: `["abacaxi", "banana", "laranja"]`
   * Treine comparação com `strcmp`.

2. **Criar um "buscador de palavras": dado um array de strings, encontre todas que contêm um certo prefixo**

   * Exemplo: prefixo `"pro"` → encontra `"programar"`, `"prova"`, etc.

3. **Reverter cada palavra em uma string, mantendo a ordem**

   * Entrada: `"sou estudante de C"`
   * Saída: `"uos etnadutse ed C"`

4. **Validar se uma string tem todos os caracteres únicos**

   * Entrada: `"amor"` → true; `"banana"` → false

5. **Desafio bônus:** implemente um **mini sistema de correção de ortografia**

   * Dado um dicionário com palavras e um texto de entrada, destaque palavras que **não estão** no dicionário.

