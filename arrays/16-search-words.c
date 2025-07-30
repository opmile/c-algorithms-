#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
1. construir uma função que analisa se a palavra tem o prefixo 

2. construir uma função de busca que retorna um novo array de strings contendo as strings que contem o prefixo
    * essa função deve analisar, para cada string do array, correspondência chamando a função que analisa se contem o prefixo 

*/

// com sliding window - permite verificar uma substring em qualquer posição da string
bool contemPalavra(const char *palavra, const char *prefixo) {
    while(*palavra) {
        const char *p1 = prefixo;
        const char *p2 = palavra;

        while (*p1 && *p2 && tolower(*p1) == tolower(*p2)) {
            p1++;
            p2++;
        }

        if (*p1 == '\0') {
            return true;
        }

        palavra++;
    }
    return false;
}

// outra forma de implementar
bool contemPalavra2(const char *palavra, const char *prefixo) {
    const char *p1 = palavra;

    while (*p1) {
        const char *p2 = prefixo;
        const char *p3 = p1; // não precisamos verificar validade, porque aponta para p1, que já checa validade no loop externo

        while (*p2 && *p2 == *p3) {
            p2++;
            p3++;
        }

        if (!*p2) { // *p2 == '\0'
            return true;
        }

        p1++;
    }
    return false;
}

// se sliding window - permite verificar apenas o começo da string (correspondência com o prefixo)
/*
lógica de contemPrefixo:

a única diferença entre as duas implementaçãoes é o loop externo, em que na primeira implementação, permitia descolar a verificação ao longo da palavra (sliding window). isso é o que faz verificar se uma substring está contida EM QUALQUER POSIÇÃO da string original
* com o loop externo: a função tenta várias "janelinhas" dentro da palavra, verificando se o prefixo bate ali
* sem o loop externo: só verifica se a primeira janelinha da palavra já bate com o prefixo

se removemos esse loop, não andamos na palavra, só comparamos do início da palavra até o fim do prefixo - ou seja, estamos verificando exatamente se o prefixo está no início da palavra

* só comparamos o começo da palavra com o prefixo
* se o prefixo bater completamente, retorna true
* se tiver qualquer letra errada logo no inicio -> false

enxugamos também os ponteiros intermediários usados na lógica anterior. isso porque precisamos preservar palavra e frase intactos entre tentativas (enquanto estamos deslizando nossa janela) - por isso usamos p1 e p2 para fazer a comparação sem perder a posição do ponteiro original
*/

bool contemPrefixo(const char *palavra, const char *prefixo) {
    while (*palavra && *prefixo && tolower(*prefixo) == tolower(*palavra)) {
        palavra++;
        prefixo++;
    }

    if (!*prefixo) {
        return true;
    }
    return false;
}


/*
lógica de buscarPrefixo:

* inicializar variáveis: palavrasPrefixo, tamanho
1. para cada elemento em palavras, verificar se o elemento contem o prefixo
2. se conter o prefixo, teremos que realocar espaço de palavrasPrefixo a partir do tamanho + 1
3. como se trata de um array de strings (ponteiros), precisamos inicializar o novo ponteiro alocado para conter o tamanho da string de análise atual a ser inserida (strlen)
4. agora na última posição do array palavrasPrefixo, que está sendo indicada por tamanho, copiamos para esse destino o conteúdo da string de análise atual 
5. devemos incrementar o tamanho para garantir inserções futuras
*/
char **buscarPrefixo(char **palavras, int n, char *prefixo, int *outCount) {
    char **palavrasPrefixo = NULL;
    int nPref = 0;

    for (int i = 0; i < n; i++) {
        if (contemPrefixo(palavras[i], prefixo)) {
            char **temp = realloc(palavrasPrefixo, (nPref + 1) * sizeof(char*));
            if (!temp) {
                printf("não foi possível realocar para inserção de %s\n", palavras[i]);
                break;
            }
            palavrasPrefixo = temp;

            palavrasPrefixo[nPref] = malloc(strlen(palavras[i]) + 1);
            strcpy(palavrasPrefixo[nPref], palavras[i]);
            nPref++;
        }
    }
    *outCount = nPref;
    return palavrasPrefixo;
}

int main() {
    char *lista[] = {"Algoritmo", "Algebra", "algema", "Estrutura"};
    int n;
    char **result = buscarPrefixo(lista, 4, "alg", &n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", result[i]);
    }

    free(result);

    return 0;
}