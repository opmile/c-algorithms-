#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int *notas;
} Aluno;

void cleanBuffer();
void addNota(Aluno *alunos, int aluno, int *numeroNotas, int add);
void calcularMedia(Aluno *alunos, int lenAlunos, int *numeroNotas);
void printAlunos(Aluno *alunos, int lenAlunos, int* numeroNotas);

int main() {

    printf("sistema de cadastro de alunos e notas\n");
    printf("---------------------------------------\n");

    int lenAlunos;
    printf("digite a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &lenAlunos);
    cleanBuffer();

    int lenNotas;
    printf("digite a quantidade de notas no semestre: ");
    scanf("%d", &lenNotas);
    cleanBuffer();

    Aluno *alunos = malloc(lenAlunos * sizeof(Aluno));
    for (int i = 0; i < lenAlunos; i++) {
        alunos[i].notas = malloc(lenNotas * sizeof(int));
    }

    printf("---------------------------------------\n");
    for (int i = 0; i < lenAlunos; i++) {
        printf("digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, MAX_NOME, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        for (int j = 0; j < lenNotas; j++) {
            printf("digite e a nota %d: ", j + 1);
            scanf("%d", &alunos[i].notas[j]);
            cleanBuffer();
        }
    }
    
    int *numeroNotas = malloc(lenAlunos * sizeof(int));
    for (int i = 0; i < lenAlunos; i++) {
        numeroNotas[i] = lenNotas;
    }

    printAlunos(alunos, lenAlunos, numeroNotas);

    int op;
    do {
        printf("---------------------------------------\n");
        printf("1 - adicionar nova nota a aluno\n");
        printf("2 - calcular média dos alunos\n");
        printf("3 - imprimir lista de notas e alunos\n");
        printf("0 - sair\n");
        printf("---------------------------------------\n");
        scanf("%d", &op);
        cleanBuffer();

        switch (op) {
        case 1: {
            
            int aluno;
            printf("digite qual aluno deseja adicionar nova nota (0 - %d): ", lenAlunos - 1);
            scanf("%d", &aluno);
            cleanBuffer();
            if (aluno < 0 || aluno > lenAlunos - 1) {
                printf("esse aluno não existe no sistema!");
                break;
            }

            int add;
            printf("digite a quantidade de notas que deseja adicionar: ");
            scanf("%d", &add);
            cleanBuffer();

            addNota(alunos, aluno, numeroNotas, add);

            break;
        }
        case 2:
            calcularMedia(alunos, lenAlunos, numeroNotas);

            break;
        case 3:
            printAlunos(alunos, lenAlunos, numeroNotas);
            break;
        case 0:
            printf("encerrando sistema...\n");
        default:
            printf("opção inválida!");
        }

    } while (op != 0);
   
    for (int i = 0; i < lenAlunos; i++) {
        free(alunos[i].notas);
    }
    free(alunos);
    free(numeroNotas);

    return 0;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addNota(Aluno *alunos, int aluno, int *numeroNotas, int add) {
    int newLen = numeroNotas[aluno] + add;

    int *temp = realloc(alunos[aluno].notas, newLen * sizeof(int));
    if (!temp) {
        printf("não foi possível realocar memória");
        return;
    }
    alunos[aluno].notas = temp;

    for (int i = numeroNotas[aluno]; i < newLen; i++) {
        printf("digite a nota %d: ", i + 1);
        scanf("%d", &alunos[aluno].notas[i]);
        cleanBuffer();
    }

    numeroNotas[aluno] = newLen;
}

void calcularMedia(Aluno *alunos, int lenAlunos, int *numeroNotas) {
    int sum;

    printf("\n médias: \n");
    for (int i = 0; i < lenAlunos; i++) {
        sum = 0;

        for (int j = 0; j < numeroNotas[i]; j++) {
            sum += alunos[i].notas[j];
        }
        float avg = (float) sum / numeroNotas[i];

        printf("aluno %d: %.2f\n", i + 1, avg);
    }
}

void printAlunos(Aluno *alunos, int lenAlunos, int* numeroNotas) {
    printf("---------------------------------------\n");
    for (int i = 0; i < lenAlunos; i++) {
        printf("%d - aluno: %s\n", i + 1, alunos[i].nome);
        for (int j = 0; j < numeroNotas[i]; j++) {
            printf("nota %d - %d\n", j + 1, alunos[i].notas[j]);
        }
    }
    printf("---------------------------------------\n");
}