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
    unordered_map<int, list<pair<int,int> > >gmap;

    void addEdge(int u, int v, int w, bool bidir=true){
        pair<int, int>newpair1(v,w);
        pair<int, int>newpair2(u,w);
        gmap[u].push_back(newpair1);
        if(bidir){
            gmap[v].push_back(newpair2);
        }
    }

    unordered_map<int, int> dijkstra(int start){
        
        unordered_map<int, int>distance;

        for(auto i:gmap){
            distance[i.first ]=INT_MAX;
        }
        distance[start]=0;

        set<pair<int, int>>myset;
        myset.insert(make_pair(0,start));
        
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
       return distance;
    }
};


// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int start) {
    vector<int>weights(n, -1);
    start=start-1;
     Graph g;
    for(int i=0;i<edges.size();i++){
        g.addEdge(edges[i][0]-1, edges[i][1]-1,edges[i][2]);
    }
    unordered_map<int, int>mymap= g.dijkstra(start);
     for(auto i:mymap){
         if(i.second!=INT_MAX)
            weights[i.first]=i.second;
    }
    weights.erase(weights.begin()+ start); 
    
    return weights;
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int vtx,ne;
        cin>>vtx>>ne;

        vector<vector<int>> edges(ne, vector<int>(3));
        for (int i = 0; i < ne; i++) {
            
                cin >> edges[i][0]>>edges[i][1]>>edges[i][2];
            
        }

        int s;
        cin >> s;

        vector<int> result = shortestReach(vtx, edges, s);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}