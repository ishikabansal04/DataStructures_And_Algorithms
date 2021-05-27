#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int eggs, floors;
    cin >> eggs >> floors;
    vector<vector<int>>dp(eggs + 1, vector<int>(floors + 1, 0));
    for(int i = 1; i<=eggs; i++){
        for(int j = 1; j<= floors; j++){
            if(i == 1){
                dp[i][j] = j;
            }
            else if(j == 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = INT_MAX;
                for(int l=j-1, r=0; l>=0; l--, r++){
                    dp[i][j] = min(dp[i][j], max(dp[i-1][l], dp[i][r]));
                }
                dp[i][j] +=1;
            }
        }
    }
    cout << dp[eggs][floors];
}