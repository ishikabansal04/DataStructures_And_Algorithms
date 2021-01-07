#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<(n&1)<<endl;
    if(n&1){
        cout<<"Odd number"<<endl;
    }
    else{
        cout<<"Even number"<<endl;
    }
    return 0;
}

/* concept used of n&1 means 
let n= 5 
5 = 0101
1 = 0001
& = 0001

if(on anding we get 0 that means last bit is 0 )
and we know if last bit is 0 then number is even else the number is odd.
*/