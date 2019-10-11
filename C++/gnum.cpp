#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>

using namespace std;

int main(){
srand(static_cast<unsigned int>(time(0)));
int rnum=rand();
int gnum=rnum%100+1;
int gp=0;
int count=0;


cout<<"Welcome to the Beta of \"Gnum Game\"!!\n"<<endl<<"Please Guess the Gnum!- ";
do{
if(gp!=gnum){
cin>>gp;
if(gp>=gnum){
cout<<"Gnum is smaller than "<<gp<<"!\nPlease Try Again!- ";
count++;
}
else if(gp<=gnum){
cout<<"Gnum is larger than "<<gp<<"!\nPlease Try Again!- ";
count++;
}
}
}while(gp!=gnum);
cout<<"\n----Congrate!----\nYour Beat the game!!\n";
cout<<"\nYour Have Tried: "<<count<<" times!!"<<endl;
return 0;
}
