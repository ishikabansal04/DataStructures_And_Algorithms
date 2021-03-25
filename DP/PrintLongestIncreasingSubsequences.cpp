#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<pair<int, string>>dp(n, (make_pair(1, "")));
    int maxlen=1;
    dp[0]= (make_pair(1, to_string(arr[0])));
    for(int i=1; i<n; i++){
        int idx=-1;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                if(dp[i].first < dp[j].first + 1){
                    dp[i].first = dp[j].first + 1;
                    idx=j;
                }
            }
        }
        if(idx==-1){
            dp[i].second = to_string(arr[i]);
        }
        else{
            dp[i].second = dp[idx].second + "->" + to_string(arr[i]);                
        }
        maxlen= max(maxlen, dp[i].first);
    }
    cout<<maxlen<<endl;
    for(int i=0; i<n; i++){
        cout<<dp[i].first<< "   "<< dp[i].second<<endl;
        if(dp[i].first == maxlen){
            cout<< dp[i].second<<endl;
        }
    }
}