#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>input(n, vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>input[i][j];
        }
    }
    vector<vector<int>>dp(3, vector<int>(n));
    for(int i=0;i<3;i++){
        dp[i][0]= input[0][i];
    }
    for(int i=1; i<n; i++){
        dp[0][i] = min(dp[1][i-1], dp[2][i-1])+ input[i][0];
        dp[1][i] = min(dp[0][i-1], dp[2][i-1])+ input[i][1];
        dp[2][i] = min(dp[0][i-1], dp[1][i-1])+ input[i][2];
    }
    cout<< min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]));
}