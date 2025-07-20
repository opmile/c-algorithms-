#include <stdio.h>
#include <stdlib.h>

void addGrade(int **system, int student, int* numGrades, int newGrades);

void calculteAvg(int **system, int strudes, int* numGrades);

void printSystem(int **system, int students, int* numGrades);

int main() {
    int students;
    int grades;

    printf("--------------------------------\n");
    printf("cadastro de notas dos estudantes\n");
    printf("--------------------------------\n");

    printf("alunos no semestre: ");
    scanf("%d", &students);
    getchar();

    printf("quantidade de notas avaliadas no semestre: ");
    scanf("%d", &grades);

    int **system = malloc(students * sizeof(int*));
    for (int i = 0; i < students; i++) {
        system[i] = malloc(grades * sizeof(int));
    }

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < grades; j++) {
            printf("digite a nota %d do estudante %d: ", j + 1, i + 1);
            scanf("%d", &system[i][j]);
        }
    }

    int *numGrades = malloc(students * sizeof(int));
    for (int i = 0; i < students; i++) {
        numGrades[i] = grades;
    }
 
    printf("--------------------------------\n");
    printf("notas dos estudantes cadastrados: \n");
    printSystem(system, students, numGrades);
    printf("--------------------------------\n");

    int op;
    do { 
        printf("menu\n");
        printf("1 - adicionar nova nota a um estudante\n");
        printf("2 - calcular média\n");
        printf("3 - imprimir lista de notas\n");
        printf("0 - sair\n");
        printf("opção: ");

        scanf("%d", &op);

        switch (op) {
            case 1: {
                int student, newGrades;

                printf("digite o aluno a ser alterado (0 a %d): \n", students - 1);
                scanf("%d", &student);
        
                printf("digite a quantidade de notas a serem adicionadas: \n");
                scanf("%d", &newGrades);
        
                addGrade(system, student, numGrades, newGrades);
                break;
            }
            case 2:
                calculteAvg(system, students, numGrades);
                break;
            case 3:
                printSystem(system, students, numGrades);
                break;
            }
    } while (op != 0);

    for (int i = 0; i < students; i++) {
        free(system[i]);
    }
    free(system);
    free(numGrades);

    return 0;
}

void printSystem(int **system, int students, int* numGrades) {
    printf("{\n");
    for (int i = 0; i < students; i++) {
        printf("  { ");
        for (int j = 0; j < numGrades[i]; j++) {
            printf("%d", system[i][j]);
            if (j < numGrades[i] - 1) printf(", ");
        }
        printf(" }%s\n", i < students - 1 ? "," : "");
    }
    printf("}\n");
}

void calculteAvg(int **system, int students, int* numGrades) {
    int sum = 0;

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < numGrades[i]; j++) {
            sum += system[i][j];
        }
        float avg = (float) sum / numGrades[i];
        printf("aluno %d com média: %.1f\n", i + 1, avg);
    }
}

void addGrade(int **system, int student, int* numGrades, int newGrades) {
    int totalGrades = numGrades[student] + newGrades;

    system[student] = realloc(system[student], totalGrades * sizeof(int));

    if (system[student] == NULL) {
        perror("erro ao alocar memória");
        return;
    }

    for (int i = numGrades[student]; i < totalGrades; i++) {
        printf("digite a nota %d:\n", i + 1);
        scanf("%d", &system[student][i]);
    }

    numGrades[student] = totalGrades;
}

/*
o vetor auxiliar numGrades
ele é a chave para que o sistema funcione quando cada aluno pode ter uma quantidade diferente de notas - especialmente depois de você usar realloc() para adicionar novas notas a alunos individualmente

é simplemene um vetor de inteiros que armazena, para cada aluno, quantas notas ele tem atualmente

se lembre que C não guarda quantos elementos tem cada vetor de alunos (system[i]) - ele só te da o ponteiro

se quisermos iterar corretamente sobre cada vetor de notas, você precisa saber quantas notas existem ali. e esse número muda a cada vez que fazemos um realloc para adicionar novas notas
*/

