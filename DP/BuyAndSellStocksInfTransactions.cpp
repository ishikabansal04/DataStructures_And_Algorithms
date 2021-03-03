#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>stk;
    stk.push(arr[0]);
    int prof=0;
    for(int i=1; i<n; i++){
        if(arr[i]<stk.top()){
            while(stk.size()!=0)
                stk.pop();
        }

        if(stk.size()==0){
            stk.push(arr[i]);
        }
        else{ 
            prof += arr[i]-stk.top();
            // cout<<stk.top()<<"  "<<arr[i]<<"    "<<prof<<endl;
            stk.push(arr[i]);
        }
    }
    cout<<prof<<endl;
}