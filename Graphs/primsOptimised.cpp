//dijkstra using sets (Optimized version)

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<utility>
#include<map>
#include<unordered_map>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int w;
    Edge(){
        u=0;
        v=0;
        w=0;
    }
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

class Vertex{
    public:
    int v;
    int d;
    Vertex(int v, int d){
        this->v=v;
        this->d=d;
    }
};

bool operator<(const Vertex& e1, const Vertex& e2){
    if(e1.d<e2.d){
        return true;
    }
    return false;
}

class Graph{
    public:
    map<int, vector<pair<int,int>>>gmap;

    void addEdge(int u, int v, int w, bool bidir=true){
        pair<int, int>newpair1(v,w);
        pair<int, int>newpair2(u,w);
        gmap[u].push_back(newpair1);
        if(bidir){
            gmap[v].push_back(newpair2);
        }
    }
    
        
    void prims(priority_queue<Vertex*>&pq){
        int* distance =new int[gmap.size()];
        for(int i=0;i<gmap.size();i++){
            distance[i]=INT_MAX;
        }
        unordered_map<int, bool>visited;
        
        distance[0]=0;
        
        int count=0;
        while(count<gmap.size()){
            Vertex* minvtx=pq.top();
            pq.pop();
            visited[minvtx->v]=true;
            for(auto i:gmap[minvtx->v]){
                if(!visited[i.first]){
                    if(distance[i.first]>i.second){
                        distance[i.first]=i.second;
                    }
                }
            }
            count++;
        }

        for(int i=0;i<gmap.size();i++){
            cout<<i<<" => "<<distance[i]<<endl;
        }
    }

};

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    priority_queue<Vertex*>pq;
    Graph g;
    
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v, w);
        
    }
    Vertex* src= new Vertex(0,0);
    pq.push(src);

    for(int i=1;i<vtx;i++){
        Vertex* vtx= new Vertex(i,INT_MAX);
        pq.push(vtx);
    }

    g.prims(pq);

}