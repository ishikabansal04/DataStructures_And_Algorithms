#include<iostream>
using namespace std;

int main(){
    int n,i;
    cin>>n>>i;
    int mask= (1<<i);
    mask=mask&n;
    mask= (mask>>i);
    cout<<mask<<endl;
    return 0;
}