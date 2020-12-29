//similar to journey to the moon problem- hackerrank!

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

    int friends_helper(int src, vector<bool>&vis){
        if(vis[src]){
            return 1;
        }
        int count=1;
        vis[src]=true;
        for(int neighbour: gmap[src]){
            if(!vis[neighbour]){
                count+=friends_helper(neighbour, vis);
            }
        }
        return count;
    }

    int friends(int vtx){
        
        vector<bool>visited(vtx, false);
        int tcount=0;
        int tsum=0;
        for(int i=0;i<vtx;i++){
            if(!visited[i]){
                int count=friends_helper(i, visited);
                // cout<<i<<"      "<<count<<endl;
                tcount=tcount+ count*tsum;
                tsum+=count;
            }
        }
        return tcount;
    }

};
int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph g;
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<g.friends(vtx);
}