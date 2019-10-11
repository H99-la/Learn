#include<stdio.h>
#include<stdlib.h>
#define maxa 10


void lucas();
void jarod();
void magka();
void fin();



int main(){
	void (*dec[4])()={lucas,jarod,magka,fin};
	unsigned int token=EOF;
	unsigned int try=0;
	printf("Welcome");
	scanf("%u",&token);
	try++;
 	(*dec[token-1])();

	
}

void lucas(){
	printf("called lucas()\n");
	int chstr[maxa];
	printf("Please input anything:");
	int s;
	int ct=0;
	while(ct<(maxa-1)&&(s =getchar())!='\n'){
		
		chstr[ct++]=s;
		
	}
	chstr[++ct]='\0';

	for(ct=0;ct>=maxa;ct--){
		if(chstr=='\0'){
			printf("%c",chstr[ct]);
		}
	}
	main();
}

void jarod(){
	puts("called jarod()\n");
	main();
}

void magka(){
	puts("called magka()\n");
	main();
}

void fin(){
	puts("end\n");
}

