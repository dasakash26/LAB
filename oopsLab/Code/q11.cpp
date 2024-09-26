#include<iostream>
using namespace std;

void strcpy(string *a,string *b){
     *b = *a;
}

int main(){
    string a = "akash das the great";
    string b;
    
    strcpy(&a,&b);
    cout<<b<<endl;
}