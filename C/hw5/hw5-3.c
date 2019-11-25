#include<stdio.h>
#include<stdlib.h>
#define N 16
void sh3(int * tree,int n);
void i_mirror(int * tree, int * im3,int n);
void r_mirror(int * tree, int * im3, int n);

int main(){
	int tree[16]={0};
	tree[0]=15;
	for(int n=1;n<16;n++)	tree[n]=n;	//init tree;

	int im3[16]={0};
	im3[0]=15;
	int m=N,count=0;
	while(m){
		m>>=1;
		count++;
	}
	count--;
	sh3(tree,count);
	puts("mirror: iterative");
	i_mirror(tree,im3,count);
	sh3(im3,count);

	for(int i=0;i<N;i++) im3[i]=0;
	puts("mirror: recursive");
	r_mirror(tree,im3,count);
	sh3(im3,count);

	return 0;
}

void sh3(int * tree, int n){
	int k=1;
	for(int i=0;i<n;i++){

		int ct=1;
		for(int j=1;j<=(ct<<i);j++){
			printf("%3.d",tree[k++]);
		}
		puts("\n");
	}

}

void i_mirror(int *tree, int * im3,int n){
	for(int i=0;i<n;i++){
		int ct=1;
		for(int j=1;j<=(ct<<i);j++)	im3[(ct<<(i))+j-1]=tree[(ct<<i+1)-j];
	}		
}

void r_mirror(int *tree,int*im3,int n){
//	printf("%d\n",n);
	if(n==0) return;
	int ct=1;
	for(int j=1;j<=(ct<<n-1);j++)	im3[(ct<<(n-1))+j-1]=tree[(ct<<n)-j];
	r_mirror(tree,im3,--n);
}
