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

    void BFS(T st){
        queue<T>que;
        unordered_map<T,bool>vis;
        que.push(st);
        vis[st]=true;
        while(que.size()!=0){
            T rn=que.front();
            que.pop();
            cout<<rn<<", ";
            for(auto i: gmap[rn]){
                if(vis.count(i)>0){
                    continue;
                }
                else{
                    vis[i]=true;
                    que.push(i);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.BFS(0);
}