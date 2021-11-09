#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  para executar digite: make
*/

void analisaChave(p_pilha pilha, p_fila fila, char chave, char* valor) {
  void* aux = NULL;
  switch (chave) {
  case 'e':
    empilha(pilha, valor);
    break;
  case 'd':
    aux = desempilha(pilha);
    if (aux != NULL) {
      enfileira(fila, aux);
    }
    break;
  }
}

int main(void) {

  // Declaração de variáveis
  char chave;
  char* valor = NULL;

  p_pilha pilha = criaPilha();
  p_fila fila = criaFila();

  while (true) {
    scanf("%s", &chave);
    if (chave == 'x') {
      break;
    }
    if (chave == 'e') {
      valor = malloc(sizeof(char));
      scanf("%s", valor);
    }

    analisaChave(pilha, fila, chave, valor);
  }

  while (!filaVazia(fila)) {
    char* aux = (char*)desenfileira(fila);
    printf("%c\n", *aux);
  }

  liberaFila(fila);
  liberaPilha(pilha);

  return 0;

}
