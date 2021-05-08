#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){
                if(i==0 && j==0){
                    dp[i][j]=0;
                }
                else if(i==0){
                    dp[i][j]=s2[j-1] + dp[0][j-1];
                }
                else if(j==0){
                    dp[i][j]=s1[i-1] + dp[i-1][0];;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }

    int main(){
    string s1, s2;
    cin>>s1>>s2;
    int res = minimumDeleteSum(s1, s2);
    
   
    cout<< res <<endl;
}