#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
#include<list>
#include<string>
using namespace std;

class Pair{
    public:
    int node=0;
    int wsf=INT_MAX;
    string psf="";
    Pair(int node, int wsf, string psf){
        this->node=node;
        this->wsf=wsf;
        this->psf=psf;
    }
};

struct compare{
        
    bool operator()(const Pair& p1, const Pair &p2){
        if(p1.wsf== p2.wsf){
            return p1.psf< p2.psf;
        }
        return p1.wsf> p2.wsf;
    }
};

class Graph{
public: 
    // * [vertex, {dest, weight}]

    unordered_map<int, list<pair<int, int>>>gmap;

    void addEdge(int src, int dest, int distance){
        pair<int, int> pair_src (dest, distance);
        gmap[src].push_back(pair_src);
        pair<int, int> pair_dest (src, distance);
        gmap[dest].push_back(pair_dest);
    }



void ShortestPaths( int src, int v, int e){
    priority_queue<Pair,vector<Pair>, compare>pq;
        vector<int>visited(v, false);
        vector<int>distance(v, INT_MAX);
        
        
        distance[src]=0;
        pq.push(Pair(src, 0, to_string(src)));
    while(pq.size()!=0){
        
        Pair newpair= pq.top();
        pq.pop();
        
        if(visited[newpair.node]){
            continue;
        }
        
            cout<<newpair.node<<" via "<<newpair.psf<<" @ "<<newpair.wsf<<endl;
            visited[newpair.node]=true;
            for(auto i: gmap[newpair.node]){
                
                 if(!visited[i.first]){
                    if(distance[i.first] > i.second + newpair.wsf){
                        distance[i.first] = i.second +  newpair.wsf;
                    }   
                    pq.push(Pair(i.first, distance[i.first], newpair.psf+ to_string(i.first)));
                    cout<<i.first<<"  "<<distance[i.first]<<"  "<<newpair.psf+ to_string(i.first)<<endl;
                }
            }
            cout<<endl;
    }
    
}
};

int main(){
    Graph g;
    int vtx,edges;
    cin>>vtx>>edges;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
    }
    int src;
    cin>>src;
    g.ShortestPaths(src, vtx, edges);
}