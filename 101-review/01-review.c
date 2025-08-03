#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void imprimitArrInt(const int *arr, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}


// 01
int stringLen(const char *str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

// 02
bool ehPalindromoInt(const int *arr, int n) {
    int left = 0;  
    int right = n - 1;

    while (left < right) {
        if (arr[left] != arr[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool ehPalindromo(const char *str) {
    int left = 0;
    int right = strlen(str);

    while (left < right) {
        if (str[left] != str[right]) return false;

        left++;
        right--;
    }
    return true;
}

// 03
void reverse(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// rotacao para esquerda (counter-clockwise)
// inverte tudo por último
void rotateLeft(int *arr, int n, int k) {
    reverse(arr, k, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, 0, n - 1);
}

// rotacao para direita (clockwise)
// inverte tudo primeiro
void rotateRight(int *arr, int n, int k) {
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}


// 04
// array temporario
int *removeDuplicates(const int *arr, int n, int *outCount) {
    int *uniques = NULL;
    int newN = 0;

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < newN; j++) {
            if (arr[i] == uniques[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            // cppcheck-suppress cstyleCast
            int *temp = (int*)realloc(uniques, (newN + 1) * sizeof(int));
            if (!temp) {
                printf("impossível realocar memória");
                return NULL;
            }
            uniques = temp;

            uniques[newN] = arr[i];
            newN++;
        }
    }
    *outCount = newN;
    return uniques;
}

// in-place
int  *removeDuplicates2(int *arr, int *n) {
    int pos = 0;
    
    for (int i = 0; i < *n; i++) {
        int j;
        for (j = 0; j < pos; j++) {
            if (arr[i] == arr[pos]) {
                break;
            }
        }

        if (j == pos) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    // cppcheck-suppress cstyleCast
    int *temp = (int*)realloc(arr, pos * sizeof(int));
    if (!temp) {
        printf("impossível redimensionar o vetor");
        return NULL;
    }
    arr = temp;

    *n = pos;
    return arr;
}


// 05
int **contarFrequencia(int *arr, int len, int *lenMatriz) {
    int lns = 0;
    int **matriz = NULL;

    // cppcheck-suppress cstyleCast
    bool *checked = (bool*)malloc(len * sizeof(bool));
    if (!checked) {
        printf("impossível contar freqência!");
        return NULL;
    }

    for (int i = 0; i < len; i++) {

        if (checked[i]) {
            continue;
        }
        int count = 1;

        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                checked[j] = true;
                count++;
            }
        }

        // cppcheck-suppress cstyleCast
        int **temp = (int**)realloc(matriz, (lns + 1) * sizeof(int*));
        if (!temp) {
            printf("impossível realocar memória para nova linha da matriz");
            return NULL;
        }
        matriz = temp;

        int cols = 2;
        // cppcheck-suppress cstyleCast
        matriz[lns] = (int*)malloc(cols * sizeof(int));
        if (!matriz[lns]) {
            printf("impossível alocar espaço para inserir elementos");
            return NULL;
        }

        matriz[lns][0] = arr[i];
        matriz[lns][1] = count;
        lns++;
    }
    free(checked);
    *lenMatriz = lns;
    return matriz;
}


// 06
// duas travessias
void empurrarZeros(int *arr, int len) {
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    for (int i = pos; i < len; i++) {
        arr[i] = 0;
    }
}

// uma travessia
void empurrarZero2(int *arr, int len) {
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;

            pos++;
        }
    }
}


// 07
void trimString(char *str) {
    int i = 0; // ponteiro de leitura
    int j = 0; // ponteiro de escrita
    bool espacoAdicionado = false;

    while (isspace(str[i])) {
        i++;
    }

    while (str[i]) {
        if (!isspace(str[i])) {
            str[j] = str[i];
            j++;
            espacoAdicionado = false;
        } else {
            if (espacoAdicionado == false) {
                str[j] = ' ';
                j++;
                espacoAdicionado = true;
            }
        }
        i++;
    }

    if (j > 0 && isspace(str[j - 1])) {
        j--;
    }
    str[j] = '\0';
}


// 08
// a)
typedef struct {
    char *palavra;
    int freq;
} Palavra;

void contarPalavras(char *str) {
    int lenPalavras = 0;
    Palavra *palavras = NULL;

    int lenStr = strlen(str) + 1;

    // cppcheck-suppress cstyleCast
    char *copy = (char*)malloc(lenStr);
    if (!copy) {
        printf("erro ao copiar string");
        return;
    }
    strcpy(copy, str);

    const char *token = strtok(copy, " \n");

    while (token) {
        bool found = false;

        for (int i = 0; i < lenPalavras; i++) {
            if (strcmp(token, palavras[i].palavra) == 0) {
                found = true;
                palavras[i].freq++;
                break;
            }
        }

        if (!found) {
            // cppcheck-suppress cstyleCast
            Palavra *temp = (Palavra*)realloc(palavras, (lenPalavras + 1) * sizeof(Palavra));
            if (!temp) {
                printf("erro ao realocar vetor de palavras");
                return;
            }
            palavras = temp;
            
            // cppcheck-suppress cstyleCast
            palavras[lenPalavras].palavra = (char*)malloc(strlen(token) + 1);
            strcpy(palavras[lenPalavras].palavra, token);
            palavras[lenPalavras].freq = 1;
            lenPalavras++;
        }
        
        token = strtok(NULL, " \n");
    }

    printf("Palavras Encontradas: \n");
    for (int i = 0; i < lenPalavras; i++) {
        printf("%s -- %d", palavras[i].palavra, palavras[i].freq);
    }

    free(palavras);
    free(copy);
}

// b)
int contarPalavra(const char *str, const char *substr) {
    int count = 0;
    int i = 0;

    int lenPalavra = strlen(str);

    while (str[i]) {

        int j = 0;
        while (str[i + j] == substr[j] && substr[j] != '\0') {
            j++;
        }

        if (j == lenPalavra) {

            char last = (i == 0) ? ' ' : str[i - 1];
            if (isspace(last) || ispunct(last)) {

                char next = str[i + j];
                if (isspace(next) || ispunct(next) || next == '\0') {
                    count++;
                }
            }
        }

        i++;
    }
    return count;
}


// 09
void toUpperFirst(char *str) {
    str[0] = toupper(str[0]);
}

char *toCamelCase(const char *str) {

    // cppcheck-suppress cstyleCast
    char *copy = (char*)malloc(strlen(str) + 1);
    if (!copy) {
        printf("erro ao realizar cópia");
        return NULL;
    }
    strcpy(copy, str);

    // cppcheck-suppress cstyleCast
    char *result = (char*)malloc(strlen(str) + 1);
    if (!result) {
        printf("erro ao carregar resultado");
        free(copy);
        return NULL;
    }
    result[0] = '\0';
    
    char *token = strtok(copy, " \n");

    bool first = false;
    int trueLen = 0;
    while (token) {
        
        if (!first) {
            first = true;
            strcat(result, token);
            trueLen += strlen(token);

        } else {
            toUpperFirst(token);
            strcat(result, token);
            trueLen += strlen(token);
        }
        
        token = strtok(NULL, " \n");
    }
    free(copy);
    
    // cppcheck-suppress cstyleCast
    char *temp = (char*)realloc(result, trueLen + 1);
    if (!temp) {
        printf("erro ao realocar memória");
        return NULL;
    }
    result = temp;

    return result;
}


// 10
char *removeVowels(char *str) {
    const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int lenVowels = 5;

    int i = 0;
    int pos = 0;
    while (str[i]) {

        int j;
        for (j = 0; j < lenVowels; j++) {
            if (*str == vowels[j]) {
                break;
            }
        }

        if (j == lenVowels) {
            str[pos] = str[i];
            pos++;
        }

        i++;
    }
    str[pos] = '\0';

    // cppcheck-suppress cstyleCast
    char *temp = (char*)realloc(str, pos);
    if (!temp) {
        printf("impossível realocar memória");
        return NULL;
    }
    str = temp;

    return str;
}


// 11
// a)
bool checkSubstring(char *str, char *substr) {
    while(*str) {
        const char *p1 = str;
        const char *p2 = substr;

        while (*p1 && *p2 && tolower(*p1) == tolower(*p2)) {
            p1++;
            p2++;
        }

        if (!*p2) {
            return true;
        }

        str++;
    }
    return false;
}

bool checkSubstring2(char *str, char *substring) {
    const char *p1 = str;

    while (*p1) {
        const char *p2 = substring;
        const char *p3 = p1;

        while (*p2 && tolower(*p2) == tolower(*p3)) {
            p2++;
            p3++;
        }

        if (!*p2) {
            return true;
        }

        p1++;
    }
    return false;
}

// b)
bool checkPrefix(const char *str, char *prefix) {
    while (*str && *prefix && tolower(*str) == tolower(*prefix)) {
        str++;
        prefix++;
    }

    if (!*prefix) {
        return true;
    }
    return false;
}


// 12
void reverseFromRange(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}


void reverseFullString(char *str) {
    char *inicio = str;

    while (*str) {

        while (*str && isspace(*str)) str++;
        inicio = str;

        while (*str && !isspace(*str)) str++;

        reverseFromRange(inicio, str - 1);
    }

}


// 13
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortStr(char *str) {
    int n = strlen(str) + 1;

    for (int i = 0; i < n; i++) {
        
    }
}