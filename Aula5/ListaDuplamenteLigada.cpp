//ListaDuplamenteLigada.cpp

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
    PONT cabeca;
    int numRegistros;
}LISTA;



void inicializar(LISTA* l);//inicializa a Lista
int tamanho(LISTA* l);//calcula o tamanho da Lista
void exibir(LISTA* l);//Exibe na tela a Lista
void exibirInvertida(LISTA* l);//exibe a Lista de forma decrescente
void insereAntes(LISTA* l,int ch, NO* atual);//insere elemento no final da Lista
bool insere(LISTA* l, REGISTRO rg); //insere elemento na posição correta da Lista
bool exclui(LISTA* d, int chave);//Exclui elemento da lista referente a chave
NO* encontrar(LISTA* l,int chave);//encontra elemento na lista
void reinicializa(LISTA* d);//reinicializa a Lista


void inicializar(LISTA* l){
	l->cabeca =(PONT) malloc(sizeof(NO));
	l->cabeca->prox = l->cabeca;
	l->cabeca->ant = l->cabeca;
}

int tamanho(LISTA* l){
	PONT aux = l->cabeca->ant;
	int tam = 0;
	while(aux != l->cabeca){
		tam++;
		aux = aux->ant;
	}
	return tam;
}

void exibir(LISTA* l){
	PONT aux = l->cabeca->prox;
	printf("%s\n", "Lista: Crescente" );
	printf("%s\t|\n","KEY");
	while(aux != l->cabeca){
		printf("%i\t|\n",aux->rg.chave);
		aux = aux->prox;
	}
}


void exibirInvertida(LISTA* l){
	PONT aux = l->cabeca->ant;
	printf("%s\n", "Lista: Decrescente" );
	printf("%s\t|\n","KEY");
	while(aux != l->cabeca){
		printf("%i\t|\n",aux->rg.chave);
		aux = aux->ant;
	}
}

void insereAntes(LISTA* l,int ch, NO* atual){
	NO* aux = l->cabeca->prox;
	while(aux != atual && aux != l->cabeca){
		aux = aux->prox;
	}

	if(aux == l->cabeca) return;

	NO* i = (NO*) malloc(sizeof(NO));
	i->rg.chave = ch;
	i->prox = aux;
	aux->ant->prox = i;
	i->ant = aux->ant;
	aux->ant = i;

}


bool insere(LISTA* l,REGISTRO rg){
	int min = l->cabeca->prox->rg.chave;
	int max = l->cabeca->ant->rg.chave;
	int med = (min+max)/2;
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->rg = rg;
	NO* i;
	if(rg.chave > med){
		i = l->cabeca->ant;
		while(i->rg.chave > rg.chave) i = i->ant;
		if(i->rg.chave == rg.chave) return false;
		novo->ant = i;
		novo->prox = i->prox;
		i->prox->ant = novo;
		i->prox = novo;
	}else{
		i=l->cabeca->prox;
		while(i->rg.chave < rg.chave) i = i->prox;
		if(i->rg.chave == rg.chave) return false;
		novo->prox = i;
		novo->ant = i->ant;
		i->ant->prox = novo;
		i->ant = novo;
	}
	printf("%s\n","inserido" );
	return true;
}

bool exclui(LISTA* l,int chave){
	int min = l->cabeca->prox->rg.chave;
	int max = l->cabeca->ant->rg.chave;
	int med = (min+max)/2;

	NO* i = encontrar(l,chave);
	if(!i) return false;
	NO* apaga = i;
	apaga->ant->prox = apaga->prox;
	apaga->prox->ant = apaga->ant;
	free(apaga);
	return true;

}

NO* encontrar(LISTA* l,int chave){
	
	NO* i = l->cabeca;

	int min = l->cabeca->prox->rg.chave;
	int max = l->cabeca->ant->rg.chave;
	int med = (min+max)/2;
	
	if(chave>max || chave<min) return NULL;

	if(chave >= med){

		do{
			i = i->ant;
		}while(i->rg.chave > chave);

		if(i==l->cabeca)return NULL;
		if(i->rg.chave!=chave)return NULL;

		NO* aux = i;
		return aux;
	}

	do{
		i = i->prox;
	}while(i->rg.chave < chave);
	
	if(i==l->cabeca)return NULL;
	if(i->rg.chave!=chave)return NULL;

	NO* aux = i;
	return aux;

}


void reinicializa(LISTA* l){
	NO* i = l->cabeca->prox;
	while(i != l->cabeca){
		NO* apaga = i;
		i = i->prox;
		free(apaga);
	}
	l->cabeca->prox = l->cabeca;
	l->cabeca->ant = l->cabeca;
}


int main(int argc, char const *argv[]){

	LISTA l1;
	inicializar(&l1);
	NO* i;


	REGISTRO rg1;
	rg1.chave = 1;
	REGISTRO rg2;
	rg2.chave = 2;
	REGISTRO rg3;
	rg3.chave = 3;
	REGISTRO rg4;
	rg4.chave = 5;
	REGISTRO rg5;
	rg5.chave = 8;
	REGISTRO rg6;
	rg6.chave = 13;

	REGISTRO rgF;
	REGISTRO rgI;

	inicializar(&l1);
	insere(&l1,rg4);
	insere(&l1,rg6);
	insere(&l1,rg2);
	insere(&l1,rg1);
	insere(&l1,rg5);
	insere(&l1,rg3);

	printf("Lista contem %i Registro(s)\n",tamanho(&l1));
	printf("%s\n","CRESCENTE:" );
	exibir(&l1);
	printf("%s\n","DECRESCENTE:" );
	exibirInvertida(&l1);
	if (exclui(&l1,13))printf("excluido o 13\n");
	if (exclui(&l1,5))printf("excluido o 5\n");
	if (exclui(&l1,14))printf("excluido o 14\n");
	exibir(&l1);
	exibirInvertida(&l1);
	i = encontrar(&l1,7);
	if(!i)printf("%s\n","Nao Achei!!!" );
	i = encontrar(&l1,2);
	if(i){
		printf("%s\n","Encontrei");
		insereAntes(&l1,1,i);
	}
	exibirInvertida(&l1);
	exibir(&l1);
	reinicializa(&l1);
	exibirInvertida(&l1);
	return 0;
}