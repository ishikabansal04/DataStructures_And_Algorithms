#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<climits>
#include<utility>
using namespace std;

class Graph{
public: 
    // * [vertex, {dest, weight}]

    unordered_map<int, list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int distance){
        pair<int, int> pair_src (dest, distance);
        gmap[src].push_back(pair_src);
        pair<int, int> pair_dest (src, distance);
        gmap[dest].push_back(pair_dest);
    }

    void BellmenFord(int V, int E,int start){
        // vector<vector<int>> distance(V, vector<int>(V, INT_MAX));
        vector<int>distance(V, INT_MAX);
        distance[start]=0;

        for(int i=0;i<V-1;i++){
            int src=start;
            
            for(auto j: gmap[start]){
                if()
            }
        }

    }
};



int main(){
    std::ios::sync_with_stdio(false);
    // int t;
    // cin>>t;
    // for(int j=0;j<t;j++){
         Graph g;
        int V, E, u, v, d;
        cin >> V >> E;
        for(int i = 0; i < E; i++){
            cin >> u >> v >> d;
            g.addEdge(u, v, d);
        }
        int start;
        cin>>start;
        start=start-1;
        g.BellmenFord(V, E, start);
        cout<<"\n";
    // }
    return 0;
}