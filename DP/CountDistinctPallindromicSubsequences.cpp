#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<vector<int>>dp(s.size(), vector<int>(s.size(), 0));
    vector<int>prev(s.size(), -1);
    vector<int>next(s.size(), -1);
    for(int i=0; i<s.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(s[i]== s[j]){
                prev[i] = j;
                break;
            }
        }
    }
    for(int i=s.size()-1; i>=0; i--){
        for(int j=i+1; j<s.size(); j++){
            if(s[i]== s[j]){
                next[i] = j;
                break;
            }
        }
    }

    for(int gap =0; gap<s.size(); gap++){
        for(int i=0, j=gap; j<s.size(); i++, j++){
            if(i==j){
                dp[i][j] = 1;
            }
            else if(gap ==1){
                dp[i][j] = 2;
            }
            else if(s[i] == s[j]){
                int next_ = next[i];
                int prev_ = prev[j];
                if(next_ == prev_){
                    dp[i][j] = 2*dp[i+1][j-1] +1;
                }
                else if(next_ > prev_){
                    dp[i][j] = 2*dp[i+1][j-1] +2;
                }
                else{
                    dp[i][j] = 2*dp[i+1][j-1] - dp[next_ +1][prev_ -1];
                }
            }
            else{
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }
    cout<< dp[0][s.size()-1]<<endl;
}