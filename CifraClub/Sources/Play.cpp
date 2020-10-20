#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

// Tom 4
#define C 523.25 //Do
#define D 587.23 //Re
#define E 659.36 //Mi
#define F 698.46 //Fa
#define G 783.99 //Sol
#define A 880 // La
#define B 987.766602 //Si

#define MAX 300

typedef struct{
	float V[MAX];
}MUSICA;


float tomMusica(){
	system("color 2");
	system("title CifraPlay by: GabrielJospin");
	printf("%s", "qual o tom desejado (0,9]? (Padrao: 4) ");
	float tom = 0;
	scanf("	%f",&tom);
	if(tom<=0 || tom>9){
		printf("%s\n", "tom invalido" );
		return tomMusica();
	}
	tom = tom/4;
	return tom;
}


float teste(char nota[]){
	
	switch(nota[0]){
		case 'a':
			return A/2;
		case 'b':
			return B/2;
		case 'c':
			return C/2;
		case 'd':
			return D/2;
		case 'e':
			return E/2;
		case 'f':
			return F/2;
		case 'g':
			return G/2;
		case 'A':
			return A;
		case 'B':
			return B;
		case 'C':
			return C;
		case 'D':
			return D;
		case 'E':
			return E;
		case 'F':
			return F;
		case 'G':
			return G;
		default:
			return 0;
	}
}

int nome(){
	printf("%s\n", "Escolha a música a ser reprodusida");
	printf("\n %s\n", "1-Asa Branca-Luiz Gonzaga" );
	printf(" %s\n", "2-In The End-Linkin Park" );
	int num;
	scanf("%d",&num);
	if(num<0 || num>2){
		printf("%s\n", "Opcao Invalida");
		return nome();
	}
	return num;
}

int ler(MUSICA* musica, int nome){
	FILE* arq;
	char linha[100];
	char txt[100][100];
	char *result;
	int i=0;
	char aux[1];

	if(nome==1)arq = fopen("..\\midia\\AsaBranca.txt","rt");
	if(nome==2)arq = fopen("..\\midia\\InTheEnd.txt","rt");

	if(!arq) printf("%s\n", "Problemas na abertura do Arquivo!!" );

	while(!feof(arq)){
		result = fgets(linha,2,arq);
		strcpy(aux,linha);
		musica->V[i] = teste(aux);
		i++;
	}
	return i;
}
int main(){
	system("color 2");
	int num = nome();
	float tom = tomMusica();
	printf("\nTOCANDO NO TOM: %.2f\n", tom*4);
	MUSICA musica;
	int tam = 1;
	tam = ler(&musica,num);
	
	for(int i = 0; i<tam;i++){
		Beep(tom*musica.V[i],500);
	}

	return 0;
}