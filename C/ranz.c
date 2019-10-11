#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void scallout(int x);
void callout();
void ques();
void fin();

int main(){
	puts("Welcome!");
	ques();
}

void ques(){
		int c;
		int s;
                printf("What do you want to try ?:(1. Rand()  2. Srand()  3. End)\n\n");
                scanf("%d",&c);
                switch(c){
			case 1 : callout();
				 break;
			case 2 : puts("Please Give A seed!");
				 scanf("%d",&s);
				 scallout(s);
				 break;
			case 3 : fin();
				 break;
			default: puts("Error!Please Try again!:");
				 ques();
				 break;
		}

}

void scallout(int x){
	srand(x);
	int temp= rand()%10+1;
	printf("seed : %d\nNum : %d\n\n",x,temp);
	ques();
}

void callout(){
	srand(time(NULL));
	int temp=rand()%10+1;
	printf("Num : %d\n\n",temp);
	ques();
}

void fin(){
	puts("End\n");
}

