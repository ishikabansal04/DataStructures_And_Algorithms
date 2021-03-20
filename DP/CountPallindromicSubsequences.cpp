#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;

    string str2="";
    for(int i=0; i<str.length(); i++){
        str2= str[i]+ str2;
    }
    vector<vector<int>>dp(str.length()+1, vector<int>(str.length()+1, 0));
    for(int i=1; i<=str.length(); i++){
        for(int j=1; j<=str.length(); j++){
            if(i==j){
                dp[i][j]=1;
            }
            else if(str[i-1]== str2[j-1]){
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            }
            else{
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }
    cout<<dp[str.length()][str.length()];
    for(int i=0; i<=str.length(); i++){
        for(int j=0; j<=str.length(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}