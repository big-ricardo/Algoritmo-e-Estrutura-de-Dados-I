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

int tamanhoString(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

char* converteNumero(int value, char* str) {

  if (value == 0) {
    str[0] = '0';
    str[1] = '\0';
    return str;
  }

  for (int i = 0; value > 0; i++) {
    int digito = value % 10;
    str[i] = digito + '0';
    value /= 10;
  }
  int j = tamanhoString(str) - 1;

  char temp;
  for (int i = 0; i < j; i++) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    j--;
  }

  return str;

}

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
  case 't':
    aux = malloc(5 * sizeof(char));
    converteNumero(tamanhoPilha(pilha), (char*)aux);
    enfileira(fila, aux);
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
    valor = NULL;
    if (chave == 'e') {
      valor = malloc(5 * sizeof(char));
      scanf("%s", valor);
    }

    analisaChave(pilha, fila, chave, valor);
  }

  while (!filaVazia(fila)) {
    char* aux = (char*)desenfileira(fila);
    printf("%s\n", aux);
    free(aux);
  }

  liberaFila(fila);
  liberaPilha(pilha);

  return 0;

}
