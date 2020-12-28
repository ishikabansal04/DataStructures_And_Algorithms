#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
#include<list>
using namespace std;

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


void prims( int v, int e){
    vector<int>distance(v, INT_MAX);
    vector<bool>visited(v, false);
    vector<int>parent(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push(make_pair(0, 0));
    distance[0]=0;
    parent[0]=0;
   
    
    while(pq.size()!=0){
        
        pair<int, int> newpair= pq.top();
        pq.pop();
        
        if(visited[newpair.second]){
            continue;
        }
        if(newpair.second!=0){
            cout<<"["<<newpair.second<<"-"<<parent[newpair.second]<<"@"<<distance[newpair.second]<<"]"<<endl;
        
        }
      

        visited[newpair.second]=true;
        for(auto i: gmap[newpair.second]){
            if(!visited[i.first]){
                if(distance[i.first] > i.second){
                    distance[i.first] = i.second;
                    parent[i.first] = newpair.second;
                pq.push(make_pair(distance[i.first], i.first));

                }
                
            }
        }
        
    }
    
}
};
int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph g;
 
    for(int i=0;i<edges;i++){
            int u, v, w;
            cin>>u>>v>>w;
            g.addEdge(u, v, w);
         
        }

    g.prims(vtx, edges);
}