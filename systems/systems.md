### **Seção 1: Ponteiros e Structs em Conjunto**

#### **1. Cadastro de Estudantes (nível médio+)**

Crie um sistema que:

* Permita cadastrar N estudantes (nome, idade, média).
* Aloca dinamicamente o vetor de estudantes.
* Ordena os estudantes por média (maior para menor).
* Exibe os dados.

✅ *Reforce:* Structs + `malloc` + manipulação com ponteiros + ordenação.

---

#### **2. Atualização via Ponteiro (nível médio)**

Implemente uma função:

```c
void atualizarIdade(struct Estudante* e, int novaIdade);
```

Depois, em `main`, teste passando diferentes estudantes.

✅ *Reforce:* Passagem de struct por ponteiro e modificação direta.

---

#### **3. Cópia de Structs via Ponteiros (nível avançado)**

Crie uma função que recebe um ponteiro para `struct Pessoa` e retorna um novo ponteiro com os mesmos dados, porém em outra região da memória (cópia profunda, com `malloc`).

✅ *Reforce:* Alocação + cópia de strings internas + retorno de ponteiros.

---

### 🧠 **Seção 2: Matrizes e Vetores Dinâmicos**

---

#### **4. Matriz Dinâmica e Soma (nível médio)**

* Aloca dinamicamente uma matriz `int**` de tamanho MxN.
* Lê os valores.
* Calcula e retorna a soma de todos os elementos.

✅ *Reforce:* `int**`, laços aninhados, `malloc` de matriz, `free`.

---

#### **5. Transposição de Matriz Dinâmica (nível difícil)**

Recebe uma matriz MxN e retorna sua transposta NxM.

✅ *Reforce:* Indexação dinâmica, reallocações, função que retorna `int**`.

---

#### **6. Vetor Crescente Dinâmico (nível médio+)**

Implemente um vetor que cresce de tamanho com `realloc` sempre que for cheio.

* Inicia com tamanho 4.
* Quando o usuário insere mais que a capacidade, dobra o tamanho.
* Mostre os dados ao final.

✅ *Reforce:* `realloc`, alocação progressiva, ponteiros de ponteiros.

---

### 💾 **Seção 3: Simulações Realistas com Structs e Ponteiros**

---

#### **7. Sistema Bancário (nível difícil)**

Crie um sistema com:

* Cadastro de contas bancárias (número, nome, tipo, saldo).
* Depósito, saque e transferência.
* Uso de ponteiros para modificar saldos.
* Listagem geral e saldo total do banco.

✅ *Reforce:* Struct + vetores dinâmicos + ponteiros para funções + boas práticas.

---

#### **8. Gerenciador de Alunos com Busca (nível médio+)**

* Cadastro dinâmico de alunos.
* Busca por nome (com `strcmp`) retornando ponteiro para o aluno.
* Permite alterar a média via função que recebe ponteiro para struct.

✅ *Reforce:* Manipulação de strings + ponteiros para structs.

---

#### **9. Agenda com Remoção de Contatos (nível difícil)**

* Cadastro dinâmico de contatos (nome, telefone, email).
* Busca por nome.
* Remoção (deve realocar vetor ou "encolher").
* Mostrar todos os contatos.

✅ *Reforce:* `malloc`/`free`, manipulação de índices, memória "limpa".

---

#### **10. Cadastro de Filmes com Gêneros (nível insano)**

* Cada filme possui nome, ano e um **vetor dinâmico de strings** representando os gêneros.
* Cadastre vários filmes com vários gêneros.
* Liste todos os filmes e seus gêneros.
* Libere corretamente toda a memória.

✅ *Reforce:* Structs com vetores de `char*`, `malloc`, `free`, ponteiros de ponteiros.

---

### 🔚 **Bônus: Exercício Mestre**

#### **11. Sistema de Biblioteca (nível hardcore)**

Projete um sistema com:

* Cadastro de livros (título, autor, ano).
* Cadastro de usuários (nome, CPF).
* Empréstimo de livros (um usuário pode pegar até 3 livros).
* Consulta de livros emprestados por usuário.
* Devolução.
* Toda a memória alocada deve ser **liberada corretamente**.

✅ *Reforce tudo:* Structs aninhados, ponteiros para structs, vetores dinâmicos, lógica condicional, `malloc`, `free`, e organização modular (coloque funções em outro arquivo se quiser ir além).

---

Se quiser, posso organizar esses exercícios por dias, com um plano intensivo de 7, 10 ou 14 dias.

Quer o gabarito de algum? Ou prefere quebrar a cabeça e me chamar pra revisar depois?

Tô aqui contigo até o fim do intensivão 💪
