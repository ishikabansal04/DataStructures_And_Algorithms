//using Adjacency Matrix

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#define INF 1e7
using namespace std;

void FW(vector<vector<int>>&dp, int V){
    for(int n=0;n<V;n++){
       
        int src=n;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i==src || j==src){
                    continue;
                }
                else if(i==j){
                    continue;
                }
                else{
                    if(dp[i][src]==INF || dp[src][j]==INF){
                        continue;
                    }
                    dp[i][j]=min(dp[i][j], dp[i][src] + dp[src][j]);
                }
            }
        }
    }

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dp[i][j]==INF){
                    cout<<"INF ";
                }
                else
                    cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
}

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int vtx;
        cin>>vtx;
        vector<vector<int>>arr(vtx, vector<int>(vtx));
        
        for(int i=0;i<vtx;i++){
            for(int j=0;j<vtx;j++){ 
                
                cin>>arr[i][j];
                
            }
        }
       
        FW(arr,vtx);
    }
    return 0;
}