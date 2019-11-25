#include<stdio.h>
#define N 4

int boolf(int* var, int m);
int recbool(int * var, int n);
int cbf(int* var,int m);
int comb(int * var, int n,int k);

int main(){
//	puts("pass");
	int varbool[20];
	recbool(varbool,N);
	puts("");
	comb(varbool,N,3);
//	puts("pass");
}

int boolf(int *var,int m){
	int result=var[0];
	for(int i=1;i<m;i++)	result=(result&&var[i]);
//	printf("bf ");
	return result;
}

int recbool(int *var,int n){
	int lvar[20],j,num=0;
	if(n==0){
		for(int i=0;i<N;i++)
			printf("%d ",var[i]);
		
		printf("%d\n",boolf(var,N));
		return ;
	}
	for(j=0;j<=1;j++){
//		puts("pass");
		var[n-1]=j;
		recbool(var,n-1);
	}
}


int cbf(int *var,int m){
	int result=0;
	for(int i=0;i<m;i++)	result+=var[i];
//	printf("bf ");
	return result;
}

int comb(int *var,int n,int k){
	int lvar[N],j,num=0;
	if(n==0){
		for(int i=0;i<N;i++)	lvar[i]=var[i];
		if(cbf(lvar,N)==k){
//			for(int i=0;i<4;i++) printf("%d",lvar[i]);
			printf("(");
			for(int i=0;i<N;i++){
				if(lvar[i]==1) printf("%d,",(i+1));
				else continue;
			}
			printf("\b)\n");
			num++;
		}
		return ;
	}
	for(j=0;j<=1;j++){
//		puts("pass");
		var[n-1]=j;
		comb(var,n-1,k);
	}
}
