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
	NO* proximo
	REGISTRO* rg;
	int posicao;
}NO;

typedef struct{
	NO* inicial
    int numRegistros;
}LISTA;


void incializarLista(LISTA* l){
    l->numRegistros = 0;
    NO ini;
    ini.posicao = 0;
    l->No->inicial = ini;
}

int tamanho(LISTA* l){
    return l->numRegistros;
}

void exibirLista(LISTA* l){
    int i = 0;
    printf("Lista: \n ");
    printf("|KEY \t |Peso \t |Altura \n");
    No aux = l->ini;
    for(i=0; i<(l->numRegistros); i++){
        printf("|%i \t |%i \t |%i \n",aux.proximo->rg->chave,aux.proximo->rg->peso,aux.proximo->rg->altura);
    	aux = aux.proximo
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
    l->numRegistros ++;
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



int main(){

    //Inicializa Lista

    LISTA lista;
    incializarLista(&lista);

    //Gabriel
    REGISTRO rgGabriel;
    rgGabriel.chave = 152;
    rgGabriel.peso = 80;
    rgGabriel.altura = 170;

    //Leticia
    REGISTRO rgLeticia;
    rgLeticia.chave = 176;
    rgLeticia.peso = 60;
    rgLeticia.altura = 150;

    //Carol
    REGISTRO rgCarol;
    rgCarol.chave = 293;
    rgCarol.peso = 40;
    rgCarol.altura = 140;

    //Testes
    printf("Testes \n");
    //Inserir
    if(inserirElemLista(&lista,rgGabriel))printf("Deu certo pro Gabriel \n");
    if(inserirElemLista(&lista,rgLeticia))printf("Deu certo pro Leticia \n");
    if(inserirElemLista(&lista,rgCarol,2))printf("Deu certo pro Carol \n");
    printf("Tamanho: %i \n",tamanho(&lista));
    printf("Carol está em %i\n",buscaElemLista(&lista,rgCarol.chave));
    printf("Exibindo lista: \n");
    exibirLista(&lista);
    if(excluirElemLista(&lista, rgGabriel.chave))printf("Excluindo Gabriel ");
    exibirLista(&lista);
    reinicializarLista(&lista);
    return 0;
}

