//Tarefa

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

//cria-se a Chave
typedef int KEY;

//cria-se o tipo ERRO, que retirna FALSO quando houver erro
typedef bool ERRO;

//cria-se o registro
typedef struct{
	KEY chave;
}REGISTRO;

//Cria-se a estura Elemento
typedef struct AUX{
	REGISTRO rg;
	AUX* prox;
}NO;

//cria-se o tipo ponteiro que aponta para um nó
typedef NO* PONT;

//Cria-se uma pilha
typedef struct{
	PONT topo;
	int numRegistros;
}PILHA;

//cria-se um tipo Lista
typedef struct{
    PONT ini;
    int numRegistros;
}LISTA;

//funções:
void inicializar(PILHA* p); //inicializa a pilha
void inicializar(LISTA* l);//Inicializa a Lista
void exibir(PONT p);//Imprime a lista ou pilha
PONT buscaElem(LISTA* l,KEY ch, PONT* ant);//Busca Elemento na lista e da seu anterior
ERRO inserir(LISTA* l, REGISTRO rg);//Adiciona um regstro ao topo da pilha, Se houver um erro ele retora FALSE
ERRO push(LISTA* l,REGISTRO rg);//insere elemento na lista, Se houver um erro ele retora FALSE
ERRO exclui(LISTA* l, KEY ch);//Exclui um elemento da lista, Se houver um erro ele retora FALSE
ERRO pop(PILHA* p, REGISTRO* rg); //Retira o elemento da pilha, e envia para o usuário no Registro informado
void reinicializar(PONT ini);//Reinicializa a lista ou pilha
ERRO inserirSemOrdem(LISTA* l, REGISTRO* rg); // Adiciona registro ai final da lista
NO* copiaInvertida(NO* p); //função do exercício

//------------------------------------------
// FUNÇÕES DE LISTA
//------------------------------------------

void inicializar(LISTA* l){
	l->ini = NULL;
    l->numRegistros = 0;
}

PONT buscaElem(LISTA* l,KEY ch, PONT* ant){
    PONT aux = l->ini;
    *ant = NULL;
    while(aux && aux->rg.chave < ch){
        *ant = aux;
        aux = aux->prox;

    }
    if(aux && aux->rg.chave == ch) return aux;
    else return NULL;    
}

bool inserir( LISTA* l, REGISTRO rg) {
	 NO* novo;
	 NO* ant;
	 novo = buscaElem(l, rg.chave, &ant);
	 if(novo) return(false);
	 	novo = (NO*) malloc(sizeof(NO));
	 	novo->rg.chave = rg.chave;
	 if(!l->ini) { // 1a. inserção em lista vazia
	 	l->ini = novo;
	 	novo->prox = NULL;
	 } else {
		 if(!ant) { // inserção no início da lista
		 	novo->prox = l->ini;
		 	l->ini = novo;
		 }else { // inserção após um nó existente
	 		novo->prox = ant->prox;
	 		ant->prox = novo;
	 }
	}
	 return(true);
}

ERRO inserirSemOrdem( LISTA* l, REGISTRO rg) {
	 NO* novo = (NO*) malloc(sizeof(NO));
	 novo->prox = NULL;
	 novo->rg = rg;
	 NO* ant;
	 NO* i = l->ini;
	 if(!l->ini){
	 	l->ini = novo;
	 	return true;
	 }
	 while(i){
	 	ant = i;
	 	i = i->prox;
	 }
	 ant->prox = novo;
	 novo->prox = i;
	 return true;
}


ERRO exclui(LISTA* l, KEY ch){
	PONT ant;
    PONT i;
    i = buscaElem(l,ch,&ant);
    if(!i)return false;
    if(!ant) l->ini=i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}

//------------------------------------------
// FUNÇÕES DE PILHA
//------------------------------------------
void inicializar(PILHA* p){
	p->topo = NULL;
}

ERRO push(PILHA* p, REGISTRO rg){
	NO* novo = (NO*) malloc(sizeof(NO));
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

//------------------------------------------
// FUNÇÕES DE LISTA OU PILHA
//------------------------------------------

void exibir(PONT p){
    PONT aux = p;
    printf("Lista: \n");
    printf("|KEY \t|\n");
    while (aux){
     printf("|%i \t|\n",aux->rg.chave);
        aux = aux->prox;
    }
}


void reinicializar(PONT ini) {
    PONT i = ini;
    while(i){
        PONT aux = i;
        i = i->prox;
        free(aux);
    }
    ini = NULL;
}

NO* copiaInvertida(NO* p) {
	NO* end = p;
	REGISTRO rg;

	PILHA aux;
	inicializar(&aux);

	LISTA resp;
	inicializar(&resp);

	while(end){
		push(&aux,end->rg);
		end= end->prox;
	}

	while(aux.topo){
		pop(&aux,&rg);
		inserirSemOrdem(&resp,rg);
	}

	return resp.ini;
}


//------------------------------------------
// TESTES
//------------------------------------------

void testeListas(){
	LISTA l;
	inicializar(&l);


	REGISTRO rg1;
	rg1.chave = 5;
	REGISTRO rg2;
	rg2.chave = 4;
	REGISTRO rg3;
	rg3.chave = 11;
	REGISTRO rg4;
	rg4.chave = 7;
	REGISTRO rg5;
	rg5.chave = 133;

	inserir(&l,rg1);
	inserir(&l,rg2);
	inserir(&l,rg3);
	inserir(&l,rg4);
	inserir(&l,rg5);

	exibir(l.ini);

	exclui(&l,rg3.chave);

	exibir(l.ini);
}

void testePilhas(){
	PILHA p;
	inicializar(&p);
	REGISTRO rg;

	REGISTRO rg1;
	rg1.chave = 5;
	REGISTRO rg2;
	rg2.chave = 4;
	REGISTRO rg3;
	rg3.chave = 11;
	REGISTRO rg4;
	rg4.chave = 7;
	REGISTRO rg5;
	rg5.chave = 133;

	push(&p,rg1);
	push(&p,rg2);
	push(&p,rg3);
	push(&p,rg4);
	push(&p,rg5);
	exibir(p.topo);

	pop(&p,&rg);

	exibir(p.topo);
}

void testePilhasLista(){
	LISTA l;
	inicializar(&l);
	LISTA l2;
	inicializar(&l2);


	REGISTRO rg1;
	rg1.chave = 5;
	REGISTRO rg2;
	rg2.chave = 4;
	REGISTRO rg3;
	rg3.chave = 11;
	REGISTRO rg4;
	rg4.chave = 7;
	REGISTRO rg5;
	rg5.chave = 133;

	inserir(&l,rg1);
	inserir(&l,rg2);
	inserir(&l,rg3);
	inserir(&l,rg4);
	inserir(&l,rg5);

	exibir(l.ini);

	l2.ini = copiaInvertida(l.ini);

	exibir(l2.ini);

}


int main(int argc, char const *argv[])
{
	testePilhasLista();
	return 0;
}