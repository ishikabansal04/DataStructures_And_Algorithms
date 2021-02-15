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
    for(int i=1;i<=amt;i++){
        for(int j=0;j<n;j++){
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