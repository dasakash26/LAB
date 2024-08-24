#include<iostream>
#define ll long long
using namespace std;

ll factorial(const ll n){
    if(n==0||n==1) return 1;
    return n*factorial(n-1);
}

int main(){
    ll n;
    cout<<"Enter the number to calculate factorial: ";
    cin>>n;
    cout<<n<<"! = "<<factorial(n)<<endl;
}