
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


typedef int KEY;
typedef bool ERRO;
typedef struct{
    KEY chave;
}REGISTRO;

typedef struct ELEMENTO{
    REGISTRO rg;
    ELEMENTO* prox;
    ELEMENTO* ant;
}NO;

typedef NO* PONT;

typedef struct{
    PONT ini;
    int numRegistros;
}LISTA;

void inicializar(LISTA* l);//inicializa a Lista
int tamanho(LISTA* l);//calcula o tamanho da Lista
void exibir(LISTA* l);//Exibe na tela a Lista
void insereAntes(LISTA* l,int ch, NO* atual);//insere elemento no final da Lista
bool insere(LISTA* l, REGISTRO rg); //insere elemento na posição correta da Lista
bool exclui(LISTA* d, int chave);//Exclui elemento da lista referente a chave
NO* encontrar(LISTA* l,int chave);//encontra elemento na lista
void reinicializa(LISTA* d);//reinicializa a Lista
NO* listaNumerada(int n);//Cria a lista de n elementos ordenados;

void inicializar(LISTA* l){
	l->ini = (NO*) malloc(sizeof(NO));
	l->ini->prox = NULL;
	l->ini->ant = NULL;
}

int tamanho(LISTA* l){
	PONT aux = l->ini;
	int tam = 0;
	while(aux){
		tam++;
		aux = aux->prox;
	}
	return tam;
}

void exibir(LISTA* l){
	PONT aux = l->ini;
	printf("%s\n", "Lista: Crescente" );
	printf("%s\t|\n","KEY");
	while(aux){
		printf("%i\t|\n",aux->rg.chave);
		aux = aux->prox;
	}
}


void insereAntes(LISTA* l,int ch, NO* atual){
	NO* i = (NO*) malloc(sizeof(NO));
	i->rg.chave = ch;
	i->prox = atual;
	atual->ant->prox = i;
	i->ant = atual->ant;
	atual->ant = i;
	if(atual == l->ini){
		l->ini = i;
	}

}

bool insere(LISTA* l, REGISTRO rg){
	printf("insere %d\n",rg.chave );
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->rg = rg;
	printf("%s\n","criado" );
	if(!l->ini){
		printf("%s\n","lista Nula");
		l->ini = novo;
		novo->prox = NULL;
		novo->ant = NULL;
		return true;
	}else if(l->ini->rg.chave > rg.chave){
		printf("%s\n","insere elemento antes da lista" );
		NO* aux = l->ini;
		novo->ant = NULL;
		novo->prox = aux;
		aux->ant = novo;
		l->ini = novo;
		return true;
	}else {
		printf("%s\n","Padrão" );
		NO* i = l->ini;
		while( i && i->rg.chave < rg.chave){
			printf("loop %d\n",i->rg.chave );
			i=i->prox;
		}
		if(i->rg.chave == rg.chave) return false;
		i = i->ant;
		novo->ant = i;
		novo->prox = i->prox;
		i->prox->ant = novo;
		i->prox = novo;
		return true;
	}

}


bool exclui(LISTA* l,int chave){

	NO* i = encontrar(l,chave);
	if(!i) return false;
	NO* apaga = i;
	apaga->ant->prox = apaga->prox;
	apaga->prox->ant = apaga->ant;
	free(apaga);
	return true;

}

NO* encontrar(LISTA* l,int chave){
	
	NO* i =l ->ini;

	
	while(i->rg.chave < chave){
		i = i->prox;
	}
	
	if(i->rg.chave!=chave)return NULL;

	return i;

}


void reinicializa(LISTA* l){
	NO* i = l->ini;
	while(i){
		NO* apaga = i;
		i = i->prox;
		free(apaga);
	}
	l->ini = NULL;
}

NO* listaNumerada(int n){
	NO* resp = (NO*) malloc(sizeof(NO));
	resp->ant = NULL;
	NO* i = resp;
	NO* novo = NULL;
	resp->rg.chave = 1;

	int key = 2;

	while(key<=n){
		novo = (NO*) malloc(sizeof(NO));
		if(key==2){
			novo->rg.chave = key;
			novo->ant = resp;
			resp->prox = novo;
			novo->prox = NULL;
		}else{
			novo->rg.chave = key;
			novo->ant=i;
			novo->prox = NULL;
			i->prox = novo;
			
		}
		NO* aux = i;
		i=i->prox;
		i->ant = aux;
		key++;
	}
	i->prox =NULL;
	return resp;

}

void moverParaFim(LISTA* l, NO* p){
	NO* i = l->ini;
	
	while(i && i!=p){
		i = i->prox;
	}

	if(!i) return;
	NO* aux = i;
	i->ant->prox = aux->prox;
	i->prox->ant = aux->ant;
	
	while(i->prox){
		i = i->prox;
	}

	i->prox = p;
	p->ant = i;
	p->prox = NULL;

}


int main(int argc, char const *argv[]){

	LISTA l1;
	inicializar(&l1);
	NO* a = listaNumerada(100);
	l1.ini = a;
	exibir(&l1);
	NO* rg = encontrar(&l1, 42);
	moverParaFim(&l1,rg);
	printf("%s\n","42" );
	rg = encontrar(&l1, 55);
	moverParaFim(&l1,rg);
	printf("%s\n","55" );
	rg = encontrar(&l1, 56);
	moverParaFim(&l1,rg);
	printf("%s\n","56" );
	rg = encontrar(&l1, 56);
	moverParaFim(&l1,rg);
	printf("%s\n","56" );
	exibir(&l1);
	return 0;
}