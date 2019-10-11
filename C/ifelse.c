#include<stdio.h>

int main(){
	char ans;
	printf("Welcome! Do you want to quit(Y/N):");
	scanf("%c",&ans);
	if(ans=='y')
		printf("Okay!\n\n Goodbye!\n");
	else if(ans=='n')
		printf("I don't care!\n\n Goodbye!\n");
	else printf("Error!!\n\n Goodbye\n!");
}
