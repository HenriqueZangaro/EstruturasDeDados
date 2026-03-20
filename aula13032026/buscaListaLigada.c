#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};

struct No* buscar(struct No* inicio, int x) {
    struct No* atual = inicio;

    while (atual != NULL) {
        if (atual->dado == x) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

int main() {

    struct No* n1 = (struct No*)malloc(sizeof(struct No));
    struct No* n2 = (struct No*)malloc(sizeof(struct No));
    struct No* n3 = (struct No*)malloc(sizeof(struct No));
    struct No* n4 = (struct No*)malloc(sizeof(struct No));

    n1->dado = 10; n1->proximo = n2;
    n2->dado = 20; n2->proximo = n3;
    n3->dado = 30; n3->proximo = n4;
    n4->dado = 40; n4->proximo = NULL;

    struct No* resultado = buscar(n1, 30);

    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->dado);
    }
    else {
        printf("Elemento nao encontrado.\n");
    }

    resultado = buscar(n1, 99);
    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->dado);
    }
    else {
        printf("Elemento nao encontrado.\n");
    }

    free(n1); free(n2); free(n3); free(n4);

    return 0;
}