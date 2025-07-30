#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 70
#define MAX_CURSO 50

typedef struct {
    char nome[MAX_NOME];
    char curso[MAX_CURSO];
    int *notas;
    int qtdNotas;
} Aluno;

typedef struct {
    char nome[MAX_CURSO];
    Aluno *alunos;
    int qtd;
} Curso;

/*
o vetor de nomesCursos é um vetor de strings (char**)
iterar sobre todos os alunos
analisar correspondência entre o curso atual e os cursos já registrados no vetor de nomesCursos. se não houver correspondência, esse curso ainda não existe no vetor e deve ser adicionado
para ser adicionado, temos que realocar o vetor de nomesCursos para comportar mais um curso. como nomes cursos é um array de strings, depois da realocação, o que temos é apenas mais um espaço com um ponteiro não inicializado, por isso, devemos inicializar esse ponteiro para se comportar como um array de char (string) comportando a quantidade exata de caracteres necessários com strlen
*/
char *extrairCursos(Aluno *alunos, int totalAlunos, int *totalCursos) {
    char **nomesCursos = NULL;
    int qtd = 0;

    for (int i = 0; i < totalAlunos; i++) {
        bool found = false;

        for (int j = 0; j < qtd; j++) {
            if (strcmp(alunos[i].curso, nomesCursos[j]) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            char **temp = realloc(nomesCursos, (qtd + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível inserir novo curso");
                break;
            }
            nomesCursos = temp;

            nomesCursos[qtd] = malloc(strlen(alunos[i].curso) + 1);
            strcpy(nomesCursos[qtd], alunos[i].curso);
            qtd++;
        }
    }
    *totalCursos = qtd;
    return nomesCursos;
}

Curso *agruparPorCurso(Aluno *alunos, int totalAlunos) {
    int totalCursos;
    char **nomesCursos = extrairCursos(alunos, totalAlunos, &totalCursos);

    Curso *cursos = malloc(totalCursos * sizeof(Curso));
    if (!cursos) {
        perror("erro ao alocar vetor de cursos");
        exit(1);
    }

    for (int i = 0; i < totalCursos; i++) {
        strcpy(cursos[i].nome, nomesCursos[i]);
        cursos[i].alunos = NULL;
        cursos[i].qtd = 0;
    }

    // checar correspondência entre aluno atual e vetor de cursos. quando encontrar, adicionar esse aluno ao vetor de cursos
    for (int i = 0; i < totalAlunos; i++) {
        for (int j = 0; j < totalCursos; j++) {
            if (strcmp(alunos[i].curso, cursos[j].nome) == 0) {
                int pos = cursos[j].qtd;
                Aluno *temp = realloc(cursos[j].alunos, (pos + 1) * sizeof(Aluno));
                if (!temp) {
                    printf("impossível realocar memória para aluno %s\n", alunos[i].nome);
                    break;
                }
                cursos[j].alunos = temp;

                cursos[j].alunos[pos] = alunos[i];
                cursos[j].qtd++;
                break; // já identificamos a qual curso o aluno atual pertence
            }
        }
    }

    for (int i = 0; i < totalCursos; i++) {
        free(nomesCursos[i]);
    }
    free(nomesCursos);

    return cursos;
}

void imprimirPorCurso(Curso *cursos, int totalCursos) {
    for (int i = 0; i < totalCursos; i++) {
        printf("\nCurso: %s\n", cursos[i].nome);
        for (int j = 0; j < cursos[i].qtd; j++) {
            printf("%d -- %s", j + 1, cursos[i].alunos[j].nome);
        }
    }
}

void calcularMediaGeral(Curso *cursos, int totalCursos) {
    printf("Médias Globais por Curso: \n");

    for (int i = 0; i < totalCursos; i++) { // para cada curso
        
        int sumCurso = 0;
        for (int j = 0; j < cursos[i].qtd; j++) { // para cada aluno
            
            int sumAluno = 0;
            for (int k = 0; k < cursos[i].alunos[j].qtdNotas; k++) { // itera sobre cada nota
                sumAluno += cursos[i].alunos[j].notas[k];
            }

            float mediaAluno = (float) sumAluno / notasSemestre;
            sumCurso += mediaAluno;
        }

        float mediaGlobal = (float) sumCurso / cursos[i].qtd;

        printf("Média Global %s: %.2f\n", cursos[i].nome, mediaGlobal);
    }
}
/*
calcular media global do curso = 
media aluno = soma das notas de cada aluno / qtd notas do semestre
media do curso = soma das medias de cada aluno / qtd de alunos matriculados no curso
*/

int main() {
    
    return 0;
}