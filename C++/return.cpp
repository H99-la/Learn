#include <iostream>
#include <string>
using namespace std;

int main(){

string str;
cin.clear();
cin.ignore();
getline(cin,str);
if(str=="\n")
cout<<"test success!";
else cout<<"fail!";
return 0;
}
