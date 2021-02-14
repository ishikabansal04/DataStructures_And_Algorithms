#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cs(int n){
    // write your code here
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    
    int count=0;
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=dp[1] + dp[0];
    
    for(int i=3;i<=n;i++){
        for(int j=1; j<=3;j++){
            dp[i]+= dp[i-j];
        }
    }

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}