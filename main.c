#include <stdio.h>
#include <stdbool.h>
#include "TorreDeHanoi.h"
                         
int validaEntrada(char c){
  int n;
  if(c == 'p') printf("Insira a quantidade de pinos: [3..5] ");
  else printf("Insira a quantidade de discos: [3..5] ");
  scanf("%d", &n);
  if(!(n >= 3 && n <= 5)){
    printf("Entrada invalida\n");
    n = validaEntrada(c);
  }
  return n;
}

bool validaMovimento(int n, int a, int b){
  if( a != b && (b >= 1 && b <= n) && (a >= 1 && a <= n)){
    return true;
  }
  return false;
}

void iniciaJogo(int n, int m){

  Pino **pinos, *pinoInicial;
  Disco *topoDiscoInicial, *iDisco, *nextDisco;
  
  pinos = criarPinos(n);

  pinoInicial = pinos[0];
  pinoInicial -> numDiscos = m + '0';
  pinoInicial -> top = criarDisco(m);
  
  for(int i = 0; i < n; i++){

    printf("Ponteiro do pino: %p\n", pinos[i]);
    printf("Ponteiro do proximo pino: %p\n", pinos[i + 1]);
    printf("Numero de discos no pino %d: %c\n", i + 1, pinos[i] -> numDiscos);
    //if(pinos[i] -> numDiscos != '0'){
      iDisco = pinos[i] -> top;
      printf("Tamanho do disco:\n%c, actual: %p, next: %p\n", iDisco -> TamDisco, iDisco , iDisco -> next);
      nextDisco = iDisco -> next;
      for(int j = 0; j < (iDisco -> TamDisco) - '0'; j++){
        printf("%c, actual: %p, next: %p\n", nextDisco -> TamDisco, nextDisco ,nextDisco -> next);
        nextDisco = nextDisco -> next;
      }
    //}
  }

  if(validaMovimento(n, 2, 3)){
    int t = moverDisco(pinos, 1, 2); //a, b--
    printf("t: %d\n", t);
  }else printf("n deu certo a entrada");

}


int main(void) {
  int n, m;
  n = validaEntrada('p');
  m = validaEntrada('d');
  iniciaJogo(n, m);
  

  return 0;
}