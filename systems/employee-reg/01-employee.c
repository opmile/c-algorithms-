// codigo QUEBRADO!!!! voltar nele depois!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_SIGLA 10

typedef struct {
    char nome[MAX_NOME];
    int codigo;
    char sigla[MAX_SIGLA];
} Departamento;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int idade;
    Departamento *dep;
    float salario;
} Funcionario;

void cleanBuffer();
Funcionario *registerFuncionario(
    Funcionario *funcionarios,
    int *qtdFunciocarios,
    char *nome,
    int idade,
    float salario,
    const char *siglaDept,
    Departamento *deps,
    int qtdDepartamentos    
);

void printFunc(
    Funcionario *funcionarios, 
    int qtdFuncionarios, 
    Departamento *departamentos, 
    int qtdDepartamentos);

int main() {
    Departamento deps[] = {
        {"Tecnologia da Informação", 101, "TI"},
        {"Recursos Humanos", 102, "RH"}
    };
    int qtdDepartamentos = sizeof(deps) / sizeof(deps[0]);

    Funcionario *funcionarios = NULL;
    int qtdFuncionarios = 0;

    int op;
    do {
        printf("---- cadastro de funcionários ----\n");
        printf("1 - cadastrar novo funcionário\n");
        printf("2 - exibir funcionários cadastrados\n");
        printf("3 - remover funcionário do sistema\n");
        printf("0 - encerrar programa\n");
        printf("----------------------------------\n");
        scanf("%d", &op);
        cleanBuffer();

        switch (op) {
            case 1: {
                char nome[MAX_NOME];
                printf("nome do funcionário: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                int idade;
                printf("idade do funcionário: ");
                scanf("%d", &idade);
                cleanBuffer();

                float salario;
                printf("salário do funcionário: ");
                scanf("%f", &salario);
                cleanBuffer();

                char sigla[MAX_SIGLA];
                printf("sigla do departamento: ");
                fgets(sigla, MAX_SIGLA, stdin);
                sigla[strcspn(sigla, "\n")] = '\0';


                for (int i = 0; i < strlen(sigla); i++) {
                    sigla[i] = toupper(sigla[i]);
                }

                funcionarios = registerFuncionario(funcionarios, &qtdFuncionarios, nome, idade, salario, sigla, deps, qtdDepartamentos);

                break;
            }
            case 2:
                printFunc(funcionarios, qtdFuncionarios, deps, qtdDepartamentos);
            break;
        }

    } while (op != 0);
    
    return 0;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}  

Funcionario *registerFuncionario(
    Funcionario *funcionarios,
    int *qtdFuncionarios,
    char *nome,
    int idade,
    float salario,
    const char *siglaDept,
    Departamento *deps,
    int qtdDepartamentos    
) {
    // tenta encontrar o departamento correspondente
    Departamento *dep = NULL;
    for (int i = 0; i < qtdDepartamentos; i++) {
        if (strcmp(deps[i].sigla, siglaDept) == 0) {
            dep = &deps[i];
            break;
        }
    }

    if (!dep) {
        printf("departamento '%s' não encontrado!", siglaDept);
        return funcionarios;
    }

    Funcionario *temp = realloc(funcionarios, (*qtdFuncionarios + 1) * sizeof(Funcionario));
    if (!temp) {
        printf("não foi possível realocar memória para novo funcionário\n");
        return funcionarios;
    }
    funcionarios = temp;

    Funcionario *f = &funcionarios[*qtdFuncionarios];
    strcpy(f->nome, nome);
    f->idade = idade;
    f->salario = salario;
    f->dep = dep;

    (*qtdFuncionarios)++;
    return funcionarios;
}

void printFunc(
    Funcionario *funcionarios, 
    int qtdFuncionarios,
    Departamento *departamentos, 
    int qtdDepartamentos
) {
    for (int i = 0; i < qtdDepartamentos; i++) {
        if (funcionarios == NULL) printf("nenhum funcionário cadastrado ainda!\n"); break;
        printf("Departamento: %s\n", departamentos[i].nome);
        for (int j = 0; j < qtdFuncionarios; j++) {
            if (funcionarios[j].dep == &departamentos[i]) {
                printf("%d - %s, %d anos, %.2f", j + 1, funcionarios[j].nome, funcionarios[j].idade, funcionarios[j].salario);
            }
        }
    }
}