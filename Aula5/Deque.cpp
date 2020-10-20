//Deque.cpp

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

typedef struct auxElem{
	REGISTRO rg;
	auxElem* prox;
	auxElem* ant;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	PONT cabeca;
}DEQUE;

void inicializar(DEQUE* d);//inicializa o Deque
int tamanho(DEQUE* d);//calcula o tamanho do Deque
void exibir(DEQUE* d);//Exibe na tela o Deque
ERRO insereFim(DEQUE* d, REGISTRO rg); //insere elemento no final do Deque
ERRO insereIni(DEQUE* d, REGISTRO rg); //insere elemento no inicio do Deque
ERRO excluiFim(DEQUE* d, REGISTRO* rg);//Exclui elemento do final do Deque e add a um registro
ERRO excluiIni(DEQUE* d, REGISTRO* rg);//Exclui elemento do inicio do Deque e add a um registro
void reinicializa(DEQUE* d);//reinicializa o Deque

void inicializar(DEQUE* d){
	d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
	d->cabeca->prox = d->cabeca;
	d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE* d){
	PONT aux = d->cabeca->prox;
	int tam=0;
	while(aux != d->cabeca){
		tam++;
		aux = aux->prox;
	}
	return tam;
}

void exibir(DEQUE* d){
	PONT aux = d->cabeca->prox;
	printf("%s\n","Deque:");
	printf("%s\t|\n","KEY" );
	while(aux != d->cabeca){
		printf("%i\t|\n",aux->rg.chave);
		aux = aux->prox; 
	}
}

ERRO insereFim(DEQUE* d, REGISTRO rg){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->rg.chave = rg.chave;
	novo->prox = d->cabeca;
	novo->ant = d->cabeca->ant;
	d->cabeca->ant = novo;
	novo->ant->prox = novo;
	return true;
}

ERRO insereIni(DEQUE* d, REGISTRO rg){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->rg.chave = rg.chave;
	novo->ant = d->cabeca;
	novo->prox = d->cabeca->prox;
	d->cabeca->prox = novo;
	novo->prox->ant = novo;
	return true;
}


ERRO excluiFim(DEQUE* d, REGISTRO* rg){
	if(d->cabeca->ant == d->cabeca) return false;
	PONT apagar = d->cabeca->ant;
	*rg = apagar->rg;
	d->cabeca->ant = apagar->ant;
	apagar->ant->prox = d->cabeca;
	free(apagar);
}

ERRO excluiIni(DEQUE* d, REGISTRO* rg){
	if(d->cabeca->prox == d->cabeca) return false;
	PONT apagar = d->cabeca->prox;
	*rg = apagar->rg;
	d->cabeca->prox = apagar->prox;
	apagar->prox->ant = d->cabeca;
	free(apagar);
}

void reinicializa(DEQUE* d){
	PONT aux = d->cabeca->prox;
	while(aux != d->cabeca){
		PONT apagar = aux;
		aux = aux->prox;
		free(apagar);
	}
	d->cabeca->prox = d->cabeca;
	d->cabeca->ant = d->cabeca;
}

int main(int argc, char const *argv[])
{
	printf("%s\n","Good morning");
	DEQUE d1;

	REGISTRO* rg1 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg1->chave = 1;
	REGISTRO* rg2 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg2->chave = 2;
	REGISTRO* rg3 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg3->chave = 3;
	REGISTRO* rg4 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg4->chave = 5;
	REGISTRO* rg5 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg5->chave = 8;
	REGISTRO* rg6 = (REGISTRO*) malloc(sizeof(REGISTRO));
	rg6->chave = 13;

	REGISTRO rgF;
	REGISTRO rgI;

	inicializar(&d1);
	insereFim(&d1,*rg4);
	insereFim(&d1,*rg5);
	insereFim(&d1,*rg6);
	insereIni(&d1,*rg3);
	insereIni(&d1,*rg2);
	insereIni(&d1,*rg1);

	printf("Deque criado com %i elemento(s)\n",tamanho(&d1));

	exibir(&d1);

	excluiIni(&d1,&rgI);
	excluiFim(&d1,&rgF);
	printf("Excluidos %i e %i \n",rgI.chave, rgF.chave);
	exibir(&d1);

	reinicializa(&d1);

	printf("%s\n","reinicializada" );

	exibir(&d1);	
	return 0;
}