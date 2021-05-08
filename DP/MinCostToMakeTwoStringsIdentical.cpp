#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int minimumDeleteSum(string s1, string s2, int x, int y) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){
                if(i==0 && j==0){
                    dp[i][j]=0;
                }
                else if(i==0){
                    dp[i][j]= y + dp[0][j-1];
                }
                else if(j==0){
                    dp[i][j]= x + dp[i-1][0];;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + x, dp[i][j-1] + y);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }

    int main(){
    string s1, s2;
    cin>>s1>>s2;
    int x , y;
    cin >> x>> y;
    int res = minimumDeleteSum(s1, s2, x, y);
    cout<< res <<endl;
}