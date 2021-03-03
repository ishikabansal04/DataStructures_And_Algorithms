#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

int main(){
    int f, c;
    cin>>f>>c;
    vector<vector<int>>dp(2, vector<int>(f));
    dp[0][0]= 0; // last 2 same
    dp[1][0]= c; // last 2 different
    for(int i=1; i<f; i++){
        dp[0][i]= dp[1][i-1];
        dp[1][i]= (dp[0][i-1] + dp[1][i-1])*(c-1);
    }

    for(int i=0;i<2; i++){
        for(int j=0; j<f; j++){
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<dp[0][f-1] + dp[1][f-1]<<endl;
}