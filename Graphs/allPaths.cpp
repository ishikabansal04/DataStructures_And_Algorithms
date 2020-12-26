#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
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

    void DFS(T st,T dest, vector<string>&path, vector<bool>vis, string str){
        if(st==dest){
            str=str+to_string(dest);
            path.push_back(str);
        }
        if(vis[st]){
            return;
        }
        vis[st]=true;
        str=str+to_string(st);
        for(auto i: gmap[st]){
            if(!vis[i]){
                DFS(i, dest, path, vis, str);
                // if we add in the arguments itself then src vertex is not printed ... so in order to add src to string 
                //as well we need to keep str+to_string(st) outside this loop
                //but then dest vertex is not added so we add dest vertex in base condition.
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
        g.addEdge(a,b);
    }
    
    int src;
    cin>>src;
    int dest;
    cin>>dest;


    vector<string>path;
    vector<bool>vis(vtx, false);

    g.DFS(src, dest, path, vis , "");
    sort(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<endl;
    }
}