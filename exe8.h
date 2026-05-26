#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

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