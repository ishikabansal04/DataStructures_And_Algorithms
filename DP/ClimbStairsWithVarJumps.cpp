#include <iostream>
#include <vector>
using namespace std;

int cs(vector<int>arr, int n){
    // write your code here
  
    vector<int>dp(n+1, 0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=arr[i];j++){
            if(i+j <=n){
                dp[i+j]+=dp[i];
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}