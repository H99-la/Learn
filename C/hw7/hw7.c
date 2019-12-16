#include<stdio.h>
#include<stdlib.h>
void f2bs();
void d2bs();
void d2bu();
void f2bu();
void b2f();
void b2d();


int main(int argc, char* argv[]){
	//check case;
	struct {
		int cs;
		char* d1;
		char* d2;
		char* d3;
	} inps={atoi(argv[1]),argv[2],argv[3],argv[4]};
	
	struct {
		int cs;
		union{	float f1;
			int i1;
		} fi1;
		union{	double db1;
			long l1;	
		} dl1;
		char* d1;
		char* d2;
		char* d3;
	} inpu={atoi(argv[1]),atof(argv[2]),atof(argv[2]),argv[2],argv[3],argv[4]};

	
	switch(inps.cs){
		case 1:	//ftob;
			printf("STRUCT : ");
			f2bs(inps.d1);
			printf("UNION  : ");
			f2bu(inpu.fi1.i1);
			break;
		case 2:	//dtob;
			printf("STRUCT : ");
			d2bs(inps.d1);
			printf("UNION  : ");
			d2bu(inpu.dl1.l1);
			break;
		case 3:	//btof;
			printf("STRUCT : ");
			b2f(inps.d1,inps.d2,inps.d3);
			printf("UNION  : ");
			b2f(inpu.d1,inpu.d2,inpu.d3);
			break;
		case 4:	//btod
			printf("STRUCT : ");
			b2d(inps.d1,inps.d2,inps.d3);
			printf("UNION  : ");
			b2d(inpu.d1,inpu.d2,inpu.d3);
			break;
		default:
			puts("error");
			break;
	}
	return 0;
}

void f2bs(char* in){
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
void d2bs(char* in){
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


void f2bu(int out){
	printf("%d",(out>>31)%2==1?1:0);
	printf(" ");
	for(int i=2;i<=9;i++)
		printf("%d",(out>>(32-i))%2==1?1:0);
	printf(" ");
	for(int i=10;i<=32;i++)
		printf("%d",(out>>(32-i))%2==1?1:0);
	printf("\n");
}
void d2bu(long out){
	printf("%d",(out>>(63))%2==1?1:0);
	printf(" ");
	for(int i=2;i<=12;i++)
		printf("%d",(out>>(64-i))%2==1?1:0);
	printf(" ");
	for(int i=13;i<=64;i++)
		printf("%d",(out>>(64-i))%2==1?1:0);
	printf("\n");
}
