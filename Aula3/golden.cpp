#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

float golden(int num);

float golden(int num){
	if(num==0) return 1;
	return 1 +(1/golden(num-1));
}

int main(int argc, char const *argv[])
{
	int j = atoi(argv[1]);
	float i = golden(j);
	printf("%f\n",i );
	printf("%f\n",(1+sqrt(5))/2 );
	return 0;
}
