### **bateria de exercícios com `struct` em C**

* aplicar **lógica com structs**
* trabalhar com **alocação dinâmica**, **ponteiros para structs**
* exercitar **relacionamentos entre structs**
* e explorar **níveis crescentes de raciocínio**, com código compacto e direto ao ponto.

---

#### 1. **troca de dados entre structs**
> crie uma `struct Pessoa` com nome e idade.
> escreva uma função que troque os dados de duas pessoas usando ponteiros.
> **reforço:** manipulação por referência, sem retorno.

#### 2. **busca de maior valor em um vetor de structs**
> dado um array de `struct Produto { char nome[50]; float preco; }`, encontre o produto mais caro.
> Faça isso com uma função que receba o vetor e retorne um ponteiro para o produto mais caro.

---

#### 3. **Contar Palavras com Struct**

> Crie uma função que recebe uma string e conta a frequência de cada palavra, armazenando em uma `struct Palavra { char texto[50]; int freq; }`.
> Armazene todas as palavras diferentes em um vetor de `struct Palavra` dinâmico.
> Requer **comparação, alocação e contagem lógica.**

---

#### 4. **Agrupamento por Categoria**

> Dado um vetor de `struct Livro { char titulo[50]; char categoria[30]; }`, separe os livros por categoria em diferentes vetores.
> Exemplo: livros de “ficção” num vetor, “biografia” em outro etc.
> **Pede: lógica de agrupamento + comparação entre strings.**

---

#### 5. **Atualização de Campo com Ponteiros**

> Crie uma função que recebe um ponteiro para `struct Conta { char titular[50]; float saldo; }` e um valor.
> A função deve aplicar um “bônus” no saldo de 10% se o valor passado for maior que 1000.
> Serve pra praticar acesso a campos via ponteiros + lógica condicional.

---

#### 6. **Struct com Vetor Interno de Inteiros**

> Crie uma `struct Aluno` que tem um nome e um vetor de 5 notas.
> Escreva uma função que calcula a média das notas e retorna se o aluno foi aprovado.
> **Bônus:** permita que o vetor de notas seja alocado dinamicamente.

---

#### 7. **Struct com Ponteiro para Outro Struct**

> Crie duas structs: `struct Departamento` e `struct Funcionario`, onde o `Funcionario` tem um ponteiro para o `Departamento`.
> Simule a associação entre eles e imprima os dados do funcionário junto com o nome do departamento.
> Esse é excelente pra entender **relacionamentos entre structs**.

---

#### 8. **Ordenação de Structs**

> Dado um vetor de `struct Pessoa { char nome[50]; int idade; }`, ordene as pessoas por idade de forma crescente.
> Use `qsort` ou escreva sua própria função de ordenação com `strcmp` e lógica personalizada.

---

#### 9. **Remoção de Elemento de um Vetor de Structs**

> Escreva uma função que remove um aluno específico (por nome) de um vetor de `struct Aluno`, realocando dinamicamente para manter a integridade.
> **Toque importante:** deslocamento + `realloc`.

---

#### 10. **Struct Aninhada com Média**

> `struct Curso` possui um vetor de `struct Aluno`, cada aluno tem vetor de notas.
> Escreva uma função que calcule a média geral do curso com base nas médias dos alunos.
> **Reforça acesso em profundidade**: `curso.alunos[i].notas[j]`

---

#### 11. **Busca de Substring em Vetor de Structs**

> Dado um vetor de `struct Livro { char titulo[100]; }`, encontre todos os livros que contêm a palavra “algoritmo” no título.
> Sem `strstr` — apenas ponteiros e lógica manual de substring.

---

#### 12. **Comparação de Campos com Ponteiros**

> Dado dois ponteiros para `struct Data { int dia, mes, ano; }`, escreva uma função que retorna:
>
> * 0 se são iguais
> * -1 se a primeira é anterior
> * 1 se a primeira é posterior
>   (tipo um `strcmp`, mas pra datas)

---

#### 13. **Structs em Forma de Lista Linear**

> Simule manualmente uma lista encadeada de `struct Elemento`, onde cada `Elemento` aponta para o próximo.
> Faça uma função que insere no final e uma que imprime todos os elementos.
> Sem usar `typedef struct Node*` — só com ponteiro explícito.

---

#### 14. **Função para Clonar uma Struct**

> Escreva uma função `Aluno* clonar(Aluno *original)` que cria uma cópia alocada dinamicamente da struct recebida.
> Muito útil pra entender **copiar por valor vs ponteiro.**

---

#### 15. **Struct de Frequência de Caracteres**

> Dada uma string, conte a frequência de cada caractere e armazene em `struct Letra { char c; int freq; }`.
> Ordene depois por frequência decrescente.


