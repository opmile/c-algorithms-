#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
reverter cada palavra da string individualmente, sem mudar a ordem das palavras

* devemos percorrer a string do início ao fim
* quando encontrarmos o início de uma palavra, salvamos o ponteiro (esse será o ponteiro start)
* continuamos a iteração até chegar no fim da palavra (um espaço ou terminador nulo)
    * a posição anterior indica o fim da palavra (esse será o ponteiro end)
* daí invertemos os caracteres de start até end - 1
* fazemos isso enquanto a string é válida (diferente de \0)

* esse exercício exige consciência e entendimento de manipulação de ponteiros com strings!

* aplicamos uma variação da técnica de sliding window (estamos manipulando uma janela sobre um estrutura sequencial e deslocando início e fim dessa janela conforme uma condição) 
    * aqui definiremos dinamicamente uma janela delimitada por dois ponteiros (start e end), baseada em um critério (espaços - já que marcam o fim de cada palavra)
    * e estamos realizando uma operação apenas dentro dessa janela, movendo-a conforme avançamos na string
*/

// função auxiliar de inverte todos os caracteres de start a end
/*
start e end são ponteiros que apontam para o endereço do primeiro e último caractere da string, por isso, não precisamos que nossa função receba diretamente o ponteiro base da string para manipulação
*/
void reverseRange(char *start, char *end) { 
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// aqui usaremos os ponteiros start e a própria string para fazer a manipulação
void reverseEachWord(char *str) {
    char *start = str;

    while (*str) {
        // pular espaços
        while (*str && isspace(*str)) str++;
        start = str; // marca o início da palavra

        // vai até o fim da palavra
        while (*str && !isspace(*str)) str++;

        // str aponta para o primeiro espaço ou para o terminador nulo
        reverseRange(start, str - 1);
    }
}

int main() {
    return 0;
}