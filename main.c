#include <stdio.h>
#include <stdbool.h>
#include "TorreDeHanoi.h"
                         
int totalJogadas = 0;

int validaEntrada(char c){
  /*
  Esta função valida o range da entrada para pinos e discos, retornando o numero da entrada caso o valor passe na condição
  */
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
  /*
  Esta função valida o movimento dos discos entre os pinos, retornando verdadeiro caso a entrada esteja no range de pinos e falso caso contrario
  */
  if( a != b && (b >= 1 && b <= n) && (a >= 1 && a <= n)){
    return true;
  }
  printf("Movimento invalido\n");
  return false;
}

Pino** iniciaJogo(int n, int m){
  /*
  Esta função starta o jogo da torre de hanoi, criando os pinos e alocando os discos no pino principal 
  */

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

bool checaVitoria(Pino **pinos, int numDiscos, int numPinos){
  /*
  Esta função checa se o usuario ja venceu o jogo, baseando-se na condição de que o primeiro pino deverá estar vazio e um entre os outros pinos deverá conter todos os discos
  */
  char numDiscosC =  numDiscos + '0';
  if(pinos[0] -> numDiscos == '0'){
    for(int i = 1; i < numPinos; i++){
      if(pinos[i] -> numDiscos == numDiscosC){
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

  while(!checaVitoria(pinos, numDiscos, numPinos)){
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

  for(int i = 0; i < numPinos; i++){
    excluirPino(pinos[i]);
  }

  printf("PARABENS VOCE CONSEGUIU\n");
  printf("TOTAL DE JOGADAS: %d\n", totalJogadas);
  return 0;
}