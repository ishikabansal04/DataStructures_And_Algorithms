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
    int amt;
    cin>>amt;
    vector<int>dp(amt+1, 0);
    dp[0]=1;
    
    for(int j=0;j<n;j++){
        for(int i=0;i<=amt;i++){
            if(i < arr[j]){
                continue;
            }
            else{
                if(dp[i-arr[j]]){
                    dp[i]+=dp[i-arr[j]];
                }
            }
        }
    }
    cout<<dp[amt]<<endl;
}