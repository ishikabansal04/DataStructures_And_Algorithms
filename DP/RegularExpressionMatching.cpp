#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    vector<vector<bool>>dp(str2.size()+1, vector<bool>(str1.size()+1, false));
    int n1= str1.size(), n2= str2.size();
    dp[0][0] =true;
    for(int i=0; i<=n2; i++){
        for(int j=0; j<=n1; j++){
            if(i==0){
                // cout<< boolalpha <<dp[i][j]<<"      ";
                continue;
            } 
            else if(j==0){
                dp[i][j] = str2[i-1] == '*' ? dp[i-2][j] : false;
            }
            else{
                if(str2[i-1] == '*'){
                    dp[i][j] = dp[i-2][j];
                    if(str2[i-2] == str1[j-1] || str2[i-2]=='.'){
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                }
                else if(str2[i-1] == str1[j-1] || str2[i-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
            // cout<< boolalpha <<dp[i][j]<<"      ";
        }
        // cout<< endl;
    }
    cout<<boolalpha<<dp[n2][n1]<<endl;
}