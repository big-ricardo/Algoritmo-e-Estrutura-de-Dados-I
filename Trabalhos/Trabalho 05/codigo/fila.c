#include <stdlib.h>
#include "fila.h"
#define true 1
#define false 0
typedef int bool;

struct No {
    void* info;
    struct No* prox;
};

typedef struct  No* p_no;

struct Fila {
    p_no inicio;
    p_no fim;
    int tamanho;
};

typedef struct No No;

p_fila criaFila() {
    p_fila fila = (p_fila)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void enfileira(p_fila f, void* info) {

    p_no novo = malloc(sizeof(No));

    novo->info = info;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;

    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
    return;
}

bool filaVazia(p_fila f) {
    return f->fim == NULL;
}

void* desenfileira(p_fila f) {
    void* aux;
    p_no noAux;

    if (f->inicio != NULL) {
        noAux = f->inicio;
        aux = noAux->info;
        f->inicio = f->inicio->prox;
        f->tamanho--;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        free(noAux);
    }

    return aux;
}

void liberaFila(p_fila f) {
    p_no no = f->inicio;
    while (no != NULL) {
        p_no prox = no->prox;
        free(no->info);
        free(no);
        no = prox;
    }
    free(f);
}