#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 30


void setup(int m,int n,char *arr,int *ft);

void game(int m,int n,char *arr,int *ft);

void parr(int n,char *arr,int *ft);

int rim(int i,int j,int n, char *arr,int *ft);

int main(int argc,char* argv[]){
	int m=atoi(argv[2]), n=atoi(argv[1]),ft[N][N]={0};
	srand(time(0));
	system("clear");
	if(n>N){
		printf("Error!!! Size(N) too large: %d\n",n);
		return 0;
	}
		if(m>n*n){
		printf("Error!!! Size(M) too large: %d\n",m);
		return 0;
	}
char arr[N][N]={0};
	setup(m,n,arr,ft);
	parr(n,arr,ft);
	game(m,n,arr,ft);
	return 0;
}

void setup(int m,int n,char *arr,int *ft){
	for(int i=1;i<=m;i++){
		char *p=(char*)(arr+(rand()%n)*30+(rand()%n));
		if(*p=='X') i--;
		*p='X';
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tk=48;
//			*(ft+N*i+j)=1;
//			puts("");
			for(int k=i-1;k<=i+1;k++){
				if(k<0||k>=n) continue;
				for(int l=j-1;l<=j+1;l++){
					if(l<0||l>=n) continue;
					char*q=(char*)(arr+k*N+l);
					if(*q=='X') tk++;
					
				}
			}
			char *p=(char*)(arr+N*i+j);
			if(*p=='X') continue;
			if(tk==48) *p=95;
			else *p=tk;
		}
	}
}

void parr(int n,char *arr,int *ft){
	system("clear");
//	printf("   ");
//	for(int i=0;i<n;i++) printf("%2.d ",i);
//	puts("");
	for(int i=0;i<n;i++){
//		printf("%2.d ",i);
		for(int j=0;j<n;j++){
//			if(*(ft+N*i+j)==1)printf(" %c ",*(arr+i*N+j));
//			else printf(" ? ");
				if(*(ft+N*i+j)==1)printf("%c ",*(arr+i*N+j));
			else printf("? ");
	}
		puts("");
	}
	puts("");
}

void game(int m,int n,char *arr,int *ft){
	int tmp,inp[2];
re:	printf("Input :\n");
	for(int i=0;i<2;i++){
		scanf("%d",&tmp);
		if(tmp<0||tmp>=n){
			puts("Error_1: out of range\n");
	       		game(m,n,arr,ft);
		}	
		else	*(inp+i)=tmp;
	}
	int *p=(int *)(ft+N*(*inp)+(*(inp+1)));
	if(*p==1){
		puts("\nERROR_2: Clicked\n");
		goto re;
	}
	switch(rim(*inp,*(inp+1),n,arr,ft)){
		case 0: printf("%d %d\n",*inp,*(inp+1));
			int tk=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					int *o=(int *)(ft+N*i+j);
					if(*o==1) tk++;
				}
			}
			if(tk==(n*n-m)){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++)	*(ft+N*i+j)=1;
				}
				parr(n,arr,ft);
				puts("\nyou WIN!!!");
				return 0;
			}
			parr(n,arr,ft);
			game(m,n,arr,ft);
			break;
		case 1: printf("\nyou are dead!\n");
		return 0;
	}
}

int rim(int i,int j,int n,char *arr,int *ft){
	int *p=(int *)(ft+N*i+j);
	char *q=(char*)(arr+N*i+j);
	if(*q=='X') return 1;
	*p=1;
	if(*q==95){
			for(int k=i-1;k<=i+1;k++){
				if(k<0||k>=n) continue;
				for(int l=j-1;l<=j+1;l++){
					int *o=(int *)(ft+N*k+l);
					if(l<0||l>=n||(k==i&&l==j)||*o) continue;
					rim(k,l,n,arr,ft);
				}
			}
	}
	return 0;

}
