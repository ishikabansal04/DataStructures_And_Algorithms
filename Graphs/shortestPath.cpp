#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Graph{
    int v;
    list<int>* l;

    public:
    Graph(int v){
        this->v=v;
        l= new list<int>[v];
    }

    void addEdge(int u, int v, bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

    void display(){
        for(int i=0; i<v; i++){
            cout<<i<<"->";
            for(int j:l[i]){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    vector<int> shortestPath(int src){
        queue<int>que;
        vector<int>dist(v, INT_MAX);
        que.push(src);
        dist[src]=0;
        while(que.size()!=0){
            int rn=que.front();
            que.pop();
            for(int j: l[rn]){
                if(dist[j]==INT_MAX){
                    dist[j]=dist[rn]+1;
                    que.push(j);
                }
            }
        }
        return dist;
    }
};


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(3,4);
    // g.display();
    vector<int>dist= g.shortestPath(0);
    for(int i=0;i<dist.size();i++){
        cout<<"Distance of "<<i<<" from 0 is: "<<dist[i]<<endl;
    }

}
