#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>stk;
    for(int i=0;i<n;i++){
        while(stk.size()!=0 && arr[stk.top()]<arr[i]){
            stk.pop();
        }
        if(stk.size()==0){
            ans[i]=i+1;
        }
        else if(arr[stk.top()]>arr[i]){
            ans[i]=i-stk.top();
        }
        stk.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}