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
	if(c<=3) return c;
	return f(c-1)+f(c-2)+f(c-3);
}
