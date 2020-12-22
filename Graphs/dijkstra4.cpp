#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<utility>
#include<map>
#include<unordered_map>
#include<set>
#include<list>
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


// class int{
//     public:
//     int v;
//     int d;
//     int(int v, int d){
//         if(v==0){
//             this->v=v;
//             this->d=0;
//         }
//         else{
//             this->v=v;
//             this->d=d;
//         }    
//     }
// };

// bool operator<(const int e1, const int e2){
//     return e1.d<e2.d;
// }

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>gmap;

    void addEdge(int u, int v, int w, bool bidir=true){
        pair<int, int>newpair1(v,w);
        pair<int, int>newpair2(u,w);
        gmap[u].push_back(newpair1);
        if(bidir){
            gmap[v].push_back(newpair2);
        }
    }

    void dijkstra(set<pair<int,int>>& pq){
        unordered_map<int, bool>visited;
        int count=0;
        while(count<gmap.size()){
            pair<int,int> minvtx= *pq.begin();
            pq.erase(pq.begin());
            visited[minvtx.second]=true;
            int currvtx= minvtx.second;
            for(auto i:gmap[currvtx]){
                if(visited.count(i.first)>0){
                    continue;
                }
                else{
                    if(i.second > minvtx.first+ i.second){
                        pair<int, int>rpair(i.first.d, i.first.v);
                        pq.erase(rpair);
                        i.first.d = minvtx.first+ i.second;
                        rpair.first=i.first.d;
                        pq.insert(rpair);
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
    set<pair<int,int>>pq;   //distance v;
    Graph g;
    
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        int vtx1(u,INT_MAX);
        int vtx2(v,INT_MAX);
        g.addEdge(vtx1, vtx2, w);
    }
    
    // int src(0,0);
    pair<int,int> src(0,0);
    pq.insert(src);

    for(int i=1;i<vtx;i++){
        pair<int,int> vtx(i,INT_MAX);
        pq.insert(vtx);
    }

    g.dijkstra(pq);

}