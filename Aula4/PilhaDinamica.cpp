//pilhaDinamica.cpp

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

//cria-se a Chave
typedef int KEY;

//ccria-se o tipo ERRO, que retirna FALSO quando houver erro
typedef bool ERRO;

//cria-se o registro
typedef struct{
	int chave;
}REGISTRO;

//Cria-se a estura Elemento
typedef struct AUX{
	REGISTRO rg;
	AUX* prox;
}ELEMENTO;

//cria-se o tipo pilha
typedef struct{
	ELEMENTO* topo;
}PILHA;

//cria-se o ponteiro de elemento
typedef ELEMENTO* PONT;

//funções
void inicializar(PILHA* p); //inicializa a pilha
int tamanho(PILHA* p); //calcula o tamanho dela
bool estaVazia(PILHA* p);//Responde true se a pilha estiver vazia
void exibir(PILHA* p);//exibe para o usuário a pilha
ERRO push(PILHA* p, REGISTRO rg);//Adiciona um regstro ao topo da pilha, Se houver um erro ele retora FALSE
ERRO pop(PILHA* p, REGISTRO* rg); //Retira o último elemento da pilha, e envia para o usuário no Registro informado
void reinicializar(PILHA* p);//Reinicializa a pilha

//Criando-as
void inicializar(PILHA* p){
	p->topo = NULL;
}

int tamanho(PILHA* p){
	PONT end = p->topo;
	int tam = 0;
	while(end){
		tam++;
		end = end->prox;
	}
	return tam;
}

bool estaVazia(PILHA* p){
	if(!p->topo)return true;
	return false;
}

void exibir(PILHA* p){
	PONT end = p->topo;
	while(end){
		printf("%i\t|\n",end->rg.chave);
		end = end->prox;
	}

}

ERRO push(PILHA* p, REGISTRO rg){
	ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	novo->rg = rg;
	novo->prox = p->topo;
	p->topo = novo;
	return true;
}

ERRO pop(PILHA* p, REGISTRO* rg){
	if(!p->topo){
		printf("%s\n","ERROR: Stack EMPTY" );
		return false;
	}
	*rg = p->topo->rg;
	PONT lula = p->topo;
	p->topo = p->topo->prox;
	free(lula);
	return true;
}

void reinicializar(PILHA* p){
	PONT pos = p->topo;
	while(pos->prox){
		PONT lula = pos;
		pos = pos->prox;
		free(lula);
	}
	p->topo = NULL;
}

//teste
int main(){

	PILHA p;
	REGISTRO rg;

	REGISTRO rg1;
	rg1.chave = 5;
	REGISTRO rg2;
	rg2.chave = 4;
	REGISTRO rg3;
	rg3.chave = 7;
	REGISTRO rg4;
	rg4.chave = 11;
	REGISTRO rg5;
	rg5.chave = 133;

	inicializar(&p);
	push(&p,rg1);
	printf("%i\n",p.topo->rg.chave);
	push(&p,rg2);
	push(&p,rg3);
	push(&p,rg4);
	push(&p,rg5);
	printf("Tamano: %i\n",tamanho(&p));
	exibir(&p);
	pop(&p,&rg);
	printf("Retirado: %i\n",rg.chave);
	exibir(&p);
	reinicializar(&p);
	pop(&p,&rg);
	return 0;
}