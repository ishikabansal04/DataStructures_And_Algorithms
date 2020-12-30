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
    int vtx,edges;
    cin>>vtx>>edges;
    Graph<int> g;
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b,false);
    }
    
    vector<bool>vis(vtx, false);
    int count=0;
    cout<<"[";
    for(int i=0;i<7;i++){
        if(!vis[i]){
            vector<int>path;
            count++;
            g.DFS(i, path, vis);
            if(count>1){
                cout<<", ";
            }
            cout<<"[";
            for(int j=0;j<path.size()-1;j++){
                cout<<path[j]<<", ";
            }
            cout<<path[path.size()-1];
            cout<<"]";
            
        }
    }
    cout<<"]"<<endl;
    //cout<<"There are in total "<<count<<" components in given graph"<<endl;
}