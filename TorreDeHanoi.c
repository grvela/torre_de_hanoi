#include <stdlib.h>
#include "TorreDeHanoi.h"

Disco* criarDisco(int tam){
  //verificar o valor a comparação com o NULL
  //NULL é um endereço de memoria não listado utilizado pelo computador para fazer as comparaçõaes
  // quando o NULL é comparado, os endereços de memoria sao os mesmo, por isso deve-se ter cuidado ao alocar um endereco de memoria para cada disco
  //verificar logica do , disco fantasta "0" pode ser prejudicial em comparações da logica do jogo
  Disco *disco;
  disco = (Disco*)malloc(sizeof(Disco));
  if(tam == 0){
    disco -> next = NULL;
    disco -> TamDisco = '0';
  }else{
    disco -> TamDisco = tam + '0';
    disco -> next = criarDisco(tam - 1);
  }
  return disco;
}

Pino* criarPino(){
  Pino *pino;
  pino = (Pino*)malloc(sizeof(Pino));
  pino -> numDiscos = '0';
  pino -> top = criarDisco(0);
  return pino;
}

Pino** criarPinos(int n){
  Pino **pinos = (Pino**)malloc(n * sizeof(Pino*));
  for(int i = 0; i < n; i++){
    pinos[i] = criarPino();
  }
  return pinos;
}

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino){

  Disco *discoOrigem, *discoDestino;
  int tamDiscoOrigem, tamDiscoDestino;

  if((pinos[pinoOrigem] -> numDiscos) == '0'){
    return 0;
  }

  if(pinos[pinoDestino] -> numDiscos != '0'){
    discoOrigem = pinos[pinoOrigem] -> top;
    discoDestino = pinos[pinoDestino] -> top;
          
    tamDiscoOrigem = (int)(discoOrigem -> TamDisco);
    tamDiscoDestino = (int)(discoDestino -> TamDisco);
          
    if(!(tamDiscoDestino > tamDiscoOrigem)){
      return 0;
    }
  }
  return 1;
}

void imprimir(Pino **pinos, int numPinos, int numDiscos){
  Disco *disco;
  int numDiscosPino, linhaTemDisco, colunaHaste;
  int tamBase, tamHaste, tamDisco;

  tamBase = 2*numDiscos + 3;
  tamHaste = numDiscos + 1;

  for(int p = 0; p < numPinos; p++){

    numDiscosPino = (int)(pinos[p] -> numDiscos) - '0';
    linhaTemDisco = (tamHaste - 1) - numDiscosPino;
    colunaHaste = (tamBase - 1)/2;
    disco = pinos[p] -> top;
    //resolver problema do ponteiro
    for(int i = 0; i < tamHaste - 1; i++){

      for(int j = 0; j < tamBase; j++){
        if(i < linhaTemDisco){
          if(j != colunaHaste) printf(" ");
          else printf("|");
        }else{
          tamDisco = (int)(disco -> TamDisco) - '0';
          if(tamDisco != 0){
            if((j >= colunaHaste - tamDisco) || (j > colunaHaste && j <= colunaHaste + tamDisco) ){
            printf("_");
            }else printf(" ");
          }
        }
      }
      disco = disco -> next;
      printf("\n");
    }
    for(int j = 0; j < tamBase; j++){
      if(j != colunaHaste) printf("_");
      else printf("|");
    }
    printf("\n");
  }

}

//Disco* pop(Pino *pino){

//}

void push(Pino *pino, Disco *disco){

}

void excluirPino(Pino *pino){

}