#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<vi>
#define vbb vector<vb>

using namespace std;

void NumberOfIslands(int i, int j, vii &arr, vbb &vis, vii dir){
    if(i==arr.size()-1 && j==arr[0].size()-1){
        return;
    }
    for(int d=0;d<dir.size();d++){
        int x=i+ dir[d][0];
        int y=j+ dir[d][1];
        if(x>=0 && x<arr.size() && y>=0 && y<arr.size()){
            if(arr[x][y]!=1 && !vis[x][y]){
                vis[x][y]=true;
                NumberOfIslands(x, y, arr, vis, dir);
            }
        }
    }
}

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    vii arr(vtx,vi(vtx,0));
    for(int i=0;i<vtx;i++){
        for(int j=0;j<vtx;j++){
            cin>>arr[i][j];
        }
    }
    vbb vis(vtx, vb(vtx, false));
    int count=0;
     vii dir={{0,1},
            {0,-1},
            {1,0},
            {-1,0}};
    for(int i=0;i<vtx;i++){
        for(int j=0;j<vtx;j++){
            if(arr[i][j]!=1 && !vis[i][j]){
                // cout<<"Call for "<<i<<"     "<<j<<"     "<<count<<endl;
                count++;
                vis[i][j]=true;
                NumberOfIslands(i, j, arr, vis, dir);
            }
        }
    }

    cout<<count<<endl;
}