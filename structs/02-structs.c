#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
} Person;

void setName(Person *p, char *name);

void setAge(Person *p, int age);

int sumAges(Person *p, int len);

int main() {
    int len = 3;
    Person *p = malloc(len * sizeof(Person));

    if (p == NULL) {
        printf("não foi possível alocar memória");
        return 1;
    }

    int age;
    char name[100];

    for (int i = 0; i < len; i++) {
        printf("digite o nome: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';

        printf("digite a idade: ");
        scanf("%d", &age);
        getchar();

        setName((p + i), name);
        setAge((p + i), age);
    }

    printf("{\n");
    for (int i = 0; i < len; i++) {
        printf("{");
        printf("name: %s; age: %d", p[i].name, p[i].age);
        printf("}\n");
    }
    printf("}\n");

    printf("soma das idades: %d\n", sumAges(p, len));

    free(p);
    
    return 0;
}

void setName(Person *p, char *name) {
    strncpy(p->name, name, sizeof(p->name));
    p->name[sizeof(p->name) - 1] = '\0';
}

void setAge(Person *p, int age) {
    p->age = age;
}

int sumAges(Person *p, int len) {
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += (p + i)->age;
    }
    return sum;
}

/*
1. se lembre da aritmética de ponteiros
p + i == &p[i]
*(p + i) == p[i]

2. getchar() depois do scanf
depois de scanf("%d", ...), o \n da tecla Enter fica no buffer, e isso faz com que fgets() leia uma linha em branco na próxima iteração
adicionar getchar(); resolve isso consumindo o \n

*/

