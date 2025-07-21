#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void change(Person *p1, Person *p2);

int main() {
    Person p1;
    strcpy(p1.name, "milena");
    p1.age = 19;

    Person p2;
    strcpy(p2.name, "milena2");
    p2.age = 20;

    printf("antes da troca: \n");
    printf("p1: {nome: %s, idade %d\n", p1.name, p1.age);
    printf("p2: {nome: %s, idade %d\n", p2.name, p2.age);

    printf("\n");
    change(&p1, &p2);

    printf("depois da troca: \n");
    printf("p1: {nome: %s, idade %d\n", p1.name, p1.age);
    printf("p2: {nome: %s, idade %d\n", p2.name, p2.age);

    return 0;
}

void change(Person *p1, Person *p2) {
    // change names
    char temp[50];
    strcpy(temp, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, temp);

    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}