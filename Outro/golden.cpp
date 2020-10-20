#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

float golden(int i){
	if(i==0) return 1;
	return 1+ 1/golden(i-1);
}


int main(){
	printf("%s\n", "That's the golden show");
	printf("%s", "How much detailed you want? " );
	int detailed;
	scanf("%d",&detailed);
	
	printf("\n%f\n", golden(detailed));


	return 0;
}