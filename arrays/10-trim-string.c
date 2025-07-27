/*
dada uma string, queremos
* remover espaços no início e no fim
* substituir múltiplos espaços entre palavras por um único
* queremos uma solução in-place, mais eficiente em termos de memória

1. ignorar espaços no início enquanto não encontramos o primeiro caractere "real"
ex) "  abc" -> pulamos os espaços iniciais até chegar no 'a'
* isspace() é uma função de <ctype.h> e verifica se o caractere é espaço, tab, quebra de linha etc.

2. começamos a copiar para o início da string
usamos duas variáveis:
* i -> percorre toda a string original (leitor)
* j -> constrói a nova string, limpando os espaços (escritor)

a cada caractere:
* se for letra ou número, copiamos
* se for espaço
    * só copiamos se o caractere anterior não foi um espaço (para evitar múltiplos)

3. depois do loop, verificamos se a string terminou com espaço
ex) "abc   " -> o espaço no final é desnecessário, então o tiramos
* se terminou com espaço, ajustamos o ponteiro j para apontar justamente para onde o terminador nulo deve ser inserido

4. finalizamos com o caractere nulo \0
* isso marca o fim da nova string, limpinha
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void removeEspacosDuplicadosCompleta(char *str) {
    int i = 0; // index para percorrer a string original -> leitura
    int j = 0; // index para construir a nova string limpa -> escreve
    bool ultimoEspacoFoiAdicionado = false; // indica se o último caractere adicionado foi um espaço

    // pular espaços iniciais
    while(str[i] != '\0' && str[i] == ' ') { // -> while (str[i] && str[i] == ' ')
        i++; // avança enquanto encontrar espaços no início
    }
    // j espera em sua posição original para a escrita

    // enquanto não chegar no fim da string
    while (str[i] != '\0') { // -> == while (str[i])
        if (str[i] != ' ') { // se o caractere atual for diferente de espaço
        str[j] = str[i]; // copia o caractere
        j++; // avança o índice de escrita
        ultimoEspacoFoiAdicionado = false; // o último caractere adicionado NÃO foi espaço
        } else { // se o caractere atual é um espaço
            if (ultimoEspacoFoiAdicionado == false) { // e se o último caractere adicionado não foi um espaço
                str[j] = ' '; //  adiciona apenas UM espaço
                j++; // avança o índice de escrita
                ultimoEspacoFoiAdicionado = true; // marca que um espaço foi adiconado
            }
            // se ultimoEspacoFoiAdicionado já é true, não faz nada (ignora o espaço duplicado)
        }
        i++; // avança para o próximo caractere da string original
    }

    // remover espaço final, se tiver
    if (j > 0 && str[j - 1] == ' ') {
        j--; // remove o espaço final recuando uma posição
    }
    str[j] = '\0';
}
/*
(j > 0 && str[j - 1] == ' ')
durante a copia dos caracteres, estamos reescrevendo a string original no próprio buffer (str[j] = str[i])
* o ponteiro j representa a próxima posição de escrita
* a cada escrita, j é incrementado
* se não foi adicionado um espaço anterior, j é incrementado
* então str[j - 1] é o último caractere que foi escrito
* é esperado que, ao final da iteração (str[i] != '\0'), i aponta para o terminador nulo e j aponta para a próxima posição disponível de escrita
    * se o último caractere válido que escrevemos foi uma letra -> str[j] será a posição do \0 porque foi foi incrementado no bloco
    * se o último caractere válido que escrevemos foi um espaço indesejado ao final -> esse caractere terá sido escrito em str[j - 1]
* enquanto isso, i já percorreu toda a string original, e está apontando para \0

essa linha:
* verifica se pelo menos um caractere foi escrito (j > 0)
* verifica se o último caractere escrito foi um espaço (str[j - 1] == ' ')
* se verdadeiro ele recua uma posição, apontando agora para um caractere não nulo
*/

void removeEspacosDuplicadosEnxuta(chr *str) {
    int i, j;
    i = 0;
    j = 0;
    espacoAdicionado = false;

    // ignorar espaços no começo
    while (isspace(str[i])) {
        i++;
    }

    bool espacoAdicionado = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i++];
            espacoAdicionado = false;
        } else {
            if (!espacoAdicionado) {
                str[j++] = ' ';
                espacoAdicionado = true;
            }
            i++;
        }
    }

    if (j > 0 && str[j - 1] = ' ') {
        j--;
    }
    str[j] = '\0';
}

int main() {
    char frase[] = "  isso   é   um    teste ";
    
    removeEspacosDuplicadosEnxuta(frase);
    
    printf("\"%s\"\n", frase);

    return 0;
}
