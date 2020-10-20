#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>


int main(){
	FILE* arq;
	char linha[100];
	char txt[100][100];
	char *result;
	int i=0;

	arq = fopen("Cifra.txt","rt");

	if(!arq) printf("%s\n", "Problemas na abertura do Arquivo!!" );

	while(!feof(arq)){
		result = fgets(linha,2,arq);
		strcpy(txt[i],linha);
		if(strcmp("a",txt[i]) == 0 || strcmp("A",txt[i]) == 0 )printf("\t%s\n",txt[i]);
		i++;
	}
}