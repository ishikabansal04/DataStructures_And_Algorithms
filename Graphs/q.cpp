#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<utility>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int, int> vi;
typedef unordered_set<int> usi;

#define mp make_pair
#define INFI 10e8 

    bool detect_cycle_helper(int src, vector<int>gmap[], usi &visited){
        if(visited.find(src)!=visited.end()){
            cout<<"I form cycle   "<<src<<endl;
            return 1;
        }
        visited.insert(src);
        bool recursive_cycle = false;
        for(auto neighbour : gmap[src]){
            if (visited.find(neighbour) == visited.end())
            {
                // cout<<"Call for"<<neighbour<<endl;
                recursive_cycle = detect_cycle_helper(neighbour, gmap, visited);
                if(recursive_cycle == 1){
                    cout<<"2    ";
                    return 1;
                }
            }
            else{
                cout<<"3    ";
                return 1;
            }
        }
        return 0;
    }
    bool detect_cycle(int V, vector<int>gmap[]){
        usi visited; 
        bool cycle = false;
        for(int i=0;i<V;i++){
            if(visited.find(i) == visited.end()){
                // visited.insert(node.first);
                // cout<<"Call for"<<node.first<<endl;
                cycle = detect_cycle_helper(i, gmap, visited);
                if(cycle){
                    break;
                }
            }
        }
       return cycle;
    }


int main(){
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int V, E, u, v, w;
        cin >> V >> E;
        vector<int>adj[1000];
        
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            adj[u].push_back(v);
        }

        // for(int i=0;i<V;i++){
        //     cout<<i<<" =>";
        //     for(int k:adj[i]){
        //         cout<<k<<"  ";
        //     }
        //     cout<<endl;
        // }
        cout<<detect_cycle(V, adj)<<endl;
    }
    
}