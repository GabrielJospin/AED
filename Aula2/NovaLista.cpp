#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define INVALIDO -1

typedef int KEY;
typedef bool ERRO;
typedef struct{
    KEY chave;
    int altura;
    int peso;
}REGISTRO;

typedef struct ELEMENTO{
    REGISTRO rg;
    ELEMENTO* prox;
}NO;


typedef NO* PONT;

typedef struct{
    PONT ini;
    int numRegistros;
}LISTA;




void incializarLista(LISTA* l){
    l->ini = NULL;
    l->numRegistros = 0;
}

int tamanho(LISTA* l){
    PONT aux = l->ini;
    int tam = 0;
    while(aux){
        tam++;
        aux=aux->prox;
    }
    l->numRegistros = tam;
    return tam;
}

void exibirLista(LISTA* l){
    PONT aux = l->ini;
    printf("Lista: \n");
    printf("|KEY \t |Peso \t |Altura \n");
    while (aux){
     printf("|%i \t |%i \t |%i \n",aux->rg.chave, aux->rg.peso, aux->rg.altura);
    	aux = aux->prox;
    }
}

void exibirLista(PONT p){
    PONT aux = p;
    printf("Lista: \n");
    printf("|KEY \t |Peso \t |Altura \n");
    while (aux){
     printf("|%i \t |%i \t |%i \n",aux->rg.chave, aux->rg.peso, aux->rg.altura);
        aux = aux->prox;
    }
}


PONT buscaElemLista(LISTA* l,KEY ch){
    PONT aux = l->ini;
    while(aux && aux->rg.chave < ch) aux = aux->prox;
    if(aux && aux->rg.chave == ch) return aux;
    else return NULL;   
}

PONT buscaElemLista(LISTA* l,KEY ch, PONT* ant){
    PONT aux = l->ini;
    *ant = NULL;
    while(aux && aux->rg.chave < ch){
        *ant = aux;
        aux = aux->prox;

    }
    if(aux && aux->rg.chave == ch) return aux;
    else return NULL;    
}

ERRO inserirElemLista(LISTA* l, REGISTRO rg){
    KEY chave = rg.chave;
    PONT ant;
    PONT i;
    
    //i = buscaElemLista(l,chave,&ant);
    //if(i) return true;
    i = (PONT) malloc(sizeof(NO));
    i->rg = rg;
    if(l->numRegistros == 0){
        i->prox = NULL;
        l->ini = i;
        l->numRegistros++;
        return false;
    }else{
        if(ant){
            i->prox = l->ini;
            l->ini = i;
        }else{
            i->prox = ant->prox;
            ant->prox = i;
        }
    l->numRegistros+=1;


        return false;
    }

}

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

ERRO excluirElemLista(LISTA* l, KEY ch){
    PONT ant;
    PONT i;
    i = buscaElemLista(l,ch,&ant);
    if(!i)return true;
    if(!ant) l->ini=i->prox;
    else ant->prox = i->prox;
    free(i);
    return false;
}


void reinicializarLista(LISTA* l) {
    PONT i = l->ini;
    while(i){
        PONT aux = i;
        i = i->prox;
        free(aux);
    }
    incializarLista(l);
}

int ocorrencias(LISTA* l,int x){
    if(tamanho(l) == 0) return false;
    int contador = 0;
    PONT aux = l->ini;
    while(aux){
        if(aux->rg.chave == x)contador++;
        aux = aux->prox;
    }
    return contador;
}

bool identicas(LISTA* l1, LISTA* l2){
    if(tamanho(l1)!=tamanho(l2)) return false;
    PONT aux1 = l1->ini;
    PONT aux2 = l2->ini;
    while(aux1){
        if(aux1->rg.chave != aux2->rg.chave)return false;
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return true;
}
    
ERRO excluirOcorrencias(LISTA* l, KEY ch){
    PONT ant;
    PONT i = l->ini;
    while(i->prox){
        ant = i;
        i = i->prox;
        if(i->rg.chave == ch){
            ant->prox = i->prox;
            free(i);
        }

    }
    return false;
}

NO* copia(NO* p){
    NO* ini = (NO*) malloc(sizeof(NO));
    ini->rg = p->rg;
    NO* aux = ini;
    while(p->prox){
        aux->prox = (NO*) malloc(sizeof(NO));
        aux->prox->rg = p->prox->rg;
        aux = aux->prox;
        p = p->prox;
    }
    return ini;
}


void testeCriacao(){
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

    PONT teste;

    //Testes
    printf("Testes \n");
    //Inserir
    if(!inserirElemLista(&lista,rgGabriel))printf("Deu certo pro Gabriel \n");
    if(!inserirElemLista(&lista,rgLeticia))printf("Deu certo pra Leticia \n");
    if(!inserirElemLista(&lista,rgCarol))printf("Deu certo pra Carol \n");
    printf("Tamanho: %i \n",lista.numRegistros);
    printf("Tamanho: %i \n",tamanho(&lista));
    printf("Carol esta em %i\n",buscaElemLista(&lista,rgCarol.chave));
    printf("Exibindo lista: \n");
    exibirLista(&lista);
    if(!excluirElemLista(&lista, rgCarol.chave))printf("Excluindo Gabriel \n");
    printf("%s\n","Re exibir lista:" );
    exibirLista(&lista);
    reinicializarLista(&lista);
}

void testeComparacao(){
    LISTA lista1;
    incializarLista(&lista1);
    LISTA lista2;
    incializarLista(&lista2);

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

    REGISTRO rgLucien;
    rgLucien.chave = 777;
    rgLucien.peso = 80;
    rgLucien.altura = 160;

    REGISTRO rgCristina;
    rgCristina.chave = 666;
    rgCristina.peso = 60;
    rgCristina.altura = 162;

    //inserirElemLista(&lista1,rgGabriel);
    inserirElemLista(&lista1,rgCarol);
    //inserirElemLista(&lista1,rgGabriel);
    inserirElemLista(&lista1,rgCristina);
    inserirElemLista(&lista1,rgGabriel);
    inserirElemLista(&lista1,rgLucien);


    exibirLista(&lista1);
    printf("%d\n", ocorrencias(&lista1,rgGabriel.chave));  
    if(excluirOcorrencias(&lista1, rgGabriel.chave))printf("%s\n", "nao Excluidos");
    exibirLista(&lista1);
    
}

int main(){
    testeComparacao();

    //Inicializa Lista

   
    return 0;
}

