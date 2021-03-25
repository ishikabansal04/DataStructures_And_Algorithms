#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, 0));
    int n= s.length();
    int max_=0;
    for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(i==j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    dp[i][j] =dp[i+1][j-1] +2 ;
                }
                else{
                    dp[i][j]=0;
                }
                max_= max(max_, dp[i][j]);
            }
        }
   
    cout<<max_;
}