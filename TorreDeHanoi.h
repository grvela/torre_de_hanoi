#include <stdio.h>

#ifndef TORRE_HANOI
#define TORRE_HANOI

typedef struct disco Disco;
struct disco{
  Disco *next; 
  char TamDisco;
};

typedef struct pino Pino;
struct pino{
  Disco *top;
  char numDiscos; 
};

Pino** criarPinos(int n);
int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);
Pino* criarPino();
Disco* criarDisco(int tam);
Disco* insereDiscos(Disco *disco, int tam);
Disco* pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);

#endif