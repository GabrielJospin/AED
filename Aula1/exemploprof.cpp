#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int verificaOrdem(int* V, int N) {
    if(N>2) return 0;
    bool aumenta = false;
    bool diminui = false;
    int i;
    for(i=0;i<N-1;i++){
        if(V[i]>V[i+1]) diminui=true;
        if(V[i] < V[i+1])aumenta=true;
        if(aumenta && diminui)return(99);
    }
    if(aumenta) return 1;
    if(diminui) return -1;
    return 0;
}


int main() {


    int cres[] = { 1,2,3,4,5,6,8,9,10,10,20 };
    int decres[] = { 1, 9,60 , 50, 40 , 40, 30, 10, 10, 10, 15 ,20 };
    int same[] = { 1, 1 , 1, 1, 1, 1, 1, 1 , 1 , 1 , 1 };
    int chaos[] = { 1, 2 ,3, 2, 1, 4, 5, 9, 0, 10, 11 };
    int zero[] = {};

    if (verificaOrdem(cres, 11) == 1) printf("Certo para primeiro \n");
    if (verificaOrdem(decres, 12) == -1)printf("Certo para segundo \n");
    if (verificaOrdem(same, 11) == 0) printf("Certo para terceiro \n");
    if (verificaOrdem(chaos, 11) == 99) printf("certo para quarto\n");
    if (verificaOrdem(zero, 0) == 0) printf("certo para quinto\n");

    return 0;

}



