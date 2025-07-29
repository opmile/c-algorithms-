#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float nota;
} Aluno;

/*
* precisamos conferir se o elemento a ser removido está realmente na lista. fazemos isso iterando sobre o vetor de alunos até que encontremos correspondência
    * caso não haja correspondência, retornamos a função imediatamente
    * caso haja, com o break no loop agora temos um ponteiro que aponta exatamente para onde está o elemento a ser removido

* sabendo onde está o elemento a ser removido, devemos realizar o movimento de deslocamento para a esquerda, de modo a "tapar o buraco" do elemento a ser removido

* por fim, devemos decrementar o valor da variável tamanho, e com uma casa sobrando à esquerda, realocamos a memória dinamicamente do vetor de alunos, para que assim tenhamos manutenção da ordem dos elementos e da integridade do vetor

* obs: a variável tamanho n deve ser passada como ponteiro, isso porque não queremos passar o valor (cópia) mas fazer a modificação perdurar fora da função, e por isso passamos por referência
*/

Aluno *removerAluno(Aluno *alunos, int *n, int idx) {
    int i;

    bool found = false;
    for (i = 0; i < *n; i++) {
        if (alunos[i] == alunos[idx]) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("não achamos esse aluno na base de dados");
        return NULL;
    }

    for (int j = i; j < *n - 1; j++) { // -1 para não acessar elemento fora do índice
        alunos[j] = alunos[j + 1];
    }

    (*n)--;
    Aluno *temp = realloc(alunos, (*n) * sizeof(Aluno));
    if (!temp && *n > 0) {
        perror("erro ao realocar");
        exit(1);
    }
    alunos = temp;

    return alunos;
}
/*
!temp && *n > 0 serve para diferenciar dois cenários completamente distintos quando realloc retora NULL

ao pedir para realocar para tamanho 0, o comportamente depende da implementação
* algumas retornaram NULL
* outras retornam um ponteiro válido que não deve ser desreferenciado

se a realocação faz virar vetor = realloc (vetor, 0), e essa realocação retorna NULL, você não sabe se
* deu erro de realocação de memória 
    se *n > 0 e novo_vetor == NULL, é um erro real.
* ou foi apenas o comportamento normal do realloc(0)
    se *n == 0 e novo_vetor == NULL, é esperado, não precisa tratar como falha
*/

int main() {

    return 0;
}