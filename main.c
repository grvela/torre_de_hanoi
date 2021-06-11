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

Pino** iniciaJogo(int n, int m){
  Pino **pinos, *pinoInicial;
  Disco *discoTopo;

  pinos = criarPinos(n);
  pinoInicial = pinos[0];
  pinoInicial -> numDiscos = m + '0';
  pinoInicial -> top = criarDisco(0);
  discoTopo = pinoInicial -> top;
  
  for(int i = m; i >= 1; i--){
    discoTopo = insereDiscos(discoTopo, i);
  }

  pinoInicial -> top = discoTopo;

  return pinos;
}


int main(void) {
  int n, m;
  Pino **pinos;

  n = validaEntrada('p');
  m = validaEntrada('d');
  
  pinos = iniciaJogo(n, m);
  
  imprimir(pinos, n, m);
  
  
  return 0;
}