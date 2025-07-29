### **agrupamento por categoria**
> dado um vetor de `struct Livro { char titulo[50]; char categoria[30]; }`, separe os livros por categoria em diferentes vetores.
> ex) livros de “ficção” num vetor, “biografia” em outro etc.

-- para depois
Categorias dinâmicas: detectar categorias em tempo de execução.
Ordenar livros dentro de cada categoria.
=

vamos montar um vetor de vetores de `Livro`, onde cada subvetor representa uma categoria, e os livros são agrupados dinamicamente de acordo com essas categorias

1. criar um vetor de strings com as categorias rotuladas
2. criar um vetor de ponteiro para `Livro`, um ponteiro para cada categoria
3. realocar os subvetores dinamicamente à medida que encontramos livros da categoria correspondente
4. ao final, cada `categorias[i]` terá seu `livrosPorCategoria[i]` com seus livros agrupados
5. imprimir tudo agrupado

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 50
#define MAX_CATEGORIA 30

typedef struct {
    char titulo[MAX_TITULO];
    char categoria[MAX_CATEGORIA];
} Livro;

void groupByCategory(Livro *livros, int totalLivros) {
    const char *categorias[] = {"ficção", "biografia", "suspense", "aventura", "romance"};
    int totalCategorias = sizeof(categorias) / sizeof(categorias[0]);

    // vetor de ponteiro para Livro (um vetor por categoria)
    Livro **livrosPorCategoria = malloc(totalCategorias * sizeof(Livro*));
    int *quantidades = calloc(totalCategorias, sizeof(int)); // livros por categoria

    if (!livrosPorCategoria || !quantidades) {
        printf("impossível alocar memória!");
        return;
    }

    // agrupar por categoria
    for (int i = 0; i < totalLivros; i++) {
        for (int j = 0; j < totalCategoria; j++) {
            if (strcmp(livros[i].categoria, categorias[j]) == 0) {
                int qtdAtual = quantidades[j];
                Livro *temp = realloc(livrosPorCategoria[j], (qtd + 1) * sizeof(Livro));
                if (!temp) {
                    printf("impossível realocar memória!");
                    return;
                }

                livrosPorCategoria[j] = temp;
                livrosPorCategoria[j][qtdAtual] = livros[i];
                quantidades[j]++;
                break;
            }
        }
    }

    // resultado
    for (int i = 0; i < totalCategorias; i++) {
        printf("\ncategoria: %s\n", categorias[i]);
        for (int j = 0; j < quantidades[i]; j++) {
            printf(" - %s\n", livrosPorCategoria[i][j].titulo);
        }
    }

    // liberar memória
    for (int i = 0ç i < totalCategoriasç i++) {
        free(livrosPorCategoria[i]);
    }
    free(livrosPorCategoria);
    free(quantidades);
}
```

**agrupar livros**
esse código separa os livros de um vetor `Livro[]` em grupos por categoria, usando um vetor de ponteiros para vetores dinâmicos (`Livro **livrosPorCategoria`)

* usaremos `categorias`, um vetor de ponteiro para strings literais, para comparar com os livros registrados e descobrir onde cada um pertence
* `livrosPorCategoria[i]` vai ser um vetor de livros da categoria `i`
* `quantidades[i]` conta quantos livros tem na categoria `i`
* ou seja, temos um vetor de vetores dinâmicos de `Livro`, um para cada categoria, e outro vator dinâmico para armazenar a quantidade de livros da categoria correspondente ao vetor `catgorias`
* `livrosPorCategoria` deve ser inicializado como `NULL`, porque ainda não adicionamos um livro, mas quando adicionarmos, cada ponteiro deve ter sido inicializados (não podemos atribuir coisas a ponteiros não inicializados, já que apontam para lugares aleatórios)
* para cada livro em `livros`, percorremos todas as categorias. se `livro[i].categoria` for igual a `categorias[j]`, o livro pertence a essa categoria
* dentro dessa condição, se encontramos a categoria correspondente, adicionamos o livro
    * para isso, devemos realocar o tamanho de `livrosPorCategoria` para a categoria correspondente extraindo essa informação de `quantidades[j]`
    * `realloc` expande o vetor de livros da categoria `j` para caber mais 1 livro
* `livrosPorCategoria[j][qtdAtual] = livros[i]` copia o livro atual para a posição `qtdAtual` do vetor da categoria `j`
* daí incrementa-se o contador `quantidades` para aquela categoria

ainda podemos encapsular tudo dentro de uma struct chamada `Categoria`, o que deixa o código mais organizado e sem paralelismo bagunçado de vetores (tipo `livrosPorCategoria[i]` e `quantidades[i]` separados)
e agora podemos criar um vetor de `Categoria` que agrupa os Livros por categoria

```c
#include <stdio.h>
#include <stlib.h>
#include <string.h>

