#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe
*/

typedef struct Objeto {
  int peso;
  int na_balanca;
} Objeto; 

typedef struct Objeto *p_Objeto;

// Função que cria um vetor com o tamanho informado
p_Objeto cria_vetor_de_objetos(int quant_objetos) {
  p_Objeto vetor = malloc(quant_objetos * sizeof(Objeto));
  return vetor;
}

// Função que faz a verificação das combinações para obter o resultado final
bool verifica_pesos(p_Objeto objetos, int quant_objetos, int peso_total, int peso_atual) {

  // Se o peso atual for maior que o peso total, retorna false
  if (peso_atual == peso_total) return true;

  // Se o peso atual for maior que o peso total, retorna false
  if (peso_atual > peso_total) return false;

  // Se a quantidade de objetos for igual a 0, retorna true
  if (quant_objetos == 0) return false;

  //Defino se o objeto vai ser colocado na balança
  objetos[quant_objetos - 1].na_balanca = 1;

  /* 
    Se a função retornar true, significa que o objeto foi colocado na balança
    ou seja, foi encontrado uma combinação que satisfaz o peso total, então faz
    um return true
  */
  if (verifica_pesos(objetos, quant_objetos - 1, peso_total, peso_atual +
    objetos[quant_objetos - 1].peso)) return true;

  /* 
    Se a função retornar false, significa que o objeto não foi colocado na balança
    ou seja, não foi encontrado uma combinação que satisfaz o peso total
  */

  // Defino que o objeto não vai ser colocado na balança
  objetos[quant_objetos - 1].na_balanca = 0;

  /* 
    Se a função retornar true, significa que o objeto não foi colocado na balança
    ou seja, foi encontrado uma combinação que satisfaz o peso total, então faz
    um return true
  */

  if (verifica_pesos(objetos, quant_objetos - 1, peso_total, peso_atual)) return true;

  // Retorna false caso nenhuma das combinações seja satisfeita
  return false;

}

int main(void) {

  // Declaração de variáveis
  int peso_total = 0;
  int quant_objetos = 0;

  // Entrada de dados
  scanf("%d", &peso_total);
  scanf("%d", &quant_objetos);

  // Alocação de memória
  p_Objeto objetos = cria_vetor_de_objetos(quant_objetos);

  // Entrada dos pesos dos objetos
  for (int i = 0; i < quant_objetos; i++) {
    scanf("%d", &objetos[i].peso);
  }
  
  // Verifica a combinação de objetos que possam ser colocados na balança
  verifica_pesos(objetos, quant_objetos, peso_total, 0);

  // Impressão do resultado das respostas
  for (int i = 0; i < quant_objetos; i++) {
    printf("%d ", objetos[i].na_balanca);
  }

  printf("\n");

  free(objetos);

  return 0;

}
