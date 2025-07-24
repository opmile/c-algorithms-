#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CURSO 30

typedef struct {
    char nome[MAX_NOME];
    char curso[MAX_CURSO];
} Aluno;

typedef struct {
    char nome[MAX_CURSO];
    Aluno *alunos;
    int qtd;
} Curso;

char **extrairCursos(Aluno *a, int totalAlunos, int *outCount);
void agruparPorCurso(Aluno *a, int totalAlunos);

int main() {
    int totalAlunos;
    printf("digite quantos alunos deseja matricular: ");
    scanf("%d", &totalAlunos);
    getchar();

    Aluno *alunos = malloc(totalAlunos * sizeof(Aluno));

    for (int i = 0; i < totalAlunos; i++) {
        char nome[MAX_NOME];
        printf("digite o nome do aluno %d: ", i + 1);
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        char curso[MAX_CURSO];
        printf("digite o curso matriculado do aluno %d: ", i + 1);
        fgets(curso, MAX_CURSO, stdin);
        curso[strcspn(curso, "\n")] = '\0';

        strcpy(alunos[i].nome, nome);
        strcpy(alunos[i].curso, curso);
    }

    printf("{");
    for (int i = 0; i < totalAlunos; i++) {
        printf(" %s - %s", alunos[i].nome, alunos[i].curso);
        if (i < totalAlunos - 1) printf(", \n");
    }
    printf(" }\n");

    agruparPorCurso(alunos, totalAlunos);

    return 0;
}

char **extrairCursos(Aluno *a, int totalAlunos, int *outCount) {
    char **nomesCursos = NULL;
    int qtd = 0;

    for (int i = 0; i < totalAlunos; i++) {
        char *atual = a[i].curso;
        bool achou = false;

        for (int j = 0; j < qtd; j++) {
            if(strcmp(atual, nomesCursos[j]) == 0) {
                achou = true;
                break;
            }
        }

        if (!achou) {
            char **temp = realloc(nomesCursos, (qtd + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar memória");
                break;
            }

            nomesCursos = temp;
            
            nomesCursos[qtd] = malloc(strlen(atual) + 1);
            strcpy(nomesCursos[qtd], atual);
            qtd++;
        }
    }
    *outCount = qtd;
    return nomesCursos;
}

void agruparPorCurso(Aluno *a, int totalAlunos) {
    int totalCursos;
    char **nomesCursos = extrairCursos(a, totalAlunos, &totalCursos);

    Curso *cursos = malloc(totalCursos * sizeof(Curso));
    for (int i = 0; i < totalCursos; i++) {
        strcpy(cursos[i].nome, nomesCursos[i]);
        cursos[i].alunos = NULL;
        cursos[i].qtd = 0;
    }  

    for (int i = 0; i < totalAlunos; i ++) {
        for (int j = 0; j < totalCursos; j++) {
            if (strcmp(a[i].curso, cursos[j].nome) == 0) {
                int pos = cursos[j].qtd;
                Aluno *temp = realloc(cursos[j].alunos, (pos + 1) * sizeof(Aluno));
                if (!temp) {
                    printf("não foi possível realocar memória");
                    return;
                }
                cursos[j].alunos = temp;
                
                cursos[j].alunos[pos] = a[i];
                cursos[j].qtd++;
                break;
            }
        }
    }

    for (int i = 0; i < totalCursos; i++) {
        printf("\n curso: %s --- %d\n", cursos[i].nome, cursos[i].qtd);
        for (int j = 0; j < cursos[i].qtd; j++) {
            printf(" - %s\n", cursos[i].alunos[j].nome);
        }
    }

    for (int i = 0; i < totalCursos; i++) {
        free(cursos[i].alunos);
        free(nomesCursos[i]);
    }
    free(cursos);
    free(nomesCursos);
}