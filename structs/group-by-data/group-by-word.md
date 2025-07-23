### **contar palavras com struct** 
> crie uma função que recebe uma string e conta a frequência de cada palavra, armazenando em uma `struct Palavra { char texto[50]; int freq; }`
> armazene todas as palavras diferentes em um vetor de `struct Palavra` dinâmico

**o que precisa ser feito**
1. receber uma string com várias palavras
2. separar as palavras -- token
3. criar uma `struct Palavra` com
```c
typedef struct {
    char texto[50];
    int fre1;
} Palavra;
```
4. usar um vetor dinâmico de `Palavra` para armazenar as palavras únicas
5. se uma palavra já existe, incrementar sua frequencia
6. se não existe, adicioná-la ao vetor com frequência 1
7. no final, imprimir as palavras com suas frequências


```c
// inicializar o vetor de palavras e seu tamanho com 0

// criar uma copia da frase

// com a copia, tokenizar a frase

// iterar a frase em um loop, enquanto não percorrermos todos os tokens (token != NULL)
// conferir se aquela palavra já foi adicionada no vetor (strcmp)
//     se foi adicionada, incrementar sua frequencia e dar break
//     se não foi adicionada:
//         * realocar espaço do vetor para caber mais uma palavra
//         * copiar (strcpy) token para a ultima posição
//         * definir a frequência do token para 1
//         * incrementar o tamanho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN

typedef struct {
    char texto[MAX_LEN];
    int freq;
} Palavra;

void contarPalavras(const char *frase) {
    Palavra *vetor = NULL;
    int len = 0;

    char *copia = malloc(strlen(frase) + 1);
    if (!copia) {
        printf("impossível alocr memória");
        return;
    }

    strcpy(copia, frase);

    char *token = strtok(copia, " \n");

    bool found = false;
    while (token != NULL) {
        
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(token, vetor[i].texto) == 0) {
                found = true;
                vetor[i].freq++;
                break;
            }
        }

        if (!found) {
            char *temp = realoc(vetor, (tamanho + 1) * sizeof(Palavra));
            if (!temp) {
                printf("não foi possível realocar memória");
                free(copia);
                free(vetor);
                return;
            }

            strcpy(vetor[tamanho], token);
            vetor[tamanho].freq = 1;
            tamanho++;
        }


        token = strtok(NULL, " \n");
    }

    printf("palavras encontradas: \n");
    for (int i = 0; i < tamanho; i++) {
        printf(" - %s -> freq.: %d\n", vetor[i].texto, vetor[i].freq);
    }

    free(vetor);
    free(copia);

}

int main() {
    return 0;
}

```