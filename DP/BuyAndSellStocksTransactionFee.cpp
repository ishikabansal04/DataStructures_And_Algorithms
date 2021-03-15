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
    int fee;
    cin>>fee;
    int prof=0;
    vector<vector<int>>dp(2, vector<int>(n));
    dp[0][0]= 0-arr[0];
    dp[1][0]= 0;
    for(int i=1; i<n;i++){
        dp[0][i]=  max(dp[0][i-1], dp[1][i-1]-arr[i]);       //buy
        dp[1][i]=  max(dp[0][i-1]+arr[i]-fee, dp[1][i-1]);   //sell
    }
    prof= dp[1][n-1];
    cout<<prof<<endl;
}