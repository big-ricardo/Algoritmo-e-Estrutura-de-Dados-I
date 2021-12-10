#include <stdlib.h>
#include "heap.h"
#define pai(i) ((i-1)/2)
#define filho_esq(i) (2*i+1)
#define filho_dir(i) (2*i+2)


p_heap cria_fila_prio(int capacidade) {
    p_heap fila = (p_heap)malloc(sizeof(Heap));
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    fila->vetor = malloc(capacidade * sizeof(Torsimre));
    return fila;
}

void insere(p_heap fila, int id, int hp) {
    Torre torre;
    torre.id = id;
    torre.hp = hp;
    if (fila->tamanho == fila->capacidade) {
        return;
    }
    fila->vetor[fila->tamanho] = torre;
    fila->tamanho++;
    int i = fila->tamanho - 1;
    while (i > 0 && fila->vetor[pai(i)].hp > fila->vetor[i].hp) {
        Torre aux = fila->vetor[i];
        fila->vetor[i] = fila->vetor[pai(i)];
        fila->vetor[pai(i)] = aux;
        i = pai(i);
    }
    return;
}

Torre retorna_min(p_heap fila) {
    if (fila->tamanho == 0) {
        Torre torre;
        torre.id = -1;
        torre.hp = -1;
        return torre;
    }
    Torre min = fila->vetor[0];
    fila->vetor[0] = fila->vetor[fila->tamanho - 1];
    fila->tamanho--;
    int i = 0;
    while (filho_esq(i) < fila->tamanho) {
        int menor = filho_esq(i);
        if (filho_dir(i) < fila->tamanho &&
            fila->vetor[filho_dir(i)].hp < fila->vetor[filho_esq(i)].hp) {

            menor = filho_dir(i);
        }
        if (fila->vetor[i].hp > fila->vetor[menor].hp) {
            Torre aux = fila->vetor[i];
            fila->vetor[i] = fila->vetor[menor];
            fila->vetor[menor] = aux;
            i = menor;
        }
        else {
            break;
        }
    }
    return min;
}

void destroi_heap(p_heap fila) {
    free(fila->vetor);
    free(fila);
}
