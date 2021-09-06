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

  int tamTotal = 0; 
  *espacos = 0;

  while (s1[tamTotal] != '\n') {
      sres[tamTotal] = s1[tamTotal];
      tamTotal++;
  }

  sres[tamTotal++] = ' ';

  for(int i = 0; s2[i] != '\n'; i++){
    sres[tamTotal++] = s2[i];
  }

  sres[tamTotal] = '\0';

  for(int i = 0; i < tamTotal; i++){
    if(sres[i] == ' '){
      *espacos = *espacos + 1;
    }
  }
  
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
