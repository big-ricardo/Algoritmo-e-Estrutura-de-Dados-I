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

// Funcao que verifica o tamanho da string
int tamanhoString(char* str) {
  // Inicializa variavel i  com 0
  int i = 0;
  // Enquanto a string nao terminar
  while (str[i] != '\0') {
    // Incrementa i
    i++;
  }
  // Retorna o tamanho da string
  return i;
}

// Funcao que converte a string para inteiro
char* converteNumero(int value, char* str) {
  // Se o valor for  0, adiciona um 0 na string
  if (value == 0) {
    str[0] = '0';
    str[1] = '\0';
    return str;
  }

  // Se o valor for maior que 0, converte o valor para string
  for (int i = 0; value > 0; i++) {
    // Guarda o resto da divisao do valor por 10
    int digito = value % 10;
    // Guarda o digito na string convertendo para char
    str[i] = digito + '0';
    // Divide o valor por 10
    value /= 10;
  }
  // Pego o tamanho da string
  int j = tamanhoString(str) - 1;
  // Inverto a string
  char temp;
  for (int i = 0; i < j; i++) {
    // Guardo o valor da posicao i
    temp = str[i];
    // Guardo o valor da posicao j na posicao i
    str[i] = str[j];
    // Guardo o valor da posicao i na posicao j
    str[j] = temp;
    // Decremento j
    j--;
  }
  // Retorno a string
  return str;

}

// Funcao que verifica a entrada para fazer a operação passada
void analisaChave(p_pilha pilha, p_fila fila, char chave, char* valor) {
  void* aux = NULL;
  // Verifica a entrada para fazer a operação
  switch (chave) {
  case 'e':
    // se for e, empilho o valor
    empilha(pilha, valor);
    break;
  case 'd':
    // se for d, desempilho o valor
    aux = desempilha(pilha);
    if (aux != NULL) {
      // se nao estiver vazio, coloco na fila para impressão
      enfileira(fila, aux);
    }
    break;
  case 't':
    // se for t, imprimo aloco o tamanho da pilha
    aux = malloc(5 * sizeof(char));
    // converto o tamanho da pilha para string
    converteNumero(tamanhoPilha(pilha), (char*)aux);
    // coloco na fila para impressão
    enfileira(fila, aux);
    break;
  }
}

int main(void) {

  // Declaração de variáveis
  char chave;
  char* valor = NULL;

  // Declaração de estruturas
  // Pilha
  p_pilha pilha = criaPilha();
  // Fila
  p_fila fila = criaFila();

  // Leitura das entradas
  while (true) {
    // Leitura da chave
    scanf("%s", &chave);
    if (chave == 'x') {
      break;
    }
    valor = NULL;
    if (chave == 'e') {
      // Aloca um espaço para o valor
      valor = malloc(5 * sizeof(char));
      // Leitura do valor
      scanf("%s", valor);
    }
    // Chama a função que analisa a entrada
    analisaChave(pilha, fila, chave, valor);
  }

  // Imprime a filha com os resultados
  while (!filaVazia(fila)) {
    // Desinfileira o valor
    char* aux = (char*)desenfileira(fila);
    // Imprime o valor
    printf("%s\n", aux);
    // Libera o espaço alocado
    free(aux);
  }

  // Libera o espaço alocado
  // Fila
  liberaFila(fila);
  // Pilha
  liberaPilha(pilha);

  return 0;

}
