#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAMES 5
#define LEN_STRING 100

int main() {
    int len = 5;
    char **names = malloc(LEN_NAMES * sizeof(char*));
    
    if (names == NULL) {
        perror("não foi possível alocar memória");
        return 1;
    }

    for (int i = 0; i < LEN_NAMES; i++) {
        names[i] = malloc(LEN_STRING * sizeof(char));

        if (names[i] == NULL) {
            perror("não foi possível alocar memória");
            return 1;   
        }

        printf("digite um nome: ");
        fgets(names[i], LEN_STRING, stdin);

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("{");
    for (int i = 0; i < LEN_NAMES; i++) {
        printf("%s", names[i]);
        if (i < LEN_NAMES - 1) printf(", ");
    }
    printf("}\n");

    for (int i = 0; i < LEN_NAMES; i++) {
        free(names[i]);
    }
    free(names);
    
    return 0;
}