#include <stdio.h>

/*
  Luis Ricardo Albano Santos - 2021031844
  gcc -pedantic-errors -Wall main.c -o main.exe && ./main.exe 
*/

//VocÃª deverÃ¡ modificar apenas a funÃ§Ã£o abaixo, vocÃª 
//nÃ£o pode modificar a assinatura dela

int analizaString(char* sin, char* sres, int* tam){
  int espacos = 0;

  for(int i = 0; sin[i] != '\0'; i++){

    if(sin[i] == '\n'){
      continue;

    }else if(sin[i] == ' '){
      espacos = espacos + 1;
    }

    sres[*tam] = sin[i];
    *tam = *tam + 1;
  }

  return espacos;

}

int concatena(char* s1, char* s2, char* sres, int* espacos){
  //===============
  //IMPLEMENTE AQUI
  //===============

  int tamTotal = 0; 
  *espacos = 0;

  *espacos += analizaString(s1, sres, &tamTotal);

  sres[tamTotal++] = ' ';
  *espacos = *espacos + 1;

  *espacos += analizaString(s2, sres, &tamTotal);

  sres[tamTotal] = '\0';
  
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
