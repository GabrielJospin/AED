#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

#define TIME 300
void better(int num){
	int i = 0;
	while(i<num){
		printf("Better\n");
		Sleep(TIME);
		i++;
	}
	printf("Waaaaa\n");
	Sleep(TIME);
}

void na(int i, int num){
	int j = 0;
	while(j<num){
		printf("%s", "Na " );
		Sleep(TIME);
		j++;
	}
	printf("%s\n", "");
}

void na(int i){
	while(true){
		printf("%s", "Na " );
		Sleep(TIME);
	}
}

void thenYou (int i){
	Sleep(TIME);
	if(i%2==0) printf("%s\n%s\n", "then you can start","to make it better"); 
	if(i%2==1) printf("%s\n%s\n", "then you bgin","to make it better");
	Sleep(TIME);
	better(5);
	Sleep(TIME);
	if(i==5)na(i);
	else na(i,10);
	Sleep(TIME);
}

void remember(int i){
	Sleep(TIME);
	if(i%2==0) printf("%s\n%s\n", "Remember","Let her into your heart");
	if(i%2==1) printf("%s\n%s\n", "Remember","Let her under your skin");
	Sleep(TIME);
	thenYou(i);
}

void dont(int i){
	Sleep(TIME);
	if(i%3==0) printf("%s\n%s\n", "Dont make it bad","Take a sad song and make it better");
	if(i%3==1) printf("%s\n%s\n", "Dont be afraid","You were made to go out and get her");
	if(i%3==2) printf("%s\n%s\n", "Dont let me down","You have found her, now you go and get her");
	Sleep(TIME);
	remember(i);
}

void heyJude(int i){
	printf("%s \n", "Hey Jude" );
	Sleep(TIME);
	dont(i);	
}


int main(){
	printf("%s\n\n","HEY JUDE" );
	Sleep(TIME);
	for (int i = 0; i < 6; ++i)
	{
		heyJude(i);
		Sleep(TIME);
	}
	return 0;
}