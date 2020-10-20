
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
    REGISTRO A[MAX+1];
    int numRegistros;
}LISTA;


void inicializarLista(LISTA* l){
    l->numRegistros = 0;
}

int tamanho(LISTA* l){
    return l->numRegistros;
}

void print(LISTA* l){
    int i = 0;
    printf("Lista: \n");
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

int buscaSentinela(LISTA* l, KEY ch){
    l->A[l->numRegistros].chave = ch;
    int i =0;
    while(l->A[i].chave != ch) i++;
    if (i != l->numRegistros)return i;
    else return -1;
}

int buscaBinaria(LISTA* l, KEY ch){
    int esq = 0;
    int dir = l->numRegistros;
    while(esq < dir){
        int meio = (esq+dir)/2;
        if(l->A[meio].chave == ch) return meio;
        if(l->A[meio].chave >= ch)dir = meio-1;
        if(l->A[meio].chave == ch)esq = meio+1;    
    }
    
    return -1;
}

void print(LISTA* l, KEY ch){
        int i = buscaBinaria(l,ch);
    printf("Linha: \n");
    printf("|KEY \t |Peso \t |Altura \n");
    printf("|%i \t |%i \t |%i \n",l->A[i].chave,l->A[i].peso,l->A[i].altura);
    
}

bool inserirElemLista(LISTA* l, REGISTRO rg){
    if(l->numRegistros >= MAX) return true;
    int pos = l->numRegistros;
    while(  pos > 0 && l->A[pos-1].chave > rg.chave){
        l->A[pos] = l->A[pos+1];
        pos --;
    }
    l->A[l->numRegistros] = rg;
    l->numRegistros++;
    return false;
}

bool excluirElemLista(LISTA* l, KEY ch){
    int pos, i;
    pos = buscaBinaria(l,ch);
    if(pos == -1) return false;
    for(i=pos; i<l->numRegistros; i++) l->A[i] = l->A [i+1];
    l->numRegistros --;
    return true;
}

void reinicializarLista(LISTA* l){
    l->numRegistros = 0;
}

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
    LISTA lista1;
    LISTA lista2;

    REGISTRO rg1;
    rg1.chave =1 ;
    rg1.altura =170;
    rg1.peso =70;

    REGISTRO rg2;
    rg2.chave =2 ;
    rg2.altura =180;
    rg2.peso =90;

    REGISTRO rg3;
    rg3.chave =3 ;
    rg3.altura =150;
    rg3.peso =60;

    REGISTRO rg4;
    rg4.chave =4 ;
    rg4.altura =160;
    rg4.peso =55;

    REGISTRO rg5;
    rg5.chave =5 ;
    rg5.altura =175;
    rg5.peso =74;


    inicializarLista(&lista1);
    inicializarLista(&lista2);

    if (inserirElemLista(&lista1, rg1))printf("Error inserction rg1\n");;
    inserirElemLista(&lista1, rg2);
    inserirElemLista(&lista1, rg3);
    inserirElemLista(&lista1, rg4);


    inserirElemLista(&lista2, rg1);
    inserirElemLista(&lista2, rg2);
    inserirElemLista(&lista2, rg3);
    inserirElemLista(&lista2, rg5);
    
    if(ocorrencias(&lista2,rg1.chave)>0)printf("Teste 1\n");

    if(!identicas(&lista2,&lista1))printf("Teste 2\n");
    return 0;
}

