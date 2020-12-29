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

    void Hamiltonian(int src, int vtx, unordered_map<int, bool>&visited, string str, vector<string>&path, int original){
        if(visited.size()==1){
            str=str+ to_string(src);
            bool res=false;
            for(int i: gmap[src]){
                if(i==original){
                    str=str+"*";
                    res=true;
                    break;
                }
            }
            if(!res){
                str=str+".";
            }
            path.push_back(str);
            return;
        }
        // cout<<src<<"    "<<str<<"    "<<visited.size()<<endl;
        str=str+to_string(src);
        visited.erase(src);
        for(int nbr: gmap[src]){
            if(visited.count(nbr)>0){
                Hamiltonian(nbr, vtx, visited, str, path, original);
            }
        }
        visited[src]=true;
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
    unordered_map<int, bool>visited;
    for(int i=0;i<vtx;i++){
        visited[i]=true;
    }
    vector<string>path;
    g.Hamiltonian(src, vtx, visited, "", path, src);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<endl;
    }
}