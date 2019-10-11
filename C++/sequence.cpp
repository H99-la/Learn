#include<iostream>
#include<ctime>
using namespace std;

int main(){
	int seq;
	srand(time(0));
	
	for(int c=1;c<=150;c++){
	seq=rand()%4;
	switch(seq){
		case 0 : cout<<"A";
			 break;
		case 1 : cout<<"G";
			 break;
		case 2 : cout<<"C";
                         break;
		case 3 : cout<<"T";
                         break;
		default: cout<<"E";
		}
	cout<<endl<<c<<endl;
	}
}
