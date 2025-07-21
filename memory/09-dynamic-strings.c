#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_CHAR 50

void printList(char **names, int len);
void edit(char **names, int len, int pos);

int main() {
    int len;
    printf("informe quantos nomes serão cadastrados: ");
    scanf("%d", &len);
    getchar();

    char **names = malloc(len * sizeof(char*));

    if (names == NULL) {
        printf("não foi possível alocar memória");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        names[i] = malloc(LEN_CHAR * sizeof(char));

        printf("digite o nome %d: ", i + 1);
        fgets(names[i], LEN_CHAR, stdin);

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("nomes cadastrados: \n");
    printf("-------------------\n");
    printList(names, len);
    printf("-------------------\n");

    int op;
    do {
        printf("1 - editar nome\n");
        printf("0 - sair\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1: {
            int pos;
            printf("escolha o nome a ser editado (0 a %d): ", len - 1);
            scanf("%d", &pos);

            edit(names, len, pos);
            printList(names, len);
            break;
        }
        } // blocos case não criam escopo próprio automaticamente, isso quebra a regra de declaração de variáveis no switch.
    } while (op != 0);

    for (int i = 0; i < len; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}

void printList(char **names, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%s", names[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

void edit(char **names, int len, int pos) {
    if (pos < 0 || pos > len - 1) {
        printf("índice inválido!");
        return;
    }
    
    int newLen = LEN_CHAR * 2;
    names[pos] = realloc(names[pos], newLen * sizeof(char));
    if (names[pos] == NULL) {
        printf("erro ao alocar memória");
        return;
    }

    getchar(); // ← consome o '\n' deixado pelo scanf
    printf("insira o novo nome: ");
    fgets(names[pos], newLen, stdin);
    names[pos][strcspn(names[pos], "\n")] = '\0';
}