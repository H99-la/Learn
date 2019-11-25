#include<stdio.h>
#include<stdlib.h>

typedef unsigned char byte;

void ip2b(byte*);
void b2ip(char*);
int main(){
	byte ip[4]={129,160,96,1};
//	puts("please input a IP address :(X.X.X.X)");
//	scanf("%hhu.%hhu.%hhu.%hhu",&ip[0],&ip[1],&ip[2],&ip[3]);	
	printf("IP=%hhu.%hhu.%hhu.%hhu\n",ip[0],ip[1],ip[2],ip[3]);
	ip2b(ip);
//b
	char bit32[32]={1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1};
//	puts("input a 32 bit ip address:");
//	scanf("%s",bit32);
	printf("32-bit:\t");
	for(int i=0;i<32;i++) printf("%d",bit32[i]);
	puts("");
	b2ip(bit32);

	return 0;
}

void ip2b(byte* ip){
	
	for(int i=0;i<4;i++){
		for(int n=7;n>=0;n--) printf("%d",((*(ip+i)>>n)%2==1?1:0));
	}
	puts("");
}

void b2ip(char* bit32){
	unsigned int ip32[4]={0};
	for(int i=0;i<32;i++){
		if(i<8){
			ip32[0]<<=1;
			ip32[0]+=(*(bit32+i)?1:0);
		}
		else	if(i<16){
				ip32[1]<<=1;
				ip32[1]+=(*(bit32+i)?1:0);
			}	
		else	if(i<24){
				ip32[2]<<=1;
				ip32[2]+=(*(bit32+i)?1:0);
			}
		else{
			ip32[3]<<=1;
			ip32[3]+=(*(bit32+i)?1:0);
		}

	}
	printf("IP=%u.%u.%u.%u\n",ip32[0],ip32[1],ip32[2],ip32[3]);
}
