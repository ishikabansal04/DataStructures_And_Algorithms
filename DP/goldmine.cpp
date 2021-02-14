#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m, INT_MIN));
    for(int i=0;i<n;i++){
        dp[i][0] = arr[i][0];
    }
for(int j=1;j<m; j++){
    for(int i=0;i<n;i++){   
            if(i==0){
                dp[i][j]= max(dp[i][j-1], dp[i+1][j-1]) + arr[i][j];
            }
            else if(i==(n-1)){
                dp[i][j]= max(dp[i][j-1], dp[i-1][j-1]) + arr[i][j];
            }
            else{
                dp[i][j]= max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1])) + arr[i][j];
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0; i<n;i++){
        ans = max(ans, dp[i][m-1]);
    }
    cout<<ans<<endl;
}