#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int,vector<int>>gmap;
    void addEdge(int u, int v, bool bidir=true){
        gmap[u].push_back(v);
        if(bidir){
            gmap[v].push_back(u);
        }
    }

    bool bipartiteHelper(queue<int>&que, unordered_map<int, int>&visited){
        bool res=true;
        bool idx=0;
        int size=que.size();
        while(que.size()!=0){
            int rn=que.front();
            que.pop();
            // cout<<idx<<endl;
            for(int i:gmap[rn]){
                if(visited.count(i)>0){
                    if(visited[i]!=(!idx)){
                        // cout<<i<<"ME"<<endl;
                        res=false;
                        break;
                    }
                }
                else{
                    visited[i]=!idx;
                    que.push(i);
                }
            }
            size--;
            if(size==0){
                idx=!idx;
                size=que.size();
            }
        }
        return res;
    }
    void Bipartite(int vtx, int edges){
        queue<int>que;
        bool res=true;
        unordered_map<int, int>visited;
        for(auto i:gmap){
            if(visited.count(i.first)>0){
                continue;
            }
            else{
                que.push(i.first);
                visited[i.first]=0;
                res=bipartiteHelper(que, visited);
                if(!res){
                    break;
                }
            }
        }
        cout<<boolalpha<<res<<endl;
    }
};


int main(){
    Graph g;
    int vtx, edges;
    cin>>vtx>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.Bipartite(vtx, edges);
}