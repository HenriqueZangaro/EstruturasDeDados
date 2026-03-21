#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int conteudoNO;
    struct no* esquerda;
    struct no* direita;
    struct no* raiz;
} No;

typedef struct
{
    No* raiz;
} avb;


void inserirnoEsquerda(No *no, int valor);
void inserirnoDireita(No *no, int valor);

void inserirNovoNo(avb *arv, int valor) {
    if(arv->raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudoNO = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->raiz = NULL; 
        arv->raiz = novoNo;
    }
    else{
        if(valor < arv->raiz->conteudoNO)
            inserirnoEsquerda(arv->raiz, valor);
        if(valor > arv->raiz->conteudoNO)
            inserirnoDireita(arv->raiz, valor);
    }
}

void inserirnoEsquerda(No *no, int valor) {
    if(no->esquerda == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudoNO = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->raiz = NULL;
        no->esquerda = novoNo;
    }
    else {
        if(valor < no->esquerda->conteudoNO)
            inserirnoEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudoNO)
            inserirnoDireita(no->esquerda, valor);
    }
}

void inserirnoDireita(No *no, int valor) {
    if(no->direita == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudoNO = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->raiz = NULL;
        no->direita = novoNo;
    }
    else {
        if(valor < no->direita->conteudoNO)
            inserirnoEsquerda(no->direita, valor);
        if(valor > no->direita->conteudoNO)
            inserirnoDireita(no->direita, valor);
    }
}

void imprimirarvore(No *raiz) {
    if(raiz != NULL) {
        imprimirarvore(raiz->esquerda);
        printf("%d ", raiz->conteudoNO);
        imprimirarvore(raiz->direita);
    }
}

No* novainsercao(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->conteudoNO = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->raiz = NULL;
        return novoNo;
    }
    else {
        if(valor < raiz->conteudoNO)
            raiz->esquerda = novainsercao(raiz->esquerda, valor);
        if(valor > raiz->conteudoNO)
            raiz->direita = novainsercao(raiz->direita, valor);
    }
    return raiz;
}

int tamanho(No *raiz) {
    if(raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave) {
    if(raiz == NULL)
        return 0;
    else {
        if(chave == raiz->conteudoNO)
            return 1;
        else {
            if(chave < raiz->conteudoNO)
                return buscar(raiz->esquerda, chave);
            if(chave > raiz->conteudoNO)
                return buscar(raiz->direita, chave);
        }
    }
    return 0;
}

No* remover(No *raiz, int chave) {
    if(raiz == NULL)
        return raiz;
    else {
        if(chave < raiz->conteudoNO)
            raiz->esquerda = remover(raiz->esquerda, chave);
        else {
            if(chave > raiz->conteudoNO)
                raiz->direita = remover(raiz->direita, chave);
            else {
                if(raiz->esquerda == NULL && raiz->direita == NULL) {
                    free(raiz);
                    return NULL;
                }
                else {
                    if(raiz->esquerda == NULL) {
                        No *temp = raiz->direita;
                        free(raiz);
                        return temp;
                    }
                    else {
                        if(raiz->direita == NULL) {
                            No *temp = raiz->esquerda;
                            free(raiz);
                            return temp;
                        }
                        else {
                            No *temp = raiz->direita;
                            while(temp->esquerda != NULL)
                                temp = temp->esquerda;
                            raiz->conteudoNO = temp->conteudoNO;
                            raiz->direita = remover(raiz->direita, temp->conteudoNO);
                        }
                    }
                }
            }
        }
    }
    return raiz;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    avb arvore;
    arvore.raiz = NULL;

    inserirNovoNo(&arvore, 10);
    inserirNovoNo(&arvore, 5);
    inserirNovoNo(&arvore, 15);
    inserirNovoNo(&arvore, 3);
    inserirNovoNo(&arvore, 7);
    inserirNovoNo(&arvore, 12);
    inserirNovoNo(&arvore, 18);

    printf("Árvore em ordem: ");
    imprimirarvore(arvore.raiz);
    printf("\n");

    printf("Tamanho da árvore: %d\n", tamanho(arvore.raiz));

    int chave = 7;
    if(buscar(arvore.raiz, chave))
        printf("Valor %d encontrado na árvore.\n", chave);
    else
        printf("Valor %d não encontrado na árvore.\n", chave);

    arvore.raiz = remover(arvore.raiz, chave);
    printf("Árvore após remoção de %d: ", chave);
    imprimirarvore(arvore.raiz);
    printf("\n");

    return 0;
}