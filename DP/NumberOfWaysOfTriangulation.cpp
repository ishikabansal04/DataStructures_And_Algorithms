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
    cin >> n;
    vector<int>dp(n+1, 0);
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for(int i=5; i<=n; i++){
        dp[i] = i* dp[i-3];
    }
    cout << dp[n] << endl;
}