#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
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

    void BFS(T st){
        queue<pair<T, string>>que;
        unordered_map<T,bool>vis;
        pair<T, string>mypair;
        mypair.first=st;
        mypair.second=to_string(st);
        que.push(mypair);
        vis[st]=true;
        while(que.size()!=0){
            pair<T,string> rn=que.front();
            que.pop();
            cout<<rn.first<<"@"<<rn.second<<endl;
            for(auto i: gmap[rn.first]){
                if(vis.count(i)>0){
                    continue;
                }
                else{
                    vis[i]=true;
                    pair<T, string> newpair;
                    newpair.first=i;
                    newpair.second= rn.second + to_string(i);
                    que.push(newpair);
                }
            }
        }
        
    }
};

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph<int> g;
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b);
    }
    
    int src;
    cin>>src;
    g.BFS(src);
}