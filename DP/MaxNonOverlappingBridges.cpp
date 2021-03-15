#include<iostream>
#include<vector>
#include<climits>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>>arr(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0;i<n; i++){
        int v1, v2;
        cin>>v1>>v2;
        arr[i]= make_pair(v1, v2);
        pq.push(arr[i]);
    }
    vector<int>input;
    while(pq.size()!=0){
        auto front= pq.top();
        pq.pop();
        input.push_back(front.second);
    }
    vector<int>dp(n, 1);
    dp[0]=1;
    int maximum=dp[0];
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(input[j]<=input[i]){
                dp[i]= max(dp[i],dp[j]+1);
            }
        }
        maximum= max(maximum, dp[i]);
    }
    cout<<maximum<<endl;
}