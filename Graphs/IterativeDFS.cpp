#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
#include<utility>
#include<string>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>>gmap;
    void addEdge(int u, int v, bool bidir=true){
        gmap[u].push_back(v);
        if(bidir){
            gmap[v].push_back(u);
        }
    }

    void DFS(int src, int vtx){
        stack<pair<int, string>>stk;
        vector<bool>visited(vtx, false);
        stk.push(make_pair(src, to_string(src)));
    
        while(stk.size()!=0){
            pair<int, string> top =stk.top();
            stk.pop();
            if(visited[top.first]){
                continue;
            }
            cout<<top.first<<"@"<<top.second<<endl;
            visited[top.first]=true;
            for(auto child : gmap[top.first]){
                if(!visited[child]){
                    stk.push(make_pair(child, top.second+to_string(child)));
                }
            }
        }
    }
};

int main(){
    Graph g;
    int vtx, edges;
    cin>>vtx>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u, v);
    }
    int src;
    cin>>src;
    g.DFS(src, vtx);
}