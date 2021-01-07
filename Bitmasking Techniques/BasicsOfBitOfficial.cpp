#include<iostream>
using namespace std;

int main(){
    int n,i,j,k,m,on;
    cin>>n>>i>>j>>k>>m;
    on=n;

    //setting ith bit
    int m1= (1<<i);
    n=n|m1;
    cout<<n<<endl;
    n=on;

    //unsetting jth bit
    int m2= ~(1<<j);
    n=n&m2;
    cout<<n<<endl;
    n=on;

    //toggling kth bit
    int m3= (1<<k);
    n=n^m3;
    cout<<n<<endl;
    n=on;

    //checking if mth bit is on or off
    int m4= (1<<m);
    n=n&m4;
    if(n){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    n=on;
    return 0;
}