#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>inp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    int k;
    cin>>k;
    unordered_map<int, int>vis;
    int i;
    for(i=0;i<k;i++){
        vis[inp[i]]+=1;
    }
    for(;i<n;i++){
        cout<<vis.size()<<" ";
        vis[inp[i-k]]-=1;
        if(vis[inp[i-k]]<=0){
            vis.erase(inp[i-k]);
        }
        vis[inp[i]]+=1;
    }
    cout<<vis.size();
return 0;
}