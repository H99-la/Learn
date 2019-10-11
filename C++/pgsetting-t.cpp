#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main(){
string name;
int test;
char gs;
char tempc;

cout<<"Welcome to the testing room!!"<<endl;
cout<<"please let me knowing you! :";
getline(cin,name);

cout<<"Welcome again, "<<name<<"!\n";
cout<<"Please choose your test!: ";
cin>>test;
cin.clear();
cin.ignore(100,'\n');

switch(test){

case 1:
cout<<"test_"<<test<<endl;
cout<<"Do you want to know the rules?(Y/N)-";
cin>>tempc;
cin.ignore();
if(tempc=='y')
cout<<"rules!\n";
else if(tempc=='n')
cout<<"Goodbye!!\n";
else cout<<"Error!";
break;

case 2:
cout<<"press ENTER to start the game!";
if(cin.get()=='\n')
cout<<"game start!\n";
else cout<<"OK";
break;

default :
cout<<"Goodbye,"<<name<<" !\n";
}
return 0;
}
