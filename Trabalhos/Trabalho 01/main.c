#include <stdio.h>

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe 
*/

//VocÃª deverÃ¡ modificar apenas a funÃ§Ã£o abaixo, vocÃª 
//nÃ£o pode modificar a assinatura dela
int concatena(char* s1, char* s2, char* sres, int* espacos){
  //===============
  //IMPLEMENTE AQUI
  //===============

  int tam1 = 0, tam2 = 0, tamTotal = 0, _espacos = 0;

  while (s1[tam1] != '\n') {
      sres[tam1] = s1[tam1];
      tam1++;
  }

  sres[tam1++] = ' ';

  while (s2[tam2] != '\n') {
      sres[tam1 + tam2] = s2[tam2];
      tam2++;
  }

  tamTotal = tam1 + tam2;
  sres[tamTotal] = '\0';

  for(int i = 0; i < tamTotal; i++){
    if(sres[i] == ' '){
      _espacos++;
    }
  }

  *espacos = _espacos;
  return tamTotal;

}

//Funcao para imprimir uma string, NÃ‚O MODIFIQUE
void print_string(char* str){
  int k = 0;
  while(str[k] != '\0'){
    printf("%c", str[k]);
    k++;
  }
  printf("\n");
}

//NÃ‚O MODIFIQUE a main
int main(int argc, char * argv[]){
  char frase1[40];
  char frase2[40];
  char fraseResultado[80];
  int tamResultado;
  int espacos;
  
  //lendo a entrada
  fgets(frase1, 40, stdin);
  fgets(frase2, 40, stdin);
  
  tamResultado = concatena(frase1, frase2, fraseResultado, &espacos);
  
  print_string(fraseResultado);
  printf("String com %d caracteres e %d espacos.\n", tamResultado, espacos);
  
  return 0;
}
