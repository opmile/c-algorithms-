> **Organizar e agrupar dados repetidos em estruturas dinâmicas.**

* `struct` com string como chave (categoria, nome, tipo…)
* uso de vetores dinâmicos
* comparação de strings (`strcmp`)
* realloc, calloc e agregações dinâmicas

---

## exercícios para fixar a lógica de agrupamento e contagem

---

### **1. agrupamento de filmes por gênero**
> crie uma função que recebe um vetor de `struct Filme { char titulo[50]; char genero[30]; }`
> agrupe os filmes por gênero, como foi feito com os livros anteriormente.
* use struct `Genero` com:
  ```c
  typedef struct {
      char nome[30];
      Filme *filmes;
      int qtd;
  } Genero;
  ```

---

### **2. contagem de tipos de animais**
> dado um vetor de `struct Animal { char especie[30]; char nome[50]; }`,
> conte quantos animais de cada espécie existem.
* use `struct Especie { char nome[30]; int qtd; }`.
* A cada novo animal:

  * se a espécie já estiver no vetor, `++qtd`
  * se não estiver, adiciona com `qtd = 1`

✅ **Mesma lógica de contar palavras**, mas com nome diferente e dado diferente.

---

### **3. agrupar alunos por curso**
> receba um vetor de `struct Aluno { char nome[50]; char curso[40]; }`
> agrupe os alunos por curso (tipo Ciência da Computação, Direito, etc).
* use struct `Curso`:

  ```c
  typedef struct {
      char nome[40];
      Aluno *alunos;
      int qtd;
  } Curso;
  ```

---

### **4. Contar Palavras Iniciadas com Mesma Letra**

> Dada uma string longa, conte quantas palavras começam com cada letra do alfabeto (A-Z, case insensitive).

* Use algo como:

  ```c
  typedef struct {
      char letra;
      int freq;
  } LetraFreq;
  ```

* Transforme primeira letra em `toupper(token[0])` e contabilize.

✅ Fixação de `strtok`, comparação e vetores de structs que crescem conforme necessário.

---

### **5. Agrupar Produtos por Marca**

> Receba `struct Produto { char nome[50]; char marca[40]; }`
> Agrupe por marca — ou seja, todos os produtos da “Nike”, da “Apple”, etc.

* Struct `Marca` com:

  ```c
  typedef struct {
      char nome[40];
      Produto *produtos;
      int qtd;
  } Marca;
  ```

repete padrão de agrupamento com realocação e `strcmp`, ajuda a deixar automático.

---
Você também pode transformar isso num repositório temático de **agrupamento e análise de dados em C** – seria um diferencial de respeito no seu GitHub. Quer ajuda pra montar isso?
