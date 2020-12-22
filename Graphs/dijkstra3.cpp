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
        if(v==0){
            this->v=v;
            this->d=0;
        }
        else{
            this->v=v;
            this->d=d;
        }    
    }
};

bool operator<(const Vertex e1, const Vertex e2){
    return e1.d<e2.d;
}

class Graph{
    public:
    unordered_map<Vertex, vector<pair<Vertex,int> > >gmap;

    void addEdge(Vertex u, Vertex v, int w, bool bidir=true){
        pair<Vertex, int>newpair1(v,w);
        pair<Vertex, int>newpair2(u,w);
        gmap[u].push_back(newpair1);
        if(bidir){
            gmap[v].push_back(newpair2);
        }
    }

    void dijkstra(priority_queue<Vertex>&pq){
        unordered_map<Vertex, bool>visited;
        int count=0;
        while(count<gmap.size()){
            Vertex minvtx= pq.top();
            pq.pop();
            visited[minvtx]=true;
            for(auto i:gmap[minvtx]){
                if(visited.count(i.first)>0){
                    continue;
                }
                else{
                    if(i.first.d > minvtx.d+ i.second){
                        i.first.d = minvtx.d+ i.second;
                    }
                }
            }
            count++;
        }
        // for(auto j: gmap){
        //     cout<<j.first.v<<" => "<<j.first.d<<endl;
        // }
        
    }
};


int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    priority_queue<Vertex>pq;
    Graph g;
    
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Vertex vtx1(u,INT_MAX);
        Vertex vtx2(v,INT_MAX);
        g.addEdge(vtx1, vtx2, w);
    }
    
    Vertex src(0,0);
    pq.push(src);

    for(int i=1;i<vtx;i++){
        Vertex vtx(i,INT_MAX);
        pq.push(vtx);
    }

    g.dijkstra(pq);

}