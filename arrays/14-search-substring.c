/*
dada uma determinada frase, verifique se existe correspondência com uma determinda substring
*/
#include <stdio.h>
#include <stdbool.h>

bool contemPalavra(const char *frase, const char *palavra) {
    const char *p1 = frase;

    while (*p1 != '\0') {
        const char *p2 = palavra;
        const char *p3 = p1;

        while (*p2 != '\0' && *p2 == *p3) {
            p2++;
            p3++;
        }

        if (*p2 == '\0') {
            return true;
        }

        p1++
    }

    return false;
}

int main() {
    return 0;
}
/*
queremos verificar se palavra aparece dentro de frase, em qualquer posição, como uma substring contínua

se lembre que não podemos copiar o conteúdo de uma string para outro local da memória fazendo uma atribuição direta! para isso, usamos strcpy para fazer a cópia do conteúdo original para o destino

mas podemos sim apontar para o mesmo conteúdo, sem copiar. fazemos isso com atribuição de ponteiros
char *a
char *b = "algoritmos" // b é um ponteiro que apontar para memória somente leitra
a = b // agora a aponta para a mesma string que b
nenhum conteúdo foi copiado. como a e b são ponteiros, podemos armazenar endereços de memória

* use strcpy quando
    * você vai modificar a string destino
    * precisa de cópias independentes
    * a variável de destino é um array fixo, não um ponteiro simples

* use atribuição de ponteiros quando
    * você só precisa ler/acessar os dados
    * não vai modificar o conteúdo apontado
    * quer usar ponteiros auxiliares para percorrer ou comparar strings!!


lógica por trás do contemPalavra:
* p1 percorre a frase caractere por caractere, como um cursor e em cada posição de p1, ele verifica se ali começa a palavra com a iteração do laço externo que continua enquanto a string é válida e ao final sempre incrementa p1 para o próximo caractere na frase

* o laço interno compara caractere por caractere a partir de dois cursores, p2 que corresponde ao ponteiro que aponta para a palavra a ser verificada, e p3, um ponteiro auxiliar que começa na posição atual de p1
    * enquanto p2 ainda é válida e não terminou, verificamos correspondência entre os caracteres apontados entre p2 e p3
    * o loop continua enquanto os caracteres forem iguais e não chegarmos ao final da palavra

* a condição de sucesso só pode ocorrer se, ao sair do loop de correspondência anterior, o cursor p2 agora aponta para o terminador nulo, porque isso significa que percorreu caractere por caractere de palavra em sequência na frase e achou correspondência sem sair do laço
    * isso é o que garante que o retorno da função seja true

* se a subtring não bateu, o ponteiro p1 avança e tudo começa de novo. isso é basicamente o padrão de deslizamento de janela (sliding window)
*/