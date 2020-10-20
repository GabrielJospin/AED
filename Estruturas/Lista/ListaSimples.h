//ListaSimples.h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int KEY;
 
typedef struct REGISTRO{
	KEY chave;
}REGISTRO;


typedef bool ERRO;

typedef struct ELEMENTO{
	REGISTRO rg;
    ELEMENTO* prox;
}NO;


typedef NO* PONT;

typedef struct{
    PONT ini;
}LISTA;

void nome(){
	printf("%s\n","Gabriel J." );
}

void inicializa(LISTA* l){
    l->ini = NULL;
}

void exibir(LISTA* l){
    PONT aux = l->ini;
    printf("Lista: \n");
    printf("|KEY \t |\n");
    while (aux){
     printf("|%i \t |",aux->rg.chave);
    	aux = aux->prox;
    }
}