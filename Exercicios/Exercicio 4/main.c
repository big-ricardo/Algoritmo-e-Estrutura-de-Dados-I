#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;
typedef int bool;

int* cria_vetor(int n) {
  int* v = (int*)malloc(n * sizeof(int));
  return v;
}

int analisa_possibilidades(int* objetos, int* resposta,
  int quantidade_objetos, int indice_atual,
  int peso_total, int peso_atual) {

  if (peso_atual == peso_total) {
    return true;
  }

  if (indice_atual >= quantidade_objetos) {
    return false;
  }

  if (peso_atual > peso_total) {
    return false;
  }

  bool foi_adicionado = analisa_possibilidades(objetos, resposta,
    quantidade_objetos, indice_atual + 1, peso_total,
    peso_atual + objetos[indice_atual]);

  if (foi_adicionado) {
    resposta[indice_atual] = 1;
    return true;
  }

  bool sem_adicionar = analisa_possibilidades(objetos, resposta,
    quantidade_objetos, indice_atual + 1, peso_total,
    peso_atual);

  if (sem_adicionar) {
    resposta[indice_atual] = 0;
    return true;
  }

  return false;
}

int main(void) {

  int peso_total = 0;
  int quant_objetos = 0;

  scanf("%d", &peso_total);
  scanf("%d", &quant_objetos);

  int* objetos = cria_vetor(quant_objetos);
  int* resposta = cria_vetor(quant_objetos);

  for (int i = 0; i < quant_objetos; i++) {
    scanf("%d", &objetos[i]);
  }

  analisa_possibilidades(objetos, resposta, quant_objetos
    , 0, peso_total, 0);

  for (int i = 0; i < quant_objetos; i++) {
    printf("%d", resposta[i]);
  }
  printf("\n");

  free(objetos);
  free(resposta);

  return 0;

}
