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

    void Multisolver(vector<bool>&visited, int src, int dest, vector<pair<int, string>>&paths, string str, int wt){
        if(src==dest){
            str=str+to_string(dest);
            paths.push_back(mp(wt, str));
            
        }
        if(visited[src]){
            return;
        }
        visited[src]=true;
        str=str+to_string(src);
        for(auto i:gmap[src]){
            if(!visited[i.first]){
                Multisolver(visited, i.first, dest, paths, str, wt+i.second);
            }
        }
        visited[src]=false;
    }
};

int main(){
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
    int dest;
    cin>>dest;
    int criteria;
    cin>>criteria;
    int k;
    cin>>k;

    vector<pair<int,string>>path;
    vector<bool>vis(vtx, false);

    g.Multisolver(vis, src, dest, path,"", 0);
    sort(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i].first<<"      "<<path[i].second<<endl;
    }

    cout<<"Smallest Path = "<<path[0].second<<"@"<<path[0].first<<endl;
    cout<<"Largest Path = "<<path[path.size()-1].second<<"@"<<path[path.size()-1].first<<endl;
    
    for(int i=0;i<path.size();i++){
        if(path[i].first>criteria){
            cout<<"Just Larger Path than "<<criteria<<" = "<<path[i].second<<"@"<<path[i].first<<endl;
            break;
        }
    }
    for(int i=path.size()-1;i>=0;i--){
        if(path[i].first<criteria){
            cout<<"Just Smaller Path than "<<criteria<<" = "<<path[i].second<<"@"<<path[i].first<<endl;
            break;
        }
    }
    cout<<k<<"th"<<" largest path = "<<path[path.size()-k].second<<"@"<<path[path.size()-k].first<<endl;

}