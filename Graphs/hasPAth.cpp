#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> gmap;
    public:
    
    void addEdge(T u, T v, bool bidir=true){
        gmap[u].push_back(v);
        if(bidir){
            gmap[v].push_back(u);
        }
    }

    void display(){
        for(auto vtx: gmap){
            cout<<vtx.first<<"=> ";
            for(auto i: vtx.second){
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }

    bool DFS(T st, T dest, vector<bool>&vis){
        if(st==dest){
            return true;
        }
        if(vis[st]){
            return false;
        }
        vis[st]=true;
        bool res=false;
        for(auto i: gmap[st]){
            if(!vis[i]){
                res=res|| DFS(i, dest, vis);
            }
        }
        return res;
    }
};

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph<int> g;
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b);
    }
    
    int src;
    cin>>src;
    int dest;
    cin>>dest;

    vector<int>path;
    vector<bool>vis(6, false);
    bool res= g.DFS(src, dest, vis);
    cout<<boolalpha<<res;
}