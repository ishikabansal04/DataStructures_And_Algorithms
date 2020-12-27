#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
using namespace std;

class Edge{
    public:
    int u=0;
    int v=0;
    int w=0;
    Edge(){

    }
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};


bool compare(const Edge &e1, const Edge&e2){
    return e1.w<e2.w;
}

int Findparent(int v, vector<int>&parent){
    if(parent[v]==v){
        return v;
    }
    return Findparent(parent[v], parent);
}

void kruskals(vector<Edge>&arr, int v, int e, vector<Edge>&output){

    unordered_map<int, pair<int, int>>mymap; // dest, src, weight;
    sort(arr.begin(), arr.begin()+e, compare);
    for(int i=0;i<e;i++){
        cout<<arr[i].u<<"       "<<arr[i].v<<"      "<<arr[i].w<<endl;
    }
    vector<int>parent(v);
    
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    // visited[0]=0;
    int count=0;
    int i=0;
    while(count<v-1){
        
        Edge curredge= arr[i];
        // cout<<curredge.u<<"     "<<curredge.v<<endl;
            int p1= Findparent(curredge.u, parent);
            int p2= Findparent(curredge.v, parent);
            if(p1== p2){
                i++;
                continue;
            }
            else{
                parent[p1]=p2;
                mymap[curredge.v]= make_pair(curredge.u, curredge.w);
                count++;
            }
        i++;
    }

    // for(int i=0;i<v;i++){
    //     cout<<parent[i]<<" ";
    // }
    //  map<int, pair<int, int>>:: iterator it=mymap.begin();
    //  while(it!=mymap.end()){
    //      cout<<it->first<<"-"<<it->second.first<<"@"<<it->second.second<<endl;
    //      it++;
    //  }
    for(int i=0;i<e;i++){
        Edge curredge=output[i];
        if(mymap[curredge.v]==make_pair(curredge.u, curredge.w)){
            cout<<"["<<curredge.v<<"-"<<curredge.u<<"@"<<curredge.w<<"]"<<endl;
        }
    }
    
}

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    // Graph g;
    

    vector<Edge>arr(edges);
    vector<Edge>output(edges);
    for(int i=0;i<edges;i++){
            int u, v, w;
            cin>>u>>v>>w;
            arr[i].u=u; output[i].u=u;
            arr[i].v=v; output[i].v=v;
            arr[i].w=w; output[i].w=w;
        }

    kruskals(arr, vtx, edges, output);
}