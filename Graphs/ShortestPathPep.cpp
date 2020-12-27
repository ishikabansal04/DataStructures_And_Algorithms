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


// struct compare{

// bool operator()(pair<int, int> const &a, pair<int, int>const & b){
//      if(a.first== b.first){
//          return a.second>b.second;
//      }
//      else{
//          return a.first>b.first;
//      }
// }

// };

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
 
    void ShortestPaths(int src, int v, int e){
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int,int>>>pq;
        vector<int>visited(v, false);
        vector<int>distance(v, INT_MAX);
        vector<string>path(v, "");
        vector<int>parent(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
        
        distance[src]=0;
        path[src]=to_string(src);
        parent[src]=-1;
        pq.push(make_pair(0, src));
        while(pq.size()!=0){
            pair<int, int>newpair= pq.top();
            pq.pop();
            if(visited[newpair.second]){
                continue;
            } 
            
            cout<<newpair.second<<" via "<<path[newpair.second]<<" @ "<<distance[newpair.second]<<endl;
            visited[newpair.second]=true;
            for(auto i: gmap[newpair.second]){
                 if(!visited[i.first]){
                    if(distance[i.first] >= i.second + distance[newpair.second]){
                        distance[i.first] = i.second +  distance[newpair.second];
                        parent[i.first] = newpair.second;  
                        path[i.first]= path[newpair.second]+ to_string(i.first);
                    }   
                    pq.push(make_pair(distance[i.first], i.first));
                        
            }
            }
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