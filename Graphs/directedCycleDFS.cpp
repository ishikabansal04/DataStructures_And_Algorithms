#include<iostream>
#include<vector>
using namespace std;


bool DFS_helper(int src, vector<int>arr[], vector<bool>&visited, vector<int>&currstk){
    if(visited[src]==true){
        return true;
    }
    visited[src]=true;
    bool smallcycle=false;
    for(int i: arr[src]){
        if(visited[i]!=true){
            currstk[i]=1;
            smallcycle=smallcycle || DFS_helper(i, arr, visited, currstk);
        }
        else{
            if(!currstk[i]){
                continue;
            }
            else{
                return true;
            }
        }
    }
    currstk[src]=0;
    return smallcycle;
}

bool DFS_cycle(vector<int>arr[], int vtx){
    vector<bool>visited(vtx,false);
    vector<int>currstk(vtx, 0);

    for(int i=0;i<vtx;i++){
        if(!visited[i]){
            currstk[i]=1;
            bool cycle= DFS_helper(i, arr, visited, currstk);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int vtx, edges;
        cin>>vtx>>edges;
        vector<int>arr[100000];
        for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            arr[u].push_back(v);
        }
        cout<<DFS_cycle(arr, vtx);

    }
    return 0;
}