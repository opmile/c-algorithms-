#include <stdio.h>
#include <string.h>

#define MAX_TITULAR 50

typedef struct {
    char titular[MAX_TITULAR];
    float saldo;
} Conta;

void depositarSalario(Conta *c, int valor, float bonus);

int main() {
    Conta conta1;
    strcpy(conta1.titular, "milena");
    conta1.saldo = 1000;

    printf("saldo antes: %.2f\n", conta1.saldo);
    depositarSalario(&conta1, 1223, 0.15);
    printf("saldo depois: %.2f\n", conta1.saldo);

    return 0;
}

void depositarSalario(Conta *c, int valor, float bonus) {
    if (valor > 1000) {
        float dep = valor + (valor * bonus);
        c->saldo += dep;
    }
}