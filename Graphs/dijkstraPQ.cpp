// //dijkstra using sets (Optimized version)
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #include<climits>
// #include<utility>
// #include<map>
// #include<unordered_map>
// #include<set>
// #include<list>
// using namespace std;

// class Graph{
//     public:
//     unordered_map<int, list<pair<int,int>>>gmap;

//     void addEdge(int u, int v, int w, bool bidir=true){
//         pair<int, int>newpair1(v,w);
//         pair<int, int>newpair2(u,w);
//         gmap[u].push_back(newpair1);
//         if(bidir){
//             gmap[v].push_back(newpair2);
//         }
//     }

//     void dijkstra(int start, int vtx){
        
//         unordered_map<int, int>distance;

//         for(int i=0;i<vtx;i++){
            
//             distance[i]=INT_MAX;
//         }
//         distance[start]=0;

//         set<pair<int, int>>myset;
//         myset.insert(make_pair(0,start));
        
//         while(myset.size()!=0){
            
//             pair<int,int> minvtx= *myset.begin();
//             myset.erase(myset.begin());
//             int currvtx=minvtx.second;
//             int currdist=minvtx.first;

//             for(auto i:gmap[currvtx]){
//                 if(distance[i.first]> currdist+i.second){
//                     auto f=myset.find(make_pair(distance[i.first], i.first));
//                     if(f!=myset.end()){
//                         myset.erase(f);
//                     }
//                     distance[i.first]= currdist+i.second;
//                     myset.insert(make_pair(distance[i.first], i.first));
//                 }
//             }
//         }
//         // cout<<"Hello";

//         for(int i=0;i<vtx && i!=start;i++){
//             if(distance[i]==INT_MAX){
//                 cout<<-1<<" ";
//             }
//             else
//              cout<<distance[i]<<" ";
//         }
//     }
// };


// int main(){
//     int t;
//     cin>>t;
//     for(int j=0;j<t;j++){
//         int vtx,edge;
//         cin>>vtx>>edge;
//         Graph g;
        
//         for(int i=0;i<edge;i++){
//             int u,v,w;
//             cin>>u>>v>>w;  
//             g.addEdge(u-1, v-1, w);
//         }
//         int start;
//         cin>>start;
        
//         g.dijkstra(start-1, vtx);
//         cout<<"\n";
    
//     }
// }


#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    void djikstra(int V, int E, Graph g, int start){
  
        bool *visited = new bool[V];

        int *distance = new int[V];  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> my_set;

        for(int i = 0; i < V; i++){
            if(i == start){
                distance[i] = 0;
            }
            else{
                distance[i] = INT_MAX;
            }
            visited[i] = false;
        }
        int vtx = start;
        my_set.push(make_pair(distance[vtx], vtx));

        while(!my_set.empty()){
            
            pair<int, int> curr_pair =my_set.top();
            my_set.pop();
            if(visited[curr_pair.second]){
                continue;
            }
            visited[curr_pair.second] = true;
            //cout<<distance[curr_pair.second]<<endl;
            for(auto neighbour : gmap[curr_pair.second]){
             if(visited[neighbour.first] == false){
                 int child_vtx, distance_from_src, distance_from_vtx;
                 child_vtx = neighbour.first;
                 distance_from_vtx = neighbour.second;
                 distance_from_src = curr_pair.first + neighbour.second;

                //  pair<int, int> search_pair(distance[child_vtx], child_vtx);
                    if(distance[child_vtx]> distance_from_src){
                        distance[child_vtx] = distance_from_src;
                        my_set.push(make_pair(distance[child_vtx], child_vtx));
                    }
               
             }
           }
        }
        for(int i = 0; i < V ; i++){
            if(i==start){
                continue;
            }
            else if(distance[i] == INT_MAX ){
                cout << "-1 ";
            }
            else{
                cout << distance[i] << " "; 
            }
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
         Graph g;
        int V, E, u, v, d;
        cin >> V >> E;
        for(int i = 0; i < E; i++){
            cin >> u >> v >> d;
            g.addEdge(u-1, v-1, d);
        }
        int start;
        cin>>start;
        start=start-1;
        g.djikstra(V, E, g, start);
        cout<<"\n";
    }
    return 0;
}