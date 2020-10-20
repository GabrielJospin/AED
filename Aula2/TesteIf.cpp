#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
	for(int i = -10; i<=10; i++){
		printf("%d eh %d \n", i&&i-1, i);
	}
	return 0;
}