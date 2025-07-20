#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int numItems;
} List;

void printList(List *list);

void addItem(List *list, int item);

bool removeItem(List *list, int index);

bool shrinkList(List *list);

int main() {
    List list;
    int amount;

    list.numItems = 0;
    list.size = 10;
    list.data = malloc(list.size * sizeof(int));

    if (list.data == NULL) {
        printf("não foi possível alocar memória dinamicamente");
        return 1;
    }

    amount = 10;
    for (int i = 0; i < amount; i++) {
        addItem(&list, i + 1);
    }

    printList(&list);

    removeItem(&list, 2);
    printList(&list);

    removeItem(&list, 5);
    printList(&list);

    shrinkList(&list);
    printList(&list);


    free(list.data);
    list.data = NULL;
    
    return 0;
}

void printList(List *list) {
    printf("{");
    for (int i = 0; i < list->numItems; i++) {
        printf("%d%s", *(list->data + i), (i < list->numItems ? ", " : ""));
    }
    printf("}\n");
}

void addItem(List *list, int item) {
    if (list->numItems == list->size) {
        list->size += 10;
        list->data = realloc(list->data, list->size * sizeof(int));

        if (list->data == NULL) {
            printf("impossível alocar memória");
            return 1;
        }

    }

    list->data[list->numItems] = item;
    list->numItems++;
}

bool removeItem(List *list, int index) {
    if (index < 0 || index >= list->numItems) {
        printf("índice inválido");
        return false;
    }

    printf("%d removido\n", *(list->data + index));
    while (index < list->numItems) {
        *(list->data + index) = *(list->data + index + 1);
        index++;
    }
    list->numItems--;
    return true;
}

bool shrinkList(List *list) {
    if (list->numItems == list->size) {
        printf("nada a encolher!");
        return false;
    }

    list->size = list->numItems;
    list->data = realloc(list->data, list->size * sizeof(int));

    if (list->data == NULL) {
        printf("impossível alocar memória");
        return 1;
    }

    printf("nova capacidade: %d\n", list->size);
    return true;
}
