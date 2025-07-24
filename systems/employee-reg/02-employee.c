#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_SIGLA 8

typedef struct {
    char nome[MAX_NOME];
    char sigla[MAX_SIGLA];
    int codigo;
} Departamento;

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float salario;
    Departamento *dep;
} Funcionario;

void imprimirFuncionarios(
    Funcionario *funcionarios, 
    int qtdFuncionarios,
    Departamento *departamentos,
    int qtdDepartamentos
);

Funcionario *cadastrarNovo(
    Funcionario *funcionarios, 
    int *qtdFuncionarios,
    char *nome,
    int idade,
    float salario,
    char *sigla,
    Departamento *departamentos,
    int qtdDepartamentos
);

int main() {
    Departamento departamentos[] = {
        {"Tecnologia da Informação", "TI", 101},
        {"Recursos Humanos", "RH", 102},
        {"Projetos", "PRJ", 103},
        {"Financeiro", "FI", 104},
        {"Produtos", "PRD", 101},
    };
    int qtdDepartamentos = sizeof(departamentos) / sizeof(departamentos[0]);

    int qtdFuncionarios = 3;
    Funcionario *funcionarios = malloc(qtdFuncionarios * sizeof(Funcionario));
    funcionarios[0] = (Funcionario){"Milena Oliveira", 19, 1200.00, &departamentos[0]};
    funcionarios[1] = (Funcionario){"Alex Carlos", 22, 950.00, &departamentos[1]};
    funcionarios[2] = (Funcionario){"Camila Marques", 25, 1550.00, &departamentos[3]};
    
    funcionarios = cadastrarNovo(funcionarios, &qtdFuncionarios, "João Macedo", 23, 1340, "FI", departamentos, qtdDepartamentos);
    imprimirFuncionarios(funcionarios, qtdFuncionarios, departamentos, qtdDepartamentos);

    return 0;
}

Funcionario *cadastrarNovo(
    Funcionario *funcionarios, // queremos modificar o vetor original e devolver o ponteiro realocado
    int *qtdFuncionarios, // precisa ser ponteiro para atualizar o valor depois de sair da função
    char *nome,
    int idade,
    float salario,
    char *sigla,
    Departamento *departamentos,
    int qtdDepartamentos
) {
    // inicializar um ponteiro Departamento apontando para nulo
    // tentar encontrar departamento correspondente -> comparando sigla com siglas dos departamentos registrados
    // se encontrar, apontar ponteiro para o endereço do departamento registrado correspondente
    // avisar se nao encontrar
    Departamento *dep = NULL;
    for (int i = 0; i < qtdDepartamentos; i++) {
        if (strcmp(sigla, departamentos[i].sigla) == 0) {
            dep = &departamentos[i];
            break;
        }
    }
    if (!dep) {
        printf("departamento '%s' não encontrado\n", sigla);
        return NULL;
    }

    // realocar memória para comportar mais um funcionario no vetor
    // criar um ponteiro para acessar o último elemento do vetor
    // a partir desse ponteiro, acessar o struct criado na última posição e definir cadastro com os parâmetros
    Funcionario *temp = realloc(funcionarios, (*qtdFuncionarios + 1) * sizeof(Funcionario));
    if (!temp) {
        printf("não foi possível cadastrar novo funcionário!");
        return NULL;
    }
    funcionarios = temp;

    Funcionario *f = &funcionarios[*qtdFuncionarios];
    strcpy(f->nome, nome);
    f->idade = idade;
    f->salario = salario;
    f->dep = dep;

    return funcionarios;
}

void imprimirFuncionarios(
    Funcionario *funcionarios, 
    int qtdFuncionarios,
    Departamento *departamentos,
    int qtdDepartamentos
) {
    for (int i = 0; i < qtdDepartamentos; i++) {
        printf("\n Departamento: %s\n", departamentos[i].nome);
        for (int j = 0; j < qtdFuncionarios; j++) {
            if (funcionarios[j].dep == &departamentos[i]) {
                printf("- Funcionário: %s\n", funcionarios[j].nome);
                printf("    - Idade: %d\n", funcionarios[j].idade);
                printf("    - Salário: %.2f\n", funcionarios[j].salario);
            }
        }
    }
}