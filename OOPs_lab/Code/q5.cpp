#include<iostream>
using namespace std;

int main(){

    //celsius to fahrenheit
    int till = 100;

    for(int c=0;c<=100;c++) {
        int f = (9/5)*c+32;
        cout<<c<<" c = "<<f<<" f "<<endl;
    }   
}
