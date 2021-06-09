#include <stdio.h>
#include "TorreDeHanoi.h"

//controllers
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

//talvez seja melhor um retorno pinos **pinos
void iniciaJogo(int n, int m){
  Pino **pinos, *pinoInicial;
  Disco *topoDiscoInicial, *iDisco, *nextDisco;
  
  //verificar se todos os pinos estão vazios. Eu setei que para tam == 0 -> NULL //n tava declarado porra

  pinos = criarPinos(n);
  pinoInicial = pinos[0];

  pinoInicial -> numDiscos = m + '0';
  pinoInicial -> top = criarDisco(m);
  
  // inicio de codigo auxiliar
  for(int i = 0; i < n; i++){
    printf("Numero de discos no pino %d: %c\n", i + 1, pinos[i] -> numDiscos);
    if(pinos[i] -> numDiscos != '0'){
      iDisco = pinos[i] -> top;
      printf("Tamanho do disco:\n%c, actual: %p,next: %p\n", iDisco -> TamDisco, iDisco , iDisco -> next);
      nextDisco = iDisco -> next;
      for(int j = 0; j < (iDisco -> TamDisco) - '0'; j++){
        printf("%c, actual: %p, next: %p\n", nextDisco -> TamDisco, nextDisco ,nextDisco -> next);
        nextDisco = nextDisco -> next;
      }
    }
  }
  //fim codigo auxiliar
  //printf("%p %c\n", pinoInicial, pinoInicial -> numDiscos);
  
}


int main(void) {
  int n, m;
  n = 3;
  m = 3;
  iniciaJogo(n, m);

  return 0;
}