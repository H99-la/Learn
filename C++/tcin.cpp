#include<iostream>
#include<string>
using namespace std;

void tcin(int a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
cin.clear();
cin.ignore();
}
void tcin(short a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
cin.clear();
cin.ignore();
}
void tcin(char a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
}
void tcin(long a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
cin.clear();
cin.ignore();
}
}
void tcin(float a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
cin.clear();
cin.ignore();
}
void tcin(bool a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
cin.clear();
cin.ignore();
}
void tcin(string a){
for(;!(cin>>a);){
cin.clear();
cin.ignore();
cout<<"try again!\n";
}
cin.clear();
cin.ignore();
}
int main(){
int i, test,tempt;
bool bl;
char ch;
string str;
float fl;
long l;
short sh;

cout<<"Welcome to the tcin test!!\n\nTest avaiable:\n1.int\n2.bool\n3.char\n4.string\n5.float\n6.long\n7.short\nTest:";
cin>>test;
switch(test){
case 1 :tcin(i);
	cout<<i;
	break;
case 2 :tcin(bl);
	cout<<bl;
	break;
case 3 :tcin(ch);
	cout<<ch;
	break;
case 4 :tcin(str);
	cout<<str;
	break;
case 5 :tcin(fl);
	cout<<fl;
	break;
case 6 :tcin(l);
	cout<<l;
	break;
case 7 :tcin(sh);
	cout<<sh;
	break;
default :cout<<"\nend";

}

cout<<"end";
return 0;
}
