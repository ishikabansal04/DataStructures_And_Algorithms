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
    int maxprof= INT_MIN;
    for(int i=1; i<n; i++){
        while(stk.size()!=0 && arr[i]<stk.top()){
            stk.pop();
        }
        if(stk.size()==0){
            stk.push(arr[i]);
        }
        else{
            int currprof = arr[i]- stk.top();
            maxprof= max(maxprof, currprof);
        }
    }
    cout<<maxprof<<endl;
}