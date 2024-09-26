#include<iostream>
using namespace std;

int main(){
    long long n;
    long long fact = 1;
    cout<<"Enter the length of factorial table : ";
    cin>>n;

    for(int i = 1; i<=n; i++){
        cout<<i<<"! = "<<fact<<endl;
        fact*i;
    }
}
