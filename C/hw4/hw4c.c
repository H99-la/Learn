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
			b2f(argv[2],argv[3],argv[4]);
			break;
		case 4:	//btod
			b2d(argv[2],argv[3],argv[4]);
			break;
		default:
			puts("error");
			break;
	}
	return 0;
}

void f2b(char* in){
	float f=atof(in);
	int *out=&f;
	printf("%d",(*out>>31)%2==1?1:0);
	printf(" ");
	for(int i=2;i<=9;i++)
		printf("%d",(*out>>(32-i))%2==1?1:0);
	printf(" ");
	for(int i=10;i<=32;i++)
		printf("%d",(*out>>(32-i))%2==1?1:0);
	printf("\n");
}
void d2b(char* in){
	double d=atof(in);
	long *out=&d;
	printf("%d",(*out>>63)%2==1?1:0);
	printf(" ");
	for(int i=2;i<=12;i++)
		printf("%d",(*out>>(64-i))%2==1?1:0);
	printf(" ");
	for(int i=13;i<=64;i++)
		printf("%d",(*out>>(64-i))%2==1?1:0);
	printf("\n");
}

void b2f(char* in1,char* in2,char* in3){
	int bch=0;
	float *f= &bch;
	if(*in1=='1')
	       	bch++;
	for(int i=0;i<=7;i++){	
		bch<<=1;
		if(*(in2+i)=='1')
		       	bch+=1;
	}
	for(int i=0;i<=22;i++){	
		bch<<=1;
		if(*(in3+i)=='1')
		       	bch+=1;
	}
	printf("%.16f\n",*f);
}

void b2d(char* in1,char* in2,char* in3){
	long bch=0;
	double* d =&bch;
	if(*in1=='1')
	       	bch+=1;
	for(int i=0;i<=10;i++){	
		bch<<=1;
		if(*(in2+i)=='1')
		       	bch+=1;
	}
	for(int i=0;i<=51;i++){	
		bch<<=1;
		if(*(in3+i)=='1')
		       	bch+=1;
	}
	printf("%.16lf\n",*d);
}
