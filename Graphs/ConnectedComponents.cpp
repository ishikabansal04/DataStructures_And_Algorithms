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

    void DFS(T st, vector<T>&path, vector<bool>&vis){
        if(vis[st]){
            return;
        }
        vis[st]=true;
        path.push_back(st);
        for(auto i: gmap[st]){
            if(!vis[i]){
                DFS(i, path, vis);
            }
        }
    }
};

int main(){
    
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(6, 5);
    // g.addEdge(3, 4);
    // g.addEdge(2, 4);
    vector<bool>vis(7, false);
    int count=0;
    for(int i=0;i<7;i++){
        if(!vis[i]){
            vector<int>path;
            count++;
            g.DFS(i, path, vis);
            for(int j=0;j<path.size();j++){
                cout<<path[j]<<", ";
            }
            cout<<endl;
        }
    }
    cout<<"There are in total "<<count<<" components in given graph"<<endl;
}