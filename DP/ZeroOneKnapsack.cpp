#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>weights(n);
    vector<int>value(n);
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    
    int cap;
    cin>>cap;
    vector<vector<int>>dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                int val1 = dp[i-1][j];
                int val2 = dp[i-1][j-weights[i-1]] + value[i-1];
                dp[i][j] = max(val1, val2); 
            }
        }
    }

    cout<<dp[n][cap]<<endl;
}