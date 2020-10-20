//Gabriel Medeiros Jospin

/*
I see a little silhouette of a man
Scaramouche, Scaramouche
Will you do the Fandango?
Thunderbolt and lightning
Very, very frightening me
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


#define INVALIDO -1

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796020");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Gabriel Medeiros Jospin");
}


// elemento da lista
typedef struct estr {
    int valor;
    struct estr* prox;
} NO;


// funcao principal
NO* uniao(NO* p1, NO* p2);

//Insere Elemento
void inserir(NO* p,int valor);

//Exibe a tabela
void exibirLista(NO* );

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------


NO* uniao(NO* p1, NO* p2){
	NO* see1 = p1; //percorre a lista 1
	NO* see2 = p2; //percorre a lista 2
	NO* ant = NULL; // mostra o anterior da lista resposta
	NO* resp = NULL; //Lista final com a união
	int ult = -1; //mostra o último elemento da lista
	//Enquanto ainda houver elementos das duas listas ele seque
	while(see1 || see2){

		if(see1 && ((see2 && see1->valor == see2->valor) || see1->valor == ult)){
			//Se O Valor que está no see1 for igual o do see2 ele avança um na lista 1 
			see1 = see1->prox;
		}else if(see2 && see2->valor == ult){
			//se o valor que está no see2 for igual o ult ele avança um na lista 2
			see2 = see2->prox;
		}
		if(see1 && (!see2  || see1->valor<=see2->valor)){
			//Se o see1 for o menor faça:
			if(!ant){
				//se não huver anterior, inicia-se a lista
				resp = (NO*) malloc(sizeof(NO));
				resp->valor = see1->valor;
				resp->prox = NULL;
				ant = resp;
				see1 = see1->prox;	
			}else if(ult == resp->valor){
				//se o anterior for a resposta, começa-se o processo de passar para o prox
				resp->prox = (NO*) malloc(sizeof(NO));
				resp->prox->valor = see1->valor;
				resp->prox->prox = NULL;
				ult = see1->valor;
				ant = resp->prox;
				see1 = see1->prox;
			}else{
				// adiciona de forma genérica na fila
				ant->prox = (NO*) malloc(sizeof(NO));
				ant->prox->valor = see1->valor;
				ant->prox->prox = NULL;
				ult = ant->prox->valor;
				ant = ant->prox;
				see1 = see1->prox;
			}
		}else if(see2 && (!see1  || see2->valor< see1->valor)){
			//Se o see1 for o menor faça:
			if(!ant){
				//se não huver anterior, inicia-se a lista
				resp = (NO*) malloc(sizeof(NO));
				resp->valor = see2->valor;
				resp->prox=NULL;
				ult = see2->valor;
				ant = resp;
				see2 = see2->prox;
			}if(ant->valor == resp->valor){
				//se o anterior for a resposta, começa-se o processo de passar para o prox
				resp->prox = (NO*) malloc(sizeof(NO));
				resp->prox->prox = NULL;
				ult = see2->valor;
				resp->prox->valor = see2->valor;
				ant = resp->prox;
				see2 = see2->prox;
			}else{
				// adiciona de forma genérica na fila
				ant->prox = (NO*) malloc(sizeof(NO));
				ant->prox->valor = see2->valor;
				ant->prox = NULL;
				ult = ant->prox->valor;
				ant = ant->prox;
				see2 = see2->prox;
			}
		}
	}	

	printf("Inseriu\n");
	return resp;
}

//Código para iserir elementos
void inserir(NO* *p, int valor){
	//Cria-se um ponteiro lhando para o objeto e um olhando para seu anterior se tornandp visivel [ant], [i] e [prox]
	NO* aux = *p;
	NO* ant = NULL;

	//Se p nulo, não há lista, logo o objeto se insere no início
	if(!*p){
		NO* i = (NO*) malloc(sizeof(NO));
		i->valor = valor;
		i->prox = NULL;
		*p = i;
		return;
	}

	//Caso não seja nulo, percorre se todo a lista até o valor do auxiliar não ser mais menor que o valor procurado
	while(aux && aux->valor<=valor){
		ant = aux;
		aux = aux->prox;
	}

	NO* objeto = (NO*) malloc(sizeof(NO));
	ant->prox = objeto;
	objeto->prox = aux;
	objeto->valor = valor;
}


void exibirLista(NO* *p){
	//Percorre toda a lista exibindo seu valor;
	NO* aux = *p;
	printf("Lista: \n");
    printf("|KEY \t |\n");
    while (aux){
    	printf("|%i \t |\n",aux->valor);
    	aux = aux->prox;
    }
}


//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	NO* p1 = NULL;
	inserir(&p1,5);
	inserir(&p1,10);
	inserir(&p1,15);
	inserir(&p1,20);
	inserir(&p1,25);
	inserir(&p1,30);
	exibirLista(&p1);
	
	NO* p2 = NULL;
	inserir(&p2,2);
	inserir(&p2,3);
	inserir(&p2,5);
	inserir(&p2,5);
	inserir(&p2,7);
	inserir(&p2,11);
	inserir(&p2,13);
	inserir(&p2,17);
	inserir(&p2,19);
	inserir(&p2,23);
	inserir(&p2,23);
	inserir(&p2,29);
	inserir(&p2,31);
	inserir(&p2,37);
	inserir(&p2,41);
	inserir(&p2,43);
	inserir(&p2,47);
	exibirLista(&p2);

/*
	NO* p3 = NULL;
	exibirLista(&p3);

	NO* p4 = NULL;
	inserir(&p4,1);
	inserir(&p4,1);
	inserir(&p4,5);
	inserir(&p4,1);
	inserir(&p4,1);
	inserir(&p4,5);
	inserir(&p4,1);
	exibirLista(&p4);
*/
	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2
	NO* teste2 = uniao(p1,p2);
	exibirLista(&teste2);
}

// por favor nao inclua nenhum código abaixo da função main()'