#include<stdlib.h>
#include<stdio.h>

int f(int);
int main(){
	int a;
	scanf("%d",&a);
	printf("%d\n",f(a));
	return 0;
}

int f(int c){
	int f0=0,f1=1,f2=2,ff=0;
	switch(c){
		case 0: return f0;
			break;
		case 1: return f1;
			break;
		case 2: return f2;
			break;
		default : 
			for(int i=3;i<=c;i++){
				ff=f2+f1+f0;
				f0=f1;
				f1=f2;
				f2=ff;			
			}
			break;
	}
	return ff;
}
