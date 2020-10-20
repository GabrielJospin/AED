#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

void mergeSort(int *A, int ini, int fim);

void intercala(int *A, int ini, int med, int fim);


void mergeSort(int *A, int ini, int fim){
	int n = fim - ini + 1;
	
	if(n >= 4){
		
		int med = (fim+ini)/2;
		int q1 = (ini+med)/2;
		int q3 = (med+fim)/2;
		
		mergeSort(A,ini,q1);
		mergeSort(A,q1+1,med);
		mergeSort(A,med+1,q3);
		mergeSort(A,q3+1,fim);

		intercala(A,ini,q1,med);
		intercala(A,med,q3,fim);
		intercala(A,ini,med,fim);

	}else{

	}
}


void intercala(int *A, int ini, int med, int fim){
	int aux;
	int count1 = ini;
	int count2 =med+1;
	while(A && count1<=med && count2 <=fim){
		if(*A[count1] > *A[count2]){
			aux = *A[count1];
			*A[count1] = *A[count2];
			*A[count1] = aux;
		}
		count2++;
	}
}


int main(){
	int A[100];
	A[0] = 9;
	A[1] = 4;
	A[2] = 8;
	A[3] = 3;
	A[4] = 7;
	A[5] = 4;
	A[6] = 6;
	A[7] = 1;
	A[8] = 5;
	A[9] = 0;

	mergeSort(&A,0,9);

	for(int i=0;i<=9;i++){
		printf("%i\n",A[i]);
	}

	return 0;
}