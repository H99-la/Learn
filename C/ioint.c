#include<stdio.h>

int main(){
	int a=10;
	int b;
	printf("The first integer is: %d\nDo you wanb to change it?And key in another Interger?(y\\n)\n",a);
	char ans;
	scanf("%c",&ans);
	switch(ans){
		case 'y' : scanf("%d%d",&a,&b);
			   break;
		case 'n' : scanf("%d",&b);
			   break;
		default  : b=10;
			   break;
	}
	printf("The sum is: %d\n",a+b);
}
