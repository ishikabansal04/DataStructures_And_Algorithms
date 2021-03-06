#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
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

    void DFS(T st, vector<bool>&vis, stack<int>&stk){
        if(vis[st]){
            return;
        }
        vis[st]=true;
        for(auto i: gmap[st]){
            if(!vis[i]){
                DFS(i, vis, stk);
            }
        }
        stk.push(st);
    }
    stack<T> tsort(int vtx){
        vector<bool>vis(vtx, false);
        stack<T>stk;
        for(int i=0;i<vtx;i++){
            if(!vis[i]){
                DFS(i, vis, stk);
            }
        }
        return stk;
    }
};

int main(){
    
    int vtx;
    cin>>vtx;
    int edges;
    cin>>edges;
    Graph<int> g;
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b,false);
    }
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 5);
    // g.addEdge(3, 4);
    // g.addEdge(2, 4);
    stack<int>stk;
    stk= g.tsort(vtx);
    while(stk.size()){
            cout<<stk.top()<<endl;
            stk.pop();
        }
}