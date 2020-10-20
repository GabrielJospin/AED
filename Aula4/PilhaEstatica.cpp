#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

//limite de elementos
#define MAX 50
#define VAZIO -1

//cria a chave
typedef int KEY;

//cria-se o tipo ERRO com FALSE para quando tiver erro
typedef bool ERRO;

//cria-se o registro
typedef struct{
	KEY chave;
}REGISTRO;

//cria-se a pilha
typedef struct{
	REGISTRO A[MAX];
	int topo;
}PILHA;

//Funções:
void inicializar(PILHA* p); //inicializa a lista
int tamanho(PILHA* p); //calcula o tamanho dela
void exibir(PILHA* p);//exibe para o usuário a pilha
ERRO push(PILHA* p, REGISTRO rg);//Adiciona um regstro ao topo da pilha, Se houver um erro ele retora FALSE
ERRO pop(PILHA* p,REGISTRO* rg);//Retira o elemento da Lista, e envia para o usuário no Registro informado
void reinicializar(PILHA* p);//Reinicializa a lista

//Criando-as

void inicializar(PILHA* p){
	p->topo = VAZIO;
}

int tamanho(PILHA* p) {
	return p->topo+1;
}

void exibir(PILHA* p){
	printf("Imprimindo Pilha: \n");
	for(int i = p->topo; i>=0; i--){
		printf("%i\t|\n",p->A[i].chave);
	}
}

ERRO push(PILHA* p, REGISTRO rg){
	if(p->topo >= MAX-1){
		printf("%s\n", "ERROR: Stack Overflow, the stack is full");
		return false;
	}
	p->A[p->topo+1] = rg;
	p->topo++;
	return true;
}

ERRO pop(PILHA* p, REGISTRO* rg){
	if(p->topo==VAZIO){
		printf("%s\n","ERROR: Stack EMPTY" );
		return false;
	}

	*rg = p->A[p->topo];
	p->topo--;
	return true;
}

void reinicializar(PILHA* p){
	p->topo = VAZIO;
}


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