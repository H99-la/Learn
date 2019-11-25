#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 65535

typedef unsigned short uns;

void comp(uns* I,uns *R,uns v);
void rearr(uns *I);
void recons(uns * T);
int main(){
//part a
	uns I[4][2]={0};
	srand(time(NULL));
	for(int i=0;i<4;i++){
		I[i][0]=rand()%200;
		I[i][1]=rand()%200;
	}
	rearr(I);
	uns v=rand()%185;
	uns R[4][2]={0};
	printf("I={ ");
	for(int i=0;i<4;i++){
		printf("[%u,%u],",I[i][0],I[i][1]);
	}
	printf("\b }\nv=%hu\n",v);
	comp(I,R,v);
	printf("R={ ");
	for(int i=0;i<4;i++){
		if(R[i][0]!=0&&R[i][1]!=0)	printf("[%u,%u],",R[i][0],R[i][1]);
	}
		printf("\b }\n\n\n");
//part b
	uns T[8]={0};
	for(int i=0;i<4;i++){
		if(I[i][0]!=0)	T[i*2]=I[i][0]-1;
		T[i*2+1]=I[i][1];
	}
	recons(T);
	printf("T={ ");
	for(int i=0;i<8;i++){
		if(T[i]==MAX) continue;
		printf("%u,",T[i]);
	}
	printf("\b }\n");
	return 0;
}

void comp(uns* I,uns* R,uns v){
	for(int i=0,j=0;i<4;i++){
		if(v>=*(I+2*i)&&v<=*(I+2*i+1)){
		       	*(R+2*j)=*(I+2*i);
		       	*(R+2*j+1)=*(I+2*i+1);
			j++;
		}
	}

}

void rearr(uns *I){
 	uns temp;
	for(int i=0;i<4;i++){
		temp=*(I+2*i);
		if(*(I+2*i)>*(I+2*i+1)){		
			*(I+2*i)=*(I+2*i+1);
			*(I+2*i+1)=temp;
			
		}
	}
}

void recons(uns* T){
//comparing same number
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j==i) continue;
			if(*(T+i)==*(T+j)) *(T+j)=MAX;
		}
	}
// rearrange 
	for(int i=0;i<=8;i++){
		for(int j=0;j<7;j++){
			uns tmp=*(T+j);
			if(*(T+j)>=*(T+j+1)){	
				*(T+j)=*(T+j+1);
				*(T+j+1)=tmp;
			}	
		}
	}

}
