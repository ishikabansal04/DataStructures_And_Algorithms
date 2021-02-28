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
    vector<int>dp(cap+1, 0);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=cap;j++){
            if(j < weights[i]){
                continue;
            }
            else{
                dp[j]= max(dp[j], value[i]+dp[j-weights[i]]);
            }
        }
    }
    cout<<dp[cap]<<endl;
}