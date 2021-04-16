#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>dp(n+1, 0);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = arr[i-1];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }
    cout<<dp[n]<<endl;
}