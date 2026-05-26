#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserir(No *raiz, int valor) {

    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

int buscar(No *raiz, int valor) {

    if (raiz == NULL) {
        return 0;
    }

    if (raiz->valor == valor) {
        return 1;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

void emOrdem(No *raiz) {

    if (raiz != NULL) {

        emOrdem(raiz->esquerda);

        printf("%d ", raiz->valor);

        emOrdem(raiz->direita);
    }
}

int main() {

    No *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Valores em ordem:\n");
    emOrdem(raiz);

    printf("\n\n");

    if (buscar(raiz, 40)) {
        printf("Valor 40 encontrado!\n");
    } else {
        printf("Valor 40 nao encontrado!\n");
    }

    if (buscar(raiz, 90)) {
        printf("Valor 90 encontrado!\n");
    } else {
        printf("Valor 90 nao encontrado!\n");
    }

    return 0;
}