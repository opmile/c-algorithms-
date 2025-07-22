#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAME 70

typedef struct  {
    char name[LEN_NAME];
    float price;
} Product;

Product* getHigestProduct(Product *p, int len);
void printList(Product *p, int len);
Product* getSecondHigest(Product *p, int len);

int main() {
    int len;
    printf("digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &len);
    getchar();

    Product *products =  malloc(len * sizeof(Product));
    if (products == NULL) {
        printf("não foi possível alocar memória");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        printf("digite o nome do produto: ");
        fgets(products[i].name, LEN_NAME, stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("digite o preço do produto: ");
        scanf("%f", &products[i].price);
        getchar();

        printf("\n");
    }

    printList(products, len);
    
    Product *highestProduct = getHigestProduct(products, len);
    printf("produto mais caro: %s - %.2f\n", highestProduct->name, highestProduct->price);

    Product *secondHigest = getSecondHigest(products, len);
    printf("segundo mais caro: %s - %.2f\n", secondHigest->name, secondHigest->price);

    free(products);
    return 0;
}

Product* getHigestProduct(Product *p, int len) {
    if (len <= 0) return NULL;
    
    Product *max = &p[0];
    
    for (int i = 1; i < len; i++) {
        if (p[i].price > max->price) {
            max = &p[i]; // *
        }
    }
    return max;
}

Product* getSecondHigest(Product *p, int len) {
    Product *max = getHigestProduct(p, len);

    Product *secondMax = &p[0];

    for (int i = 1; i < len; i++) {
        if (p[i].price > secondMax->price && p[i].price != max->price) {
            secondMax = &p[i];
        }
    }
    return secondMax;
}

void printList(Product *p, int len) {
    printf("{ ");
    for (int i = 0; i < len; i++) {
        printf("%s - R$%.2f", (p + i)->name, (p + i)->price);
        if (i < len - 1) printf(", \n");
    }
    printf(" }\n");
}

/*
max = &p[i]; → aqui você atualiza o ponteiro max para apontar para o endereço do produto mais caro até agora
* esse é o correto, porque no final da função você quer retornar um ponteiro para esse produto

max->price = p[i].price; → aqui você *não* altera o ponteiro max (ele continua apontando para o primeiro elemento!), já que você apenas copia o valor do preço do produto atual para o produto apontado por max
* isso quer dizer que você estaria mudando os dados do produto anterior, e não identificando corretamente o produto mais caro!
*/