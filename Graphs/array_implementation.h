#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int>* l;

    public:
    Graph(int v){
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
};
