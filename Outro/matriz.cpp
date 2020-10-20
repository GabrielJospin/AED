#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

typedef int vetor[100][100]; // Define o Vetor como uma matriz nxn
typedef bool error;//Cria um booleano quando o código der errado

typedef struct {
	vetor V;
	int n;
	int m;
}Matriz;
/*
	Definição da Matriz Am,n

	|a11 | a12 | a13 | ... | a1n |
	|a21 | a22 | a23 | ... | a2n |
	|a31 | a32 | a33 | ... | a3n |
	|...                         |
	|am1 | am2 | am3 | ... | amn |

*/

//OPERAÇÕES
  
// [Cn,m]ij = [An,m]ij + [Bn,m]ij , i e j pertencem aos Z | 0<i<m e 0<j<n
error Somatoria(Matriz* A, Matriz* B, Matriz* C){
	if((A->n != B->n) || (A->m != B->m)) return false;
	if((A->n != C->n) || (A->m != C->m)) return false;

	for(int i = 0; i<A->n; i++){
		for(int j = 0; j<A->m;j++){
			C->V[i][j] = A->V[i][j] + B->V[i][j];
		}
	}
}

int SomatoriaVetor(int A[], int tamanho){
	if(tamanho < 0) return 0;
	else return SomatoriaVetor(A,tamanho-1) + A[tamanho];
}

//Multiplica a Matriz A por (-1)
void minus(Matriz* A){
	for(int i = 0; i<A->n; i++){
		for(int j = 0; j<A->m;j++){
			A->V[i][j] = - A->V[i][j];
		}
	}
}


//COMPARAÇÕES

// só é verdadeiro se para todo [A]ij vc tiver um [B]ij de mesmo valor
bool equals (Matriz* A, Matriz* B){
	if ((B->n != A->n)||(A->m != B->m))return false;

	for(int i = 0; i<A->n; i++){
		for(int j = 0; j<A->m;j++){
			if(A->V[i][j] != B->V[i][j])return false;
		}
	}

	return true;
}

//CONSTRUÇÕES

//Atribui a Matriz B todos os itens da Matriz A
error iguala (Matriz* A, Matriz* B){
	if ((B->n != A->n)||(A->m != B->m))return false;

	for(int i = 0; i<A->n; i++){
		for(int j = 0; j<A->m;j++){
			B->V[i][j] = A->V[i][j];
		}
	}
	return true;
}

void neutro (int n, Matriz* N){
	N->n = n;
	N->m =n ;
	for(int i = 0; i<N->n; i++){
		for(int j = 0; j<N->m;j++){
			if(i==j) N->V[i][j] =1;
			else N->V[i][j] = 0; 
		}
	}
}

//SAIDAS

//Printa na tela a Matriz A
void print(Matriz* A){
	printf("| %s | \t", " ");
	for(int k = 0; k<A->n; k++){
		printf("%d| \t", k);
	}
	printf("\n");
	for(int i = 0; i<A->n; i++){
		printf("| %d | \t", i);
		for(int j = 0; j<A->m; j++){
			printf("%d| \t", A->V[i][j]);
		}
		printf("\n");
	}
}


int main(){
	
	Matriz A;

	A.V[0][0]=1;
	A.V[0][1]=2;
	A.V[0][2]=3;
	
	A.V[1][0]=1;
	A.V[1][1]=2;
	A.V[1][2]=3;

	A.V[2][0]=1;
	A.V[2][1]=2;
	A.V[2][2]=3;

	A.n=3;
	A.m=3;

	Matriz B;
	neutro(3,&B);
	printf("%d \n",SomatoriaVetor(A.V[1],3));
	printf("%s\n", "Inicio dos testes" );
	print(&B);
	printf("%s\n", "fim dos testes" );
	return 0;
}