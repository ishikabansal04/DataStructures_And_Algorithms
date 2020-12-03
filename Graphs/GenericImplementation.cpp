#include<iostream>
#include<map>
#include<list>
#include<string>
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
};

int main(){
    Graph<string> g;
    g.addEdge("Aditya", "Ishika");
    g.addEdge("Aditya", "Ishtyaa");
    g.addEdge("Ishika", "Ishtyaa");
    g.display();
}