#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    string str;
    cin >> str;
    vector<vector<int>>dp(str.length()+1, vector<int>(str.length()+1, 0));
    for(int i=1; i<=str.length(); i++){
        for(int j=1; j<=str.length(); j++){
            if(str[i-1] == str[j-1]){
                if(i == j){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[str.length()][str.length()] << endl;
    return 0;
}
