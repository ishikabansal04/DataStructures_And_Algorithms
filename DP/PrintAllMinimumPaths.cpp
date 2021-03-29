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
    int val;
    int idx;
    int steps;
    string psf;
    Pair(int val, int idx, int steps, string psf){
        this->val = val;
        this->idx = idx;
        this->steps = steps;
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
    vector<int>dp(n+1, INT_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=arr[i]; j++){
            if(i + j <n){
                dp[i+j] = min(dp[i]+1, dp[i+j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<dp[i]<<"  ";
    }
    cout<<endl;
    queue<Pair*>que;
    vector<string>result;
    que.push(new Pair(arr[n-1], n-1,  dp[n-1], to_string(n-1)));
    while(que.size()!=0){
        Pair* toppair = que.front();
        que.pop();
        if(toppair->steps == 0){
            result.push_back(toppair->psf);
        }
        for(int j=0; j<toppair->idx; j++){
            if(arr[j] + j >= toppair->idx){
                if(dp[j] == toppair->steps-1){
                    que.push(new Pair(arr[j], j, dp[j], to_string(j) + " -> " + toppair->psf));
                }
            }
        }
    }
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
}