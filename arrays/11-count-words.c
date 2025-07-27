#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// contar quantas vezes cada palavra aparece em uma string

#define MAX_PALAVRA 30

typedef struct {
    char palavra[MAX_PALAVRA];
    int freq;
} Palavra;

void contarPalavras(char *str) {
    Palavra *array = NULL; // vetor para armazenar as palavras únicas
    int len = 0;

    char *copy = malloc(strlen(str) + 1);
    if (!copy) {
        printf("impossível realizar cópia do texto");
        return;
    }
    strcpy(copy, str);

    char *token = strtok(copy, " \n");

    while (token != NULL) {
        
        bool found = false;
        for (int i = 0; i < len; i++) { // compara token com todas as palavras do vetor
            if (strcmp(token, array[i].palavra) == 0) {
                found = true;
                array[i].freq++;
                break;
            }
        }

        if (!found) {
            Palavra *temp = realloc(array, (len + 1) * sizeof(Palavra));
            if (!temp) {
                printf("não foi possível adicionar nova palavra");
                return;
            }
            array = temp;

            strcpy(array[len].palavra, token);
            array[len].freq = 1;
            len++;
        }
        token = strtok(NULL, " \n");
    }

    printf("palavras encontradas: \n");
    for (int i = 0; i < len; i++) {
        printf("%s -- %d\n", array[i].palavra, array[i].freq);
    }

    free(array);
    free(copy);
}

// contar quantas vezes uma palavra específica aparece em uma string

/*
1. declarações
* count - contador de ocorrências da palavra (incrementado toda vez que acharmos correspondência)
* lenPalavra - o comprimento da palavra que estamos buscando
* i - ponteiro que percorre cada caractere da frase do início ao fim

2. loop principal - percorre cada caractere da frase
enquanto a o elemento apontado por i na frase for diferente do terminador nulo (isto é, enquanto a string for válida)
* em cada posição da frase, vamos verificar se a palavra começa ali
* deve ocorrer incrementação manual de i ao final do loop

3. verifica se a palavra começa na posição i
int j = 0
while (frase[i + j] == palavra[j] && palavra[j] != '\0') j++

* compara caractere por caractere (incrementação de j) entre a palavra e a frase, a partir do ponteiro i
* se todos os caracteres da palavra coincidirem com os da frase, j chegará a lenPalavra
* se algum caractere não bater, o loop encerra - ou seja, a palavra não está ali
* se na checagem chegamos ao fim dos caracteres válidos da palavra, o loop também encerra

4. verificar se a palavra está isolada (não grudada com outras letras!)
condição 1: j == lenPalavra
isso confirma que todos os caracteres da palavra bateram com a frase

* char anterior -> verifica o caractere anterior
    * se estamos na posição 0 da frase i == 0 (inicio da string), o anterior não existe, então armazena um espaço vazio
    * caso contrário, pegamos o caractere antes de onde a palavra começou
        queremos garantir que esse "anterior" não seja uma letra - e sim:
        * um espaço (isspace)
        * uma pontuação (ispunct)
        * ou o início da string

* da mesma forma, char proximo -> verifica o caractere posterior
    * esse deve ser o caractere logo depois da palavra
    ele tamém precisa ser
    * um espaço (isspace)
    * uma pontuação (ispunct)
    * ou o fim da string (\0)

se os dois lados estão limpos, ou seja, delimitam uma palavra completa, então a palavra está isolada e podemos incrementar o contador count++

5. o final do loop deve garantir que o ponteiro i esteja percorrendo toda a string, caractere por caractere com i++
    * após cada tentativa, mesmo que não tenha dado match, seguimos para o próximo caractere
*/
int contarPalavra(char *str, char *substr) {
    int count = 0;
    int i = 0;
    int lenSubstring = strlen(substr);

    while (str[i]) {

        int j = 0;
        while (str[i + j] == substr[j] && substr[j] != '\0') { // verifica se a substring começa em i
            j++; // se começa, começa a verificação incrementando j
        }

        // ao final da verificação j deve ser igual ao comprimento da string
        if (j == lenSubstring) {
            char last = (i == 0) ? ' ' : str[i - 1];
            char next = str[i + j];

            if (isspace(last) || ispunct(last)) {
                if (isspace(next) || ispunct(next) || next == '\0') {
                    count++;
                }
            }
        }
        i++;
    }
}

int main() {
    return 0;
}