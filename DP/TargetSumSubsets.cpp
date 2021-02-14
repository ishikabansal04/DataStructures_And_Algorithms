#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    vector<vector<bool>>dp(n+1, vector<bool>(tar+1, false));
    for(int i=0; i<=n; i++){
        dp[i][0]= true;
        // cout<<"Hello"<<i<<endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=tar ;j++){
            // cout<<"hello"<<i<<" "<<j<<endl;
            if(arr[i-1] > j){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    } 
    cout<<boolalpha<<dp[n][tar]<<endl;
}