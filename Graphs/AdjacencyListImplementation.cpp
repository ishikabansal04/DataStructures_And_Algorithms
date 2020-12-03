#include<iostream>
#include<list>
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
    g.display();
}