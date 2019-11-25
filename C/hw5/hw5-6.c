#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dtm(int f[][10],int x);

int main(){
	int f[10][10]={0};
	srand(time(0));
//	puts("start!");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){ f[i][j]=(rand()%5+1);}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){ printf("%3.d",f[i][j]);}
		puts("");
	}
	puts("");
	printf("determinant=%3.d\n",dtm(f,10));
	return 0;
}

int dtm(int f[][10],int x){
	int pr=1,c[10],d=0,b[10][10],j,p,q,t;
	if(x==2) return (f[0][0]*f[1][1]-f[0][1]*f[1][0]);
	for(j=0;j<=x;j++){
		int r=0,s=0;
		for(p=0;p<=x;p++){
			for(q=0;q<=x;q++){
				if(p!=0&&q!=j){
					b[r][s]=f[p][q];
					s++;
					if(s>x-1){r++;s=0;}
				}
			}
		}	
		pr=(j%2?-1:1);
		c[j]=pr*dtm(b,x-1);
	}
	for(j=0,d=0;j<x;j++) d+=(f[0][j]*c[j]);
	return d;
}
