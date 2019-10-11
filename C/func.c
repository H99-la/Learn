#include<stdio.h>

char ch1(int r);
char ch2(int r);
int tier(int r);
int rank(int r);
void result(int r);

int main(){
	unsigned int res;
       	puts("What is your ranking? :");
	scanf("%u",&res);
	result(res);	
}




void result(int r){
	if(r<=100)
		puts("\nCongrate!! Your are the Elite in your class!!");
	else
		puts("Your result is NOT too bad!!");
	printf("\n\nyour result:\n\nTier : %5d\nRank : %3d%c%c\nClass: %5c\n _____END______\n",tier(r),rank(r),ch1(r),ch2(r),'A');
}

int tier(int r){
	int temp;
	if(r%10!=0)
		temp=r/10+1;
	else
	       	temp=r/10;
	return temp;
}

int rank(int r){
	int temp=r%10;
	if((r%10==0)&&(r/10!=0))
		temp+=10;
	return temp;
}

char ch1(int r){
	if(r/10!=1){
		switch(r%10){
			case 1: return('s');
				break;
			case 2: return('n');
				break;
			case 3: return('r');
				break;
			default: return('t');
		}
	}
	else return('t');
	
}

char ch2(int r){
        if(r/10!=1){
                switch(r%10){
                        case 1: return('t');
                                break;
                        case 2:
                        case 3: return('d');
                                break;
                        default: return('h');
                }
	}
        else return('h');
        
}

