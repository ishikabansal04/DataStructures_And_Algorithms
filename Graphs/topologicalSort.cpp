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

    vector<int> Indegree(){
        vector<int>degree(v,0);
        for(auto i: gmap){
            for(auto j:gmap[i]){
                degree[j]+=1;
            }
        }
        return degree;
    }

    void DFS(T st, vector<T>&path, vector<bool>&vis){
        if(vis[st]){
            return;
        }
        vis[st]=true;
        // path.push_back(st);
        for(auto i: gmap[st]){
            if(!vis[i]){
                path[i]=st;
                DFS(i, path, vis);
            }
        }
    }

    void TopologicalSort(vector<T>&path){
        vector<int>indegree= Indegree();
        vector<int>parent(v);
        vector<bool>vis(v, false);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
        for(int i=0;i<v;i++){
            if(!vis[i]){
                DFS(i, parent, vis);
            }
        }

        stack<T>stk;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                stk.push(i);
                vis[i]=true;
            }
        }

        while(stk.size()!=0){
            T rn=stk.top();
            stk.pop();
            path.push_back(rn);
            for(int j=0;j<v;j++){
                if(parent[j]==rn){
                    indegree[j]-=1;
                    if(indegree[j]==0 && !vis[j]){
                        vis[j]=true;
                        stk.push(j);
                    }
                }
            }
        }
        
    }
};

int main(){
    
    Graph<int> g;
    g.addEdge(0, 1, false);
    g.addEdge(0, 4, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 5, false);
    g.addEdge(3, 4, false);
    g.addEdge(2, 4, false);
    vector<int>path;
    g.TopologicalSort(path);
    for(int i:path){
        cout<<i<<", ";
    }
    cout<<endl;
}