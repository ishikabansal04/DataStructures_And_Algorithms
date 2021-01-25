#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    long long tc;
    cin>>tc;
    for(long long t=0;t<tc;t++){
        long long val;
        cin>>val;
        if(val!=1 && val%2!=0){
            cout<<"YES"<<endl;
        }
        else{
            bool flag=false;
    
        for(long long i=2;i*i<=val && i%2!=0; i++){
            if(val%i==0){
                cout<<i<<endl;
                cout<<"YES"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
        }
        
    }
}