#include <stdlib.h>
#include "fila.h"
#define true 1
#define false 0
typedef int bool;

// Definição da struct nó
struct No {
    void* info;
    struct No* prox;
};
// Definição do ponteiro para struct nó
typedef struct  No* p_no;

// Definição da struct fila
struct Fila {
    p_no inicio;
    p_no fim;
    int tamanho;
};
// Definição do ponteiro para struct fila
typedef struct No No;

// Cria uma fila vazia
p_fila criaFila() {
    // Aloca memória para a fila
    p_fila fila = (p_fila)malloc(sizeof(Fila));
    // Inicializa os ponteiros inicio e fim da fila com NULL
    fila->inicio = NULL;
    fila->fim = NULL;
    // Inicializa o tamanho da fila com 0
    fila->tamanho = 0;
    // Retorna a fila
    return fila;
}

// Insere um elemento na fila
void enfileira(p_fila f, void* info) {
    // Aloca memória para o novo nó
    p_no novo = malloc(sizeof(No));
    // Inicializa o nó com o valor de info
    novo->info = info;
    // Inicializa o ponteiro prox do novo nó com NULL
    novo->prox = NULL;
    // Se a fila estiver vazia
    if (f->inicio == NULL) {
        // Inicializa o inicio e fim da fila com o novo nó
        f->inicio = novo;
        f->fim = novo;

    }
    else {
        // Insere o novo nó no fim da fila
        f->fim->prox = novo;
        // Atualiza o fim da fila com o novo nó
        f->fim = novo;
    }
    // Incrementa o tamanho da fila
    f->tamanho++;
    return;
}

//Verifica se a fila está vazia
bool filaVazia(p_fila f) {
    return f->fim == NULL;
}

// Remove o primeiro elemento da fila
void* desenfileira(p_fila f) {
    // Declara um ponteiro para void 
    void* aux;
    // Declara um ponteiro para struct nó
    p_no noAux;
    // Se a fila estiver vazia
    if (f->inicio != NULL) {
        // Atribui o valor do inicio da fila a noAux
        noAux = f->inicio;
        // Atribui o valor da info do inicio da fila a aux
        aux = noAux->info;
        // Atribui o valor do prox do inicio da fila a inicio da fila
        f->inicio = f->inicio->prox;
        // Decrementa o tamanho da fila
        f->tamanho--;
        // Se a fila estiver vazia
        if (f->inicio == NULL) {
            // Atribui NULL ao fim da fila
            f->fim = NULL;
        }
        // Libera a memória do nó auxiliar
        free(noAux);
    }
    // Retorna o valor da info do nó auxiliar
    return aux;
}

// Libera a memória alocada para a fila
void liberaFila(p_fila f) {
    // Declara um ponteiro para primeiro nó
    p_no no = f->inicio;
    // Enquanto o nó for diferente de NULL
    while (no != NULL) {
        // Atribui o valor do prox do nó ao nó auxiliar
        p_no prox = no->prox;
        // Libera a memória do nó da info
        free(no->info);
        // Libera a memória do nó
        free(no);
        // Atribui o valor do prox do nó auxiliar ao nó
        no = prox;
    }
    // Libera a memória da fila
    free(f);
}