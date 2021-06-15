#include <stdlib.h>
#include "TorreDeHanoi.h"

Disco* criarDisco(int tam){
  Disco *disco = (Disco*)malloc(sizeof(Disco));
  disco -> TamDisco = tam + '0';
  disco -> next = NULL;
  return disco;
}

Disco* insereDiscos(Disco *disco, int tam){
  Disco* discoTopo;
  discoTopo = criarDisco(tam);
  discoTopo -> next = disco;
  return discoTopo;
}

Disco* removeDisco(Disco *disco){
  Disco *discoNext;
  discoNext = disco -> next;
  disco -> next = NULL;
  return discoNext;
}

Pino* criarPino(){
  Pino *pino;
  pino = (Pino*)malloc(sizeof(Pino));
  pino -> numDiscos = '0';
  pino -> top = NULL;
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

  Disco *discoOrigem, *discoDestino, *discoPivo;
  int tamDiscoOrigem, tamDiscoDestino;


  if((pinos[pinoOrigem] -> numDiscos) == '0'){
    printf("Movimento invalido\n");
    return 0;
  }

  if(pinos[pinoDestino] -> numDiscos != '0'){
    discoOrigem = pinos[pinoOrigem] -> top;
    discoDestino = pinos[pinoDestino] -> top;
          
    tamDiscoOrigem = (discoOrigem -> TamDisco) - '0';
    tamDiscoDestino = (discoDestino -> TamDisco) - '0';
          
    if(!(tamDiscoDestino > tamDiscoOrigem)){
      printf("Movimento invalido\n");
      return 0;
    }
  }
  return 1;
}

void imprimir(Pino **pinos, int numPinos, int numDiscos){
  
  Disco *disco;
  int numDiscosPino, linhaTemDisco, colunaHaste;
  int tamBase, tamHaste, tamDisco;
  int esquerdaPivo, direitaPivo;

  tamBase = 2*numDiscos + 3;
  tamHaste = numDiscos;
  colunaHaste = (tamBase - 1)/2;
 
  for(int p = 0; p < numPinos; p++){
    printf("\n");
    numDiscosPino = (pinos[p] -> numDiscos) - '0';
    
    if(numDiscosPino != 0){
      linhaTemDisco = (tamHaste) - numDiscosPino;
      disco = pinos[p] -> top;
    }else linhaTemDisco = tamHaste;
   
    for(int i = 0; i < tamHaste; i++){

      for(int j = 0; j < tamBase; j++){

        if(i >= linhaTemDisco){

          tamDisco = (disco -> TamDisco) - '0';

          esquerdaPivo = colunaHaste - tamDisco - 1;
          direitaPivo = colunaHaste + tamDisco;
          if(j == colunaHaste){
            printf("|");
          }else{
            if((j > esquerdaPivo && j < colunaHaste) || (j > colunaHaste && j <= direitaPivo)){
            printf("_");
            }else printf(" ");
          }
        }else{
          if(j != colunaHaste) printf(" ");
          else printf("|");
        }
      }
      if(i>= linhaTemDisco) disco = disco -> next;
      printf("\n");
    }
    for(int j = 0; j < tamBase; j++){
      if(j != colunaHaste) printf("_");
      else printf("|");
    }
    printf("\n\n");
    for(int i = 0; i < tamBase/2; i++)printf(" ");
    printf("%d\n", p + 1);
  }

}

Disco* pop(Pino *pino){
  Disco* discoTop, *discoNext;
  int numDiscos;

  discoTop = pino -> top;
  discoNext = removeDisco(discoTop);
  pino -> top = discoNext;

  numDiscos = pino ->numDiscos - '0';
  numDiscos--;
  pino -> numDiscos = numDiscos + '0';
  
  return discoTop;
}

void push(Pino *pino, Disco *disco){
  Disco *discoAnterior;
  int numDiscos;
 
  numDiscos = pino -> numDiscos - '0';
  numDiscos++;
  pino -> numDiscos = numDiscos + '0';
 
  discoAnterior = pino -> top;
  disco -> next = discoAnterior;

  pino -> top = disco;

}

void excluirPino(Pino *pino){
  free(pino);
}