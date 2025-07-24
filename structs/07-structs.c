#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_SIGLA 6

typedef struct {
    char nome[MAX_NOME];
    int codigo;
    char sigla[MAX_SIGLA];
} Departamento;

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float salario;
    Departamento *dep;
} Funcionario;

Funcionario *criar(
    char *nome,
    int idade,
    float salario,
    char *sigla,
    Departamento *deps,
    int qtdDeps
);

void imprimirInfo(Funcionario *f);

int main() {
    Departamento deps[] = {
        {"Tecnologia da Informação", 101, "TI"},
        {"Recursos Humanos", 102, "RH"},
        {"Projetos", 103, "GP"}
    };
    int qtdDeps = sizeof(deps) / sizeof(deps[0]);

    char nome[MAX_NOME];
    printf("nome do funcionário: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int idade;
    printf("idade: ");
    scanf("%d", &idade);
    getchar();

    float salario;
    printf("salário: ");
    scanf("%f", &salario);
    getchar();
    
    char sigla[MAX_SIGLA];
    printf("sigla do departamento: ");
    fgets(sigla, MAX_SIGLA, stdin);
    sigla[strcspn(sigla, "\n")] = '\0';

    Funcionario *f = criar(nome, idade, salario, sigla, deps, qtdDeps);
    imprimirInfo(f);

    return 0;
}

Funcionario *criar(
    char *nome,
    int idade,
    float salario,
    char *sigla,
    Departamento *deps,
    int qtdDeps
) {
    for (int i = 0; i < strlen(sigla); i++) {
        sigla[i] = toupper(sigla[i]);
    }

    Departamento *dep = NULL;
    for (int i = 0; i < qtdDeps; i++) {
        if (strcmp(sigla, deps[i].sigla) == 0) {
            dep = &deps[i];
        }
    }
    if (!dep) {
        printf("departamento '%s' não encontrado!", sigla);
        return NULL;
    }

    Funcionario *f = malloc(sizeof(Funcionario));
    if (!f) {
        printf("não foi possível criar novo funcionário");
        return NULL;
    }

    strcpy(f->nome, nome);
    f->idade = idade;
    f->salario = salario;
    f->dep = dep;

    return f;
}

void imprimirInfo(Funcionario *f) {
    printf("Funcionário: %s\n", f->nome);
    printf("Idade: %d\n", f->idade);
    printf("Salário: %.2f\n", f->salario);
    printf("Departamento: %s\n", f->dep->nome);
}