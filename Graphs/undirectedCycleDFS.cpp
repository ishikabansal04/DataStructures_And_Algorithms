#include<iostream>
#include<vector>
using namespace std;


bool DFS_helper(int src, vector<int>arr[], vector<bool>&visited, vector<int>&parent){
    if(visited[src]==true){
        return true;
    }
    visited[src]=true;
    bool smallcycle=false;
    for(int i: arr[src]){
        if(visited[i]!=true){
            parent[i]=src;
            smallcycle=smallcycle || DFS_helper(i, arr, visited, parent);
        }
        else{
            if(i== parent[src]){
                continue;
            }
            else{
                return true;
            }
        }
    }
    return smallcycle;
}

bool DFS_cycle(vector<int>arr[], int vtx){
    vector<bool>visited(vtx,false);
    vector<int>parent(vtx, -1);
    for(int i=0;i<vtx;i++){
        if(!visited[i]){
            bool cycle= DFS_helper(i, arr, visited, parent);
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
            arr[v].push_back(u);
        }
        cout<<DFS_cycle(arr, vtx);

    }
    return 0;
}