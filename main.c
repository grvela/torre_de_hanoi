#include <stdio.h>
#include <stdbool.h>
#include "TorreDeHanoi.h"
                         
int totalJogadas = 0;

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
  printf("Movimento invalido\n");
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

bool checaVitoria(Pino **pinos, int n){
  char numDiscos =  n + '0';
  if(pinos[0] -> numDiscos == '0'){
    for(int i = 1; i < n; i++){
      if(pinos[i] -> numDiscos == numDiscos){
        return true;
      }
    }
  }
  return false;
}

int main(void) {
  int numPinos, numDiscos;
  int pinoOrigem, pinoDestino;

  Pino **pinos;
  Disco *discoTop;

  numPinos = validaEntrada('p');
  numDiscos = validaEntrada('d');
  
  pinos = iniciaJogo(numPinos, numDiscos);
  
  imprimir(pinos, numPinos, numDiscos);
  
  while(!checaVitoria(pinos, numDiscos)){
    printf("Insira os pinos de origem e de destino: ");
    scanf("%d %d", &pinoOrigem, &pinoDestino);
  

    if(validaMovimento(numPinos, pinoOrigem, pinoDestino)){

      pinoOrigem--;
      pinoDestino--;

      if(moverDisco(pinos, pinoOrigem, pinoDestino)){
        
        discoTop = pop(pinos[pinoOrigem]);
        push(pinos[pinoDestino], discoTop);
        totalJogadas++;

      }

    }
    imprimir(pinos, numPinos, numDiscos);
  }
  printf("PARABENS VOCE CONSEGUIU\n");
  printf("TOTAL DE JOGADAS: %d\n", totalJogadas);
  return 0;
}