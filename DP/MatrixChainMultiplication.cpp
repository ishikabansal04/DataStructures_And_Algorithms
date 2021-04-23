#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
    vector<vector<int>>dp(n-1, vector<int>(n-1, INT_MAX));
    for(int gap=0; gap<n-1; gap++){
        for(int i=0, j=gap; j<n-1; i++, j++){
            if(gap == 0) dp[i][j] = 0;
            else if(gap == 1){
                dp[i][j] = arr[i] * arr[j] * arr[j+1];
            }
            else{
                for(int k=i, l=i+1; k<j; k++, l++){
                    dp[i][j] = min(dp[i][j], (dp[i][k] + dp[l][j] + (arr[i] * arr[j+1] * arr[k+1])));
                }
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(dp[i][j]==INT_MAX) cout<<"0"<<"   ";
            else{
                cout<<dp[i][j]<<"   ";
            }
        }
        cout<<endl;
    }
    cout << dp[0][n-2];
}