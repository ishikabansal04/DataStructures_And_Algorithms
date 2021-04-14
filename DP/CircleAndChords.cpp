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
    cin>>n;
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i]+= dp[j]* dp[i-j-1];
        }
    }
    cout<<dp[n]<<endl;
}