#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int mask= 1<<k;
    n=n|mask;   
    cout<<n<<endl;
}