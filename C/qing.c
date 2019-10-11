#include<stdio.h>

int main(){
	int i,k;
	printf("Please Key in a Integer:");
	scanf("%d",&i);
	for(k=2;k<i;k++){
		if(i%k==0) break;
	}
	printf("Is It a prime Number:");
	if(i==k) printf("yes\n");
	else printf("no\n");
}
