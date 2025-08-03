#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
} Cliente;

typedef struct {
    int id_cliente;
    float valor;
} Venda;

float valor_total_cliente(const Cliente c, Venda *v, int nv) {
    float sumVendas = 0;

    for (int i = 0; i < nv; i++) {
        if (v[i].id_cliente == c.id) {
            sumVendas += v[i].valor;
        }
    }
    return sumVendas;
}

void calcularVendas(const Cliente *c, int nc, Venda *v, int nv) {
    for (int i = 0; i < nc; i++) {
        float total_cliente  = valor_total_cliente(c[i], v, nv);

        printf("%s: %.6f\n", c[i].nome, total_cliente);
    }
}

void limparBuffer() {
    int l;
    while ((l = getchar()) != '\n' && l != EOF);
}

int main() {
    int nc, nv;

    // cadastrar clientes
    // registra número de clientes 
    scanf("%d", &nc);

    Cliente c[nc];
    for (int i = 0; i < nc; i++) {
        scanf("%d", &c[i].id);
        limparBuffer();

        fgets(c[i].nome, MAX_NOME, stdin);
        c[i].nome[strcspn(c[i].nome, "\n")] = '\0';
    }


    // cadastrar vendas
    // registra número de vendas
    scanf("%d", &nv);

    Venda v[nv];
    for (int i = 0; i < nv; i++) {
        scanf("%d %f", &v[i].id_cliente, &v[i].valor);
    }

    calcularVendas(c, nc, v, nv);

    return 0;
}