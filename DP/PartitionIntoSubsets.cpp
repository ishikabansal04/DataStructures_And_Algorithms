#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<long>>dp(k+1, vector<long>(n+1, 0));
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i==1){
                dp[i][j]=1;
            }
            else if(i==j){
                dp[i][j]=1;
            }
            else if(j<i){
                dp[i][j]=0;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + (dp[i][j-1] * (i));
            }
        }
    }

    cout<<dp[k][n]<<endl;
}