#define MAX_NOME 30
#define MAX_TITULO 50

typedef struct {
    char titulo[MAX_TITULO];
    char categoria[MAX_NOME];
} Livro;

typedef struct {
    char nome[MAX_NOME];
    Livro *livros; // vetor de livros dessa categoria
    int qtd; // quantidade de livros nessa categoria
} Categoria;

void agruparPorCategoria(Livro *l, totalLivros) {
    const char *nomesCategorias[] = {"ficção", "biografia", "suspense", "aventura", "romance"};
    int totalCategorias = sizeof(nomesCategorias) / sizeof(nomesCategorias[0]);

    Categoria *categorias = malloc(totalCategorias * sizeof(Categoria));
    if (!categoria) {
        printf("não foi possível alocar memória");
        return;
    }

    // inicializar cada categoria
    for (int i = 0; i < totalCategorias; i++) {
        strcpy(categorias[i].nome, nomesCategorias[i]);
        categorias[i].livros = NULL;
        categorias[i].qtd = 0;
    }

    // agrupagem de livros
    for (int i = 0; i < totalLivros; i++) {
        for (int j = 0; j < totalCategorias; j++) {
            if (strcmp(l[i].categoria, categorias[j].nome) == 0) {
                int pos = categoria[j].qtd;
                Livro *temp = realloc(categoria[j].livros, (pos + 1) * sizeof(Livro));
                if (!temp) {
                    printf("não foi possível realocar memória");
                    return;
                }

                categoria[j].livros = temp;
                categoria[j].livros[pos] = l[i];
                categoria[j].qtd++;
                break;
            }
        }
    }

    // exibir resultado
    for (int i = 0; i < totalCategorias; i++) {
        printf("\n categoria: %s\n", categorias[i].nome);
        for (int j = 0; j < categorias[i].qtd; j++) {
            printf(" - %s\n", categorias[i].livros[j].titulo);
        }
    }

    // liberar memória
    for (int i = 0; i < totalCategorias; i++) {
        free(categorias[i].livros);
    }
    free(categorias);
}

```


e se não tivessemos rotulado `nomesCategoria`? como obtê-los em tempo de execução?
```c

char **extrairCategorias(Livro *l, totalLivros, int *outCount) {
    char **nomesCategorias = NULL;
    int qtd = 0;

    for (int i = 0; i < totalLivros; i++) {
        char *atual = l[i].categoria;
        bool achou = false;

        for (int j = 0; j < qtd; j++) {
            if (strcmp(atual, nomesCategorias[j]) == 0) {
                achou = true;
                break;
            }
        }

        if (!achou) {
            char **temp = realloc(nomesCategorias, (qtd + 1) *sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar memória");
                return;
            }

            nomesCategorias = temp;
            nomesCategorias[qtd] = malloc(strlen(atual) + 1);
            strcpy(nomesCategorias[qtd], atual);
            qtd++;
        }
    }
    outCount = qtd;
    return nomesCategorias;
}

```
* inicializamos nosso vetor de `nomesCategorias` e o de quantidades `qtd`
* para cada livro dentro do nosso vetor de livros, temos que analisar correspondência entre o livro atual e cada uma das categorias já registradas dentro do nosso vetor de `nomesCategoria`
* se acharmos correspondência, significa que a categoria do livro atual já foi registrada no nosso vetor de categorias únicas
* caso contrário, precisamos registrar essa categoria no nosso vetor de categorias únicas. para isso, realocamos a memória desse vetor para caber a quantidade atual + 1 slot
* depois de realocar, temos um vetor de categorias preenchidas e um ponteiro qualquer. esse ponteiro corresponde ao último ponteiro adicionado, temos que alocar espaço na memória para que ele se encaixe exatamente no tamanho do nome da categoria do livro atual + 1 slot (do terminador nulo)
* agora que temos espaço suficiente pra ele, copiamos (strcpy como é uma string) o nome da categoria do livro atual para o slot exato (que ocupa a última posição qtd) do vetor de categorias
* por fim, precisaremos da contagem que se refere ao tamanho do vetor de categorias, e para isso, recebemos como parâmetro o endereço de um valor inteiro. ao final de todas as iterações, teremos armazenado em `qtd` a quantidade exata de categorias, e daí só resta fazer a atribuição entre as duas variáveis