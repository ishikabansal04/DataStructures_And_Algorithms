#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count =0;
    int n = s.size();
    vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(i==j){
                    dp[i][j]= true;
                }
                else if(s[i]==s[j] && gap==1){
                    dp[i][j] = true;
                }
                else if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(dp[i][j]){
                    count++;
                }
            }
        }
        cout<< count;
}