#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1);
    dp[n]=0;
    for(int i=n-1; i>=0; i--){
        dp[i]= dp[i+1] +1;
        if(2 * i <=n){
            dp[i]= min(dp[i], dp[2*i] +1);
        }
    }
    cout<<dp[0]<<endl;
}