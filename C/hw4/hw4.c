#include<stdio.h>
#include<stdlib.h>
void f2b();
void d2b();
void b2f();
void b2d();

int main(int argc, char* argv[]){
	//chech case;
	switch(atoi(argv[1])){
		case 1:	//ftob;
			f2b(argv[2]);
			break;
		case 2:	//dtob;
			d2b(argv[2]);
			break;
		case 3:	//btof;
//			b2f(argv[2],argv[3],argv[4],argv[5]);
			break;
		case 4:	//btod
//			b2d(argv[2],argv[3],argv[4],argv[5]);
			break;
		default:
			puts("error");
			break;
	}
	return 0;
}

void f2b(char* raw){
	int out[32]={0};
	long fi=(long) atof(raw);
	float ff=atof(raw)-fi;
	printf("%ld\t%.20f\n",fi,ff);
	if(fi<0){	//sign;
	       	*out=1;	
//make fi,ff positive;
		fi*=-1;
		ff*=-1;
	}

//crying part of the game 1
	int tmp[24]={0},n=0,tmpi[48]={0},expo=127;
//fi:
	if(fi){	//inreverse fi bit;
		while(fi){
			tmpi[n]=fi%2;
			fi/=2;
			n++;
		}
		expo+=(n-1);
	}	
		
	for(int i=n;i>=0;i--)	//reversed fi bit;
		tmp[n-i]=tmpi[i];

//ff:	
	for(;n<=47;n++){
		ff*=2;
		if(ff>=1) {
			tmp[n]=1;
			ff-=1;
		}
	}
	if(expo==127){
		for(int i=0;tmp[i]!=1){}
	}



// printout ;
	printf("%d ",*out);
	for(int i=1;i<9;i++)
		printf("%d",*(out+i));
	printf(" ");
	for(int i=9;i<32;i++)
		printf("%d",*(out+i));
	printf("\n");

}

void d2b(char* raw){
	int out[64]={0};
	long di=(long) atof(raw);
	double df=atof(raw)-di;
	printf("%ld\t%.20lf\n",di,df);

// printout ;
	printf("%d ",*out);
	for(int i=1;i<12;i++)
		printf("%d",*(out+i));
	printf(" ");
	for(int i=12;i<64;i++)
		printf("%d",*(out+i));
	printf("\n");


}
