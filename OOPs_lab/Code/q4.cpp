#include<iostream>
using namespace std;

int main(){
    for(int i =1; i<=10;i++){
        //this curly braces are the scope of i
        cout<<i<<endl;
    }
    //out of scope
    //cout<<i<<endl;
}
