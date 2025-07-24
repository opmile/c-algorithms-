## ✅ NÍVEL 1 — Fundamentos com structs simples (sem ponteiro entre structs)

Objetivo: Criar funções básicas (CRUD), manipular arrays de structs fixos ou com alocação simples.

### 1. Sistema de Cadastro de Produtos

**Structs:** Produto
**Funções:** cadastrar, listar, buscar por nome ou código, atualizar preço, remover
**Campos:** nome, código, preço, quantidade em estoque

---

### 2. Agenda de Contatos

**Structs:** Contato
**Funções:** adicionar, listar, buscar por nome, editar telefone, remover contato
**Campos:** nome, telefone, email
👉 Foca em manipulação de strings e busca por chave textual.

---

### 3. Cadastro de Alunos com Notas (estático)

**Structs:** Aluno
**Funções:** cadastrar, listar, buscar por nome, atualizar nota, calcular média
**Campos:** nome, matrícula, 3 notas (array fixo)
👉 Já introduz arrays dentro de structs, e lógica condicional pra média.

---

## 🔄 NÍVEL 2 — Composição de structs + agrupamentos (sem alocação dinâmica ainda)

Objetivo: Criar relação entre structs com ponteiros (ou campos embutidos), introduzindo hierarquia.

### 4. Sistema de Funcionários e Departamentos

**Structs:** Departamento, Funcionario
**Funções:** cadastrar funcionário, listar todos, buscar por nome ou por departamento, atualizar salário, remover
**Relacionamento:** cada funcionário pertence a um departamento
👉 Treina ponteiro de `Funcionario` para `Departamento`.

---

### 5. Biblioteca com Livros e Gêneros

**Structs:** Livro, Genero
**Funções:** cadastrar livro, listar livros por gênero, buscar por título, atualizar status (emprestado/disponível), remover
**Relacionamento:** cada livro tem um gênero
👉 Força filtragem por categoria (string ou código).

---

### 6. Cadastro de Alunos por Curso

**Structs:** Curso, Aluno
**Funções:** cadastrar aluno em curso, listar alunos por curso, atualizar nota, remover aluno
👉 Introduz agrupamento por entidade e já começa a parecer modelagem de verdade.

---

## 🔥 NÍVEL 3 — Alocação dinâmica e sistemas "vivos"

Objetivo: Manipular ponteiros, `malloc/realloc/free`, vetores dinâmicos, e CRUD em memória real.

### 7. Cadastro de Pacientes com Histórico de Consultas

**Structs:** Paciente, Consulta
**Funções:** adicionar paciente, registrar consulta (dinamicamente), buscar paciente, listar consultas, remover paciente
**Desafio:** cada paciente pode ter um vetor dinâmico de consultas
👉 Excelente para treinar `malloc` dentro de structs.

---

### 8. Sistema de Notas de Estudantes (matriz dinâmica)

**Structs:** Aluno
**Funções:** cadastrar aluno, adicionar nota (dinamicamente), calcular média, buscar por nome, remover aluno
**Desafio:** matriz de notas alocada dinamicamente (`int**`)
👉 Você já está mexendo com isso — ótimo ponto pra consolidar.

---

### 9. Plataforma de Cursos Online

**Structs:** Curso, Aluno, Inscrição
**Funções:** cadastrar curso, cadastrar aluno, inscrever aluno em curso, listar alunos por curso, remover inscrição
**Desafio:** vários alunos por curso e vários cursos por aluno (N\:N)
👉 Te força a pensar em modelagem intermediária.

---

## 💀 NÍVEL 4 — Modelagem mais complexa (sem banco, mas quase lá)

Objetivo: Pensar em estruturas que se aproximam de banco de dados em miniatura.

### 10. Sistema de Locadora de Filmes

**Structs:** Cliente, Filme, Locação
**Funções:** cadastrar filme, cliente, registrar locação, devolver filme, buscar por cliente ou filme, listar atrasos
**Desafio:** ligação entre três structs com datas e controle de status
👉 Te obriga a pensar no CRUD em três camadas conectadas.

---

### 11. Sistema de Eventos e Participantes

**Structs:** Evento, Participante
**Funções:** criar evento, cadastrar participante, inscrever participante no evento, listar participantes por evento, cancelar inscrição
**Desafio:** múltiplas inscrições e busca cruzada
👉 Aqui você simula um sistema relacional leve.

---

### 12. Sistema Acadêmico Completo

**Structs:** Aluno, Curso, Disciplina, Nota
**Funções:** cadastrar alunos, cursos e disciplinas, matricular aluno, lançar notas, calcular média por disciplina, emitir boletim
**Desafio:** múltiplas estruturas, busca, filtragem e realocação
👉 Projeto final. Monta tudo que caiu na prova e vai além.

