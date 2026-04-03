#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudoNO;
    struct no *esquerda;
    struct no *direita;
} No;

typedef struct {
    No *raiz;
} Avb;

No* novainsercao(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudoNO = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if (valor < raiz->conteudoNO)
            raiz->esquerda = novainsercao(raiz->esquerda, valor);
        if (valor > raiz->conteudoNO)
            raiz->direita = novainsercao(raiz->direita, valor);
        return raiz;
    }
}

void imprimirarvore(No *raiz) {
    if (raiz != NULL) {
        imprimirarvore(raiz->esquerda);
        printf("%d ", raiz->conteudoNO);
        imprimirarvore(raiz->direita);
    }
}

int tamanho(No *raiz) {
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave) {
    if (raiz == NULL) {
        return -1;
    } else {
        if (chave == raiz->conteudoNO) {
            return raiz->conteudoNO;
        } else {
            if (chave < raiz->conteudoNO)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}

No* remover(No *raiz, int chave) {
    if (raiz == NULL) {
        printf("valor nao encontrado\n");
        return NULL;
    } else {
        if (raiz->conteudoNO == chave) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            } else if (raiz->esquerda == NULL || raiz->direita == NULL) {
                No *aux;
                if (raiz->esquerda != NULL)
                    aux = raiz->esquerda;
                else
                    aux = raiz->direita;
                free(raiz);
                return aux;
            } else {
                No *aux = raiz->esquerda;
                while (aux->direita != NULL)
                    aux = aux->direita;
                raiz->conteudoNO = aux->conteudoNO;
                aux->conteudoNO = chave;
                raiz->esquerda = remover(raiz->esquerda, chave);
                return raiz;
            }
        } else {
            if (chave < raiz->conteudoNO)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

int main() {
    Avb arvore;
    arvore.raiz = NULL;

    arvore.raiz = novainsercao(arvore.raiz, 8);
    arvore.raiz = novainsercao(arvore.raiz, 3);
    arvore.raiz = novainsercao(arvore.raiz, 10);
    arvore.raiz = novainsercao(arvore.raiz, 1);
    arvore.raiz = novainsercao(arvore.raiz, 6);
    arvore.raiz = novainsercao(arvore.raiz, 14);
    arvore.raiz = novainsercao(arvore.raiz, 4);
    arvore.raiz = novainsercao(arvore.raiz, 7);
    arvore.raiz = novainsercao(arvore.raiz, 13);

    printf("Em ordem: ");
    imprimirarvore(arvore.raiz);
    printf("\n");

    printf("Tamanho: %d\n", tamanho(arvore.raiz));

    int resultado = buscar(arvore.raiz, 6);
    if (resultado != -1)
        printf("Encontrado: %d\n", resultado);
    else
        printf("Nao encontrado\n");

    arvore.raiz = remover(arvore.raiz, 3);
    printf("Apos remover 3: ");
    imprimirarvore(arvore.raiz);
    printf("\n");

    return 0;
}