#include<iostream>
#include<vector>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int s, v;
        cin>>s>>v;
        int sum=0;
        vector<int>arr(s);
        for(int j=0;j<s;j++){
            cin>>arr[j];
            sum+=arr[j];
        }
        if(sum%v==0){
            cout<<"0"<<endl;
        }
        else{
            cout<<"1"<<endl;
        }
    }
    return 0;
}