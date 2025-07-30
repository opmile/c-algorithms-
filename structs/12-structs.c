#include <stdio.h>
#include <stdlib.h>

// 27.03.2025
// 25.03.2025

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int compararDatas(Data *d1, Data *d2) {
    if (d1->ano == d2->ano) {
        if (d1->mes == d2->mes) {
            if (d1->dia == d2->dia) {
                return 0;

            } else if (d1->dia > d2->dia) {
                return 1; // é posteior
            }
            return -1;

        } else if (d1->mes > d2->mes) {
            return 1; // é posteior
        }
        return -1;

    } else if (d1->ano > d2->ano) {
        return 1;
    }
    return -1;
}

int compararDatas2(Data *d1, Data *d2) {
    if (d1->ano != d2->ano) 
        return (d1->ano > d2->ano) ? 1 : -1;

    if (d1->mes != d2->mes)
        return (d1->mes > d2->mes) ? 1 : -1;

    if (d1->dia != d2->dia)
        return (d1->dia > d2->dia) ? 1 : -1;

    return 0;
}

int main() {
    return 0;
}