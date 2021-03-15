#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>dp(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    dp[0]=arr[0];
    int maximum=dp[0];
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j]<=arr[i]){
                dp[i]= max(dp[i],dp[j]+arr[i]);
            }
        }
        maximum= max(maximum, dp[i]);
    }
    cout<<maximum<<endl;
}