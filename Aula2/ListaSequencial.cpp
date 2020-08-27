
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 50

typedef int KEY;

typedef struct{
    KEY chave;
    int altura;
    int peso;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int numRegistros;
}LISTA;


void inicializarLista(LISTA* l){
    l->numRegistros = 0;
}

int tamanho(LISTA* l){
    return l->numRegistros;
}

void exibirLista(LISTA* l){
    int i = 0;
    printf("Lista: \n ");
    printf("|KEY \t |Peso \t |Altura \n");
    for(i=0; i<(l->numRegistros); i++){
        printf("|%i \t |%i \t |%i \n",l->A[i].chave,l->A[i].peso,l->A[i].altura);
    }
}


int buscaElemLista(LISTA* l,KEY ch){
    int i = 0;
    for(i=0;i<(l->numRegistros);i++){
        if((l->A[i].chave) == ch) return i;
    }
    return -1;
}


bool inserirElemLista(LISTA* l, REGISTRO rg, int i){
    int j;
    if ((l->numRegistros) == MAX || (i<0) || (i> l->numRegistros)) return false;
    for(j=l->numRegistros; j > i; j--) l->A[j] = l->A[j-1];
    l-> A[i] = rg;
    l->numRegistros++;
    return true;
}

bool inserirElemLista(LISTA* l, REGISTRO rg){
    if(l->numRegistros == MAX) return false;
    l->A[l->numRegistros] = rg;
    l->numRegistros++;
    return true;
}

bool excluirElemLista(LISTA* l, KEY ch){
    int pos, i;
    pos = buscaElemLista(l,ch);
    if(pos == -1) return false;
    for(i=pos; i<l->numRegistros; i++) l->A[i] = l->A [i+1];
    l->numRegistros --;
    return true;
}

void reinicializarLista(LISTA* l){
    l->numRegistros = 0;
}
/*
int ocorrencias(LISTA* l, KEY ch){
    int ocorrencia;

    for(int i =0;i<l->numRegistros;i++){
        if(l->A[i].chave == ch)ocorrencia++;
    }

    return ocorrencia;
}
*/
int ocorrencias(LISTA* l, int ch){
    int ocorrencia = 0;

    for(int i =0;i<l->numRegistros;i++){
        if(l->A[i].chave == ch)ocorrencia++;
    }

    return ocorrencia;
}


bool identicas(LISTA* l1, LISTA *l2) {
    if((l1->numRegistros) != (l2->numRegistros) )return false;
    
    for(int i=0; i<(l1->numRegistros);i++){
        if(l1->A[i].chave != l2->A[i].chave)return false;
    }

    return true;
}




int main(){

    //Inicializa Lista

    LISTA lista1;
    inicializarLista(&lista1);


    LISTA lista2;
    inicializarLista(&lista2);

    LISTA lista3;
    inicializarLista(&lista3);

    REGISTRO rg1;
    rg1.chave = 152;
    
    REGISTRO rg2;
    rg2.chave = 152;

    REGISTRO rg3;
    rg3.chave = 100;

    REGISTRO rg4;
    rg4.chave = 152;

    inserirElemLista(&lista1,rg1);
    inserirElemLista(&lista1,rg2);
    inserirElemLista(&lista1,rg3);
    inserirElemLista(&lista1,rg4);

    inserirElemLista(&lista2,rg1);
    inserirElemLista(&lista2,rg2);
    inserirElemLista(&lista2,rg3);
    inserirElemLista(&lista2,rg3);

    inserirElemLista(&lista3,rg1);
    inserirElemLista(&lista3,rg2);
    inserirElemLista(&lista3,rg3);

    LISTA  lista4;
    inicializarLista(&lista4);

    KEY teste = 152;

    printf("%i \t",tamanho(&lista1));
    printf("%i \t",tamanho(&lista2));
    printf("%i \t",tamanho(&lista3));
    printf("%i \n",tamanho(&lista4));

    if(identicas(&lista1,&lista1))printf("%s\n","Deu certo 1");
    if(!identicas(&lista1,&lista2))printf("%s\n","Deu certo 2");
    if(!identicas(&lista1,&lista3))printf("%s\n","Deu certo 3");
    if(!identicas(&lista1,&lista4))printf("%s\n","Deu certo 4");

    return 0;
}

