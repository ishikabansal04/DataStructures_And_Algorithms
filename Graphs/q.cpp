//using Adjacency Matrix

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int findMinVtx(vector<int>&weights, vector<bool>&visited, int size){
    int minvtx=-1;
    int minwt=INT_MAX;
    for(int i=0;i<size;i++){
        if(!visited[i] && weights[i]<minwt){
            minwt=weights[i];
            minvtx=i;
        }
    }
    return minvtx;
}

void dijkstra(vector<vector<int>>&arr, int vtx, int start){
    vector<int>weights(vtx, INT_MAX);
    vector<bool>visited(vtx, false);
    weights[start]=0;
    int count=0;
    while(count<vtx){
         int currvtx= findMinVtx(weights, visited, vtx);
         if(currvtx==-1 || visited[currvtx]){
             count++;
             
             continue;
         }
         visited[currvtx]=true;
         for(int i=0;i<vtx;i++){
              
             if(arr[currvtx][i]!=-1 && !visited[i]){
                 if(weights[i]>arr[currvtx][i] + weights[currvtx]){
                     
                     weights[i]=weights[currvtx]+arr[currvtx][i];
                     
                 }
             }
         }
        count++; 
    }
    for(int i=0;i<vtx;i++){
        if(i==start){
            continue;
        }
        else if(weights[i]==INT_MAX){
            cout<<"-1 ";
        }
        else
        cout<<weights[i]<<" ";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++){
        int vtx,edges;
        cin>>vtx>>edges;
        vector<vector<int>>arr(vtx, vector<int>(vtx, -1));
    
        for(int i=0;i<edges;i++){
            int a,b, w;
            cin>>a>>b>>w;
            arr[a-1][b-1]=w;
            arr[b-1][a-1]=w;
        }
        int start;
        cin>>start;        
        dijkstra(arr,vtx, start-1);
        cout<<endl;
    }

}