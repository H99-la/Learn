#include<stdio.h>

int main(){
	int ct=0;
	int temp;
	int token;
	char ch1;
	char ch2;
	unsigned int* tval;
	

	puts("Welcome! How many token do you have?:");
	scanf("%d",&token);
	for(;token>0;token--,ct++){
		temp=ct+1;
		if((temp/10)!=1){
			temp=ct+1;
			switch(temp%10){
				case 1: ch1='s';
					ch2='t';
					break;
				case 2: ch1='n';
					ch2='d';	
					break;
				case 3: ch1='r';
					ch2='d';
					break;
				default: ch1='t';
					 ch2='h';
					 break;
			}
		}
		else{
			ch1='t';
			ch2='h';
		}
		temp=ct+1;
		printf("What is the %d%c%c token's Value?\n",temp,ch1,ch2);
		scanf("%u",tval+temp);

	}
	printf("The count is: %d\n",ct);
	for(temp=1;ct>0;ct--,temp++){
		printf("%-d\t%u\n",temp,*(tval+temp));
	}
	
}
