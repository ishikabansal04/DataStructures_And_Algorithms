#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

#define mp make_pair

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;

class Graph{
public:
    unordered_map<int, list<int> > gmap;

    void addEdge(int src, int dest, bool bidir = true){
        gmap[src].push_back(dest);
        if(bidir){
            gmap[dest].push_back(src);
        }
    }
    public:
    long Roads_Libraries_helper(int src, vector<bool>&visited, int clib, int croad){
        // cout<<src<<endl;
        if(visited[src]){
            return 0;
        }
        visited[src]=true;
        long count=1;
        for(auto neighbour:gmap[src]){
            if(!visited[neighbour]){
                count+=Roads_Libraries_helper(neighbour, visited, clib, croad);
            }
        }
        return count;
    }

    long Roads_Libraries(int vtx, int clib, int croad){
        vector<bool>visited(vtx, false);
        long tcost=0;
        for(int i=0;i<vtx;i++){
            if(!visited[i]){
                long count= Roads_Libraries_helper(i, visited, clib, croad);
                long ccost=clib;
                ccost=ccost + min((count-1)*clib, (count-1)*croad);
                tcost+=ccost;
            }
        }
        return tcost;
    }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int vtx,edges,clib,croad;
        cin>>vtx>>edges>>clib>>croad;
        Graph g;
        for(int i=0;i<edges;i++){
            int a,b;
            cin>>a>>b;
            g.addEdge(a-1,b-1);
        }
        cout<<g.Roads_Libraries(vtx, clib, croad)<<endl;
    }
}