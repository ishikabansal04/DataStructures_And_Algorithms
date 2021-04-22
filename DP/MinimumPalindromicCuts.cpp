#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){

    string str;
    cin>>str;
    int n= str.length();
    vector<vector<bool>>isPalin(n, vector<bool>(n, false));
    for(int gap = 0; gap<n; gap++){
        for(int i=0, j=gap; j<n; i++, j++){
            if(gap==0){
                isPalin[i][j] = true;
            }
            else if(gap == 1){
                isPalin[i][j] = str[i] == str[j] ? true: false;
            }
            else{
                if(str[i] == str[j]){
                    isPalin[i][j] = isPalin[i+1][j-1];
                }
            }
        }
    }

    vector<int>dp(n, INT_MAX);
    dp[0]=0;
    for(int j=1; j<n; j++){
        for(int i=j; i>=0; i--){
            if(isPalin[i][j]){
                if(i-1>=0)
                    dp[j] =  min(dp[j], dp[i-1]+1);
                else
                    dp[j] =  min(dp[i], 1);
            }
            else{
                continue;
            }
        }
    }
    cout<<dp[n-1]<<endl;
}