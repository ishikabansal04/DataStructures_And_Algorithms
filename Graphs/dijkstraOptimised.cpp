//dijkstra using sets (Optimized version)
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

    void dijkstra(){
        
        unordered_map<int, int>distance;

        for(auto i:gmap){
            distance[i.first]=INT_MAX;
        }
        distance[0]=0;

        set<pair<int, int>>myset;
        myset.insert(make_pair(0,0));
        
        while(myset.size()!=0){
            
            pair<int,int> minvtx= *myset.begin();
            myset.erase(myset.begin());
            int currvtx=minvtx.second;
            int currdist=minvtx.first;

            for(auto i:gmap[currvtx]){
                if(distance[i.first]> currdist+i.second){
                    auto f=myset.find(make_pair(distance[i.first], i.first));
                    if(f!=myset.end()){
                        myset.erase(f);
                    }
                    distance[i.first]= currdist+i.second;
                    myset.insert(make_pair(distance[i.first], i.first));
                }
            }
        }
        for(auto i:distance){
            cout<<i.first<<" => "<<i.second<<endl;
        }
    }
};


int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph g;
    
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;  
        g.addEdge(u, v, w);
    }
    

    g.dijkstra();
   
}