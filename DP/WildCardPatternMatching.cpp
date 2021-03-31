#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1 >> str2;
    vector<vector<bool>>dp(str2.size()+1, vector<bool>(str1.size()+1, false));
    dp[str2.size()][str1.size()] = true;
    for(int i=str2.size()-1;i>=0; i--){
        if(str2[i] == '?'){
            dp[i][str1.size()] =false;
        }

        else if(str2[i] == '*'){
            dp[i][str1.size()] =dp[i+1][str1.size()] ;
        }
        else{
            dp[i][str1.size()] = false;
        }
    }
    for(int i=str2.size()-1; i>=0; i--){
        for(int j=str1.size()-1; j>=0; j--){
            if(str2[i]== '?'){
                dp[i][j]= dp[i+1][j+1];
            }
            else if(str2[i]=='*'){
                for(int k=j; k<=str1.size(); k++){
                    if(dp[i+1][k]){
                        dp[i][j] = true;
                        break;
                    }
                }
            }
            else{
                if(str1[j] == str2[i]){
                    dp[i][j]= dp[i+1][j+1];
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
    }
    cout << boolalpha << dp[0][0] <<endl;
}