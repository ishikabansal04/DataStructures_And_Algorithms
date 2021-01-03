#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> gmap;
    public:
    
    void addEdge(T u, T v, bool bidir=true){
        gmap[u].push_back(v);
        if(bidir){
            gmap[v].push_back(u);
        }
    }

    void display(){
        for(auto vtx: gmap){
            cout<<vtx.first<<"=> ";
            for(auto i: vtx.second){
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }


    bool cycle(T st, unordered_map<T,bool>& vis,unordered_map<T, int>& nnodes){
    
        queue<T>que;
        bool cycle=true;
        
        que.push(st);
        nnodes[st]=1;
        vis[st]=true;
        while(que.size()!=0){
            T rn=que.front();
            que.pop();
            // cout<<rn<<", ";
            for(auto i: gmap[rn]){
                if(vis.count(i)>0){
                    if(nnodes[rn]-nnodes[i]%2==0){
                        cycle=true;
                        continue;
                    }
                    else{
                        cycle=false;
                        break;
                    }
                    
                }
                else{
                    vis[i]=true;
                    nnodes[i]=nnodes[src]+1;
                    que.push(i);
                }
            }
        }
        // cout<<endl;
        return cycle;
    }
};

int main(){
    int vtx;
    cin>>vtx;
    int edge;
    cin>>edge;
    Graph<int> g;
    for(int i=0;i<edge;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b,false);
    }
    bool res=false;
    unordered_map<int,bool>vis;
    unordered_map<int, int>nnodes;
    for(int i=0;i<vtx;i++){
        
        if(vis.count(i)>0){
            continue;
        }
        else{
            res = g.cycle(i, vis, nnodes);
            if(res){
                break;
            }
        }
    }
    
    cout<<boolalpha<<res;
}