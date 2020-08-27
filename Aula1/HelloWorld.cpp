#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int verificaOrdem(int* v, int N) {
    int up = 0;
    int down = 0;

    if (N == 0) {
        return 0;
    }
    int i = 0;

    for (i = 0; i < (N - 1); i++) {
        if (v[i] < v[i + 1]) up++;
        if (v[i] > v[i + 1]) down++;
    }

    if (up == 0 && down == 0) {
        return 0;
    }
    else if (up == 0) {
        return -1;
    }
    else if (down == 0) {
        return 1;
    }
    else {
        return 99;
    }

}


int main() {

    int cres[] = { 1,2,3,4,5,6,8,9,10,10,20 };
    int decres[] = { 100, 90,60 , 50, 40 , 40, 30, 10, 10, 10, 5 ,10 };
    int same[] = { 1, 1 , 1, 1, 1, 1, 1, 1 , 1 , 1 , 1 };
    int chaos[] = { 1, 2 ,3, 2, 1, 4, 5, 9, 0, 10, 11 };
    int zero[] = {};

    if (verificaOrdem(cres, 11) == 1) printf("Certo para crescente \n");
    if (verificaOrdem(decres, 12) == -1)printf("Certo para decrescente \n");
    if (verificaOrdem(same, 11) == 0) printf("Certo para Constatne \n");
    if (verificaOrdem(chaos, 11) == 99) printf("certo para chaos\n");
    if (verificaOrdem(zero, 0) == 0) printf("certo para nulo\n");

    return 0;

}

