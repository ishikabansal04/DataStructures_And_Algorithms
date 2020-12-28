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
    void Hamiltonian(int src, int vtx, vector<bool>&visited, string str){
        bool res=false;
        for(int i=0;i<vtx;i++){
            if(!visited[i]){
                res=true;
                break;
            }
        }
        if(!res){
            
            return;
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
    vector<bool>visited(vtx, false);
    g.Hamiltonian(src, vtx, visited);
}