#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>inp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    int res=inp[0];
    for(int i=1;i<n;i++){
        res=res^inp[i];
    }
    cout<<res<<endl;
}