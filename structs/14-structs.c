/*
jogo de pokemon com pedra, papel e tesoura
pokemon -> nome, tupo, poder, defesa, saúde

nome -> max 32 caracteres
type -> int    
    pode ser:
        pedra(0)
        papel(1)
        tesoura(2)

power -> int -- força de ataque do pokemon
defense -> int -- o quanto consegue diminuir a força de ataque do oponente
health -> int -- quantidade de hits que o pokemon consegue suportar antes de morrer

programa:
inicializa os pokemons do primeiro jogador e indica, para cada pokemon seu, a lista de pokemons do segundo jogador que perde do primeiro, considerando o seu tipo

pedra ganha de tesoura
tesoura ganah de papel
papel ganha de pedra
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _tNAME_SIZE 32+1
typedef unsigned char tName [_tNAME_SIZE];

#define TYPE_NAME 10

typedef enum {
    PK_PEDRA,
    PK_PAPEL,
    PK_TESOURA,
    PK_INVALID
} TypePokemon;

typedef struct {
    tName name;
    int power;
    int defense;
    int health;
    TypePokemon type;
} Pokemon;

TypePokemon reconhecerTipo(const char *str) {
    if (strcmp(str, "pedra") == 0) return PK_PEDRA;
    if (strcmp(str, "papel") == 0) return PK_PAPEL;
    if (strcmp(str, "tesoura") == 0) return PK_TESOURA;

    printf("tipo não reconhecido\n");
    return PK_INVALID;
}

/*
pedra 0
papel 1
tesoura 2

pedra ganha de tesoura
tesoura ganha de papel
papel ganha de pedra
*/
int ganhaPorTipo(TypePokemon t1, TypePokemon t2) {
    if (t1 == PK_INVALID || t2 == PK_INVALID) {
        printf("tipo não reconhecido!\n");
        return -1;
    }

    if (t1 == PK_PEDRA && t2 == PK_TESOURA) {
        return 1;
    } else if (t1 == PK_TESOURA && t2 == PK_PAPEL) {
        return 1;
    } else if (t1 == PK_PAPEL && t2 == PK_PEDRA) {
        return 1;
    }

    return 0;
}

Pokemon *cria_sacola_pokemons(int n) {
    Pokemon *pokemons = (Pokemon*)malloc(n * sizeof (Pokemon));
    if (!pokemons) {
        printf("impossível criar sacolas de pokemons");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        tName name;
        int power, defense, health;
        char typeName[TYPE_NAME];

        scanf("%s %s %d %d %d", name, typeName, &power, &defense, &health);

        TypePokemon type = reconhecerTipo(typeName);

        // cppcheck-suppress cstyleCast
        strcpy((char*)pokemons[i].name, (char*)name);
        pokemons[i].type = type;
        pokemons[i].power = power;
        pokemons[i].defense = defense;
        pokemons[i].health = health;
    } 

    return pokemons;
}

void fight(const Pokemon *p1, const Pokemon *p2, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int resultado = ganhaPorTipo(p1[i].type, p2[j].type);

            if (resultado != -1) {
                if (resultado > 0) {
                    printf("%s ganha de: %s\n", p1[i].name, p2[j].name);
                }
            }
        }
    }
}

int main() {
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    Pokemon *p1 = cria_sacola_pokemons(n1);
    Pokemon *p2 = cria_sacola_pokemons(n2);
}


