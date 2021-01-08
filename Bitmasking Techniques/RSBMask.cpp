#include<iostream>
#include<bitset>
#include<string>
using namespace std;


string ToBinary(int num){
    if(num==0){
        return "";
    }
    string res ="";
    res= ToBinary(num/2);
    res=res+to_string(num%2);
    return res;
}

int main(){
    int n;
    cin>>n;
    int nc = -n;
    // nc=nc+1;
    // cout<<(n&nc)<<endl;
    int res= n&nc;
    cout<<ToBinary(res);
}