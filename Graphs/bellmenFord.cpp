#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
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
};

void BellmenFord(int V, int E, int start, Edge* arr){
    vector<int>distance(V, INT_MAX);
    distance[start]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int src=arr[j].u;
            int dest= arr[j].v;
            int weight= arr[j].w;
            if(distance[src]+ weight < distance[dest]){
                distance[dest]=distance[src]+ weight;
            }
        }
    }

    bool isNeg= false;
    for(int j=0;j<E;j++){
            int src=arr[j].u;
            int dest= arr[j].v;
            int weight= arr[j].w;
            if(distance[src]+ weight < distance[dest]){
                isNeg=true;
                distance[dest]=INT_MAX;
                // break;
            }
    }

    // if(isNeg){
    //     cout<<"Graph contains negative weight cycle"<<endl;
    // }
    // else{
        for(int i=0;i<V;i++){
            cout<<distance[i]<<" "<<endl;
        }
    // }
}

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Edge* arr = new Edge[edges];
    for(int i=0;i<edges;i++){
        cin>>arr[i].u;
        cin>>arr[i].v;
        cin>>arr[i].w;
    }
    int start;
    cin>>start;
     BellmenFord(vtx, edges, start, arr);
     return 0;
}