#include <stdlib.h>
#include "pilha.h"
#define true 1
#define false 0
typedef int bool;

struct No {
    void* info;
    struct No* prox;
};

typedef struct  No* p_no;

struct Pilha {
    p_no pilha;
};

typedef struct No No;

p_pilha criaPilha() {
    p_pilha p = malloc(sizeof(Pilha));
    p->pilha = NULL;
    return p;
}

void empilha(p_pilha p, void* info) {
    p_no novo = malloc(sizeof(No));
    novo->info = info;
    novo->prox = p->pilha;
    p->pilha = novo;

    return;
}

bool pilhaVazia(p_pilha p) {
    return p->pilha == NULL;
}

void* desempilha(p_pilha p) {
    if (pilhaVazia(p)) {
        return NULL;
    }

    p_no aux = p->pilha;
    p->pilha = p->pilha->prox;
    void* info = aux->info;
    free(aux);

    return info;
}

void liberaPilha(p_pilha p) {
    while (!pilhaVazia(p)) {
        desempilha(p);
    }
    free(p);
}