#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

class Pair{
    public:
    int len;
    int idx;
    int val;
    string psf;
    Pair(int len, int idx, int val, string psf){
        this->len = len;
        this->idx = idx;
        this->val = val;
        this->psf = psf;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>dp(n, 1);
    dp[0]= 1;
    int maxlen = 1;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j] <= arr[i]){
                if(dp[i]< dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(maxlen<dp[i]){
            maxlen = dp[i];
        }
    }
    cout<<maxlen<<endl;
    queue<Pair*>que;
    for(int i=0; i<n; i++){
        if(dp[i] == maxlen){
            que.push(new Pair(maxlen, i, arr[i], to_string(arr[i])));
        }
    }
    
    vector<string>result;
    while(que.size()!=0){
        Pair* toppair = que.front();
        que.pop();
        if(toppair->len == 1){
            result.push_back(toppair->psf);
        }
        for(int i=toppair ->idx -1; i>=0; i--){
            if(arr[i]<= toppair->val && i<toppair->idx && dp[i]== (toppair->len-1)){
                que.push(new Pair(dp[i], i, arr[i], to_string(arr[i]) + " -> " + toppair->psf ));
            }
        }
    }
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}