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
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

    int Infection(int src, int time, int vtx){
        queue<pair<int, int>>pq;
        vector<bool>vis(vtx, false);
        pq.push(mp(src, 1));
        vis[src]=true;
        int t=1, count=0;
        while(pq.size()!=0){
            pair<int, int> top=pq.front();
            pq.pop();
            if(top.second<=time){
                count++;
            }
            
            for(auto i:gmap[top.first]){
                if(!vis[i.first]){
                    pq.push(mp(i.first, top.second+1));
                    vis[i.first]=true;
                }
            }
        }

        return count;
    }

};

int main(){
    // std::ios::sync_with_stdio(false);
    int vtx,edges;
    cin>>vtx>>edges;
    Graph g;
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b,c);
    }

    
    int src;
    cin>>src;
    int time;
    cin>>time;

    cout<<g.Infection(src, time, vtx);
}