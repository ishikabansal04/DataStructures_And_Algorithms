#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){

    string str;
    cin>>str;
    int n= str.length();
    vector<vector<bool>>isPalin(n, vector<bool>(n, false));
    for(int gap = 0; gap<n; gap++){
        for(int i=0, j=gap; j<n; i++, j++){
            if(gap==0){
                isPalin[i][j] = true;
            }
            else if(gap == 1){
                isPalin[i][j] = str[i] == str[j] ? true: false;
            }
            else{
                if(str[i] == str[j]){
                    isPalin[i][j] = isPalin[i+1][j-1];
                }
            }
        }
    }

    vector<vector<int>>dp(n, vector<int>(n, 0));
    for(int gap = 0; gap<n; gap++){
        for(int i=0, j=gap; j<n; i++, j++){
            if(gap==0){
                dp[i][j] = 0;
            }
            else if(gap == 1){
                dp[i][j] = str[i] == str[j] ? 0 : 1;
            }
            else{
                if(isPalin[i][j]){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i][j-2] + dp[i+1][j] , dp[i][j-1] + dp[i+2][j]);
                }
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< dp[i][j] << "    ";
        }
        cout<<endl;
    }
    cout << dp[0][n-1] << endl;
}