#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
#include<queue>
using namespace std;

template <typename all>
class Graph
{
    unordered_map<all, list<all> > gmap;

public:
    void addEdge(all u, all v, bool bidir = true)
    {
        gmap[u].push_back(v);
        if (bidir)
        {
            gmap[v].push_back(u);
        }
    }

    unordered_map<all, int>* shortestPath(all src){
        unordered_map<all, int> *distance = new unordered_map<all, int>();
        unordered_map<all, int> visited;
        queue<all> q;
        q.push(src);
        visited[src] = 1;
        distance-> insert({src, 0});
        while(!q.empty()){
            all front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(visited.count(neighbour) == 0){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    distance-> insert({neighbour, distance-> at(front) + 1});
                }
            }
        }
        return distance;    
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    unordered_map<int, int> *output = g.shortestPath(0);
    for(auto i : *output){
        cout << "The shortest path of " << i.first << " from the source vertex: " << i.second << '\n';
    }
}