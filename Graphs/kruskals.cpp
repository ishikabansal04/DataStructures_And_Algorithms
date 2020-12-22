#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
bool compare(const Edge& e1,const Edge& e2 ){
    if(e1.w<e2.w){
        return true;
    }
    return false;
}

int findParent(int vtx, int* parent){
    if(parent[vtx]==vtx){
        return vtx;
    }
    return findParent(parent[vtx], parent);
}

int kruskals(Edge* arr,int vtx, int edges, int* parent){
    Edge* output=new Edge[vtx-1];
    sort(arr, arr+edges, compare);
    cout<<endl<<endl;
    for(int i=0;i<edges;i++){
        cout<<arr[i].u<<"  ";
        cout<<arr[i].v<<"  ";
        cout<<arr[i].w<<endl;
    }
    cout<<endl<<endl;
    int mst=0;
    int count=0;
    for(int i=0;count<vtx-1;i++){
        Edge curredge=arr[i];
        int parent1=findParent(curredge.u, parent);
        int parent2=findParent(curredge.v, parent);

        if(parent1 !=parent2){  

            parent[parent1]=parent2;  // Always do this instead of parent[curredge.u]=curredge.v; //veryyyyy important
            mst+=curredge.w;
            output[count]=curredge;
            count++;
        }
        
    }

    cout<<"Following are the edges in the constructed MST"<<endl;
    for(int i=0;i<vtx-1;i++){
        if(output[i].u < output[i].v){
            cout<<output[i].u<<" --";
            cout<<output[i].v<<" == ";
        }
        else{
            cout<<output[i].v<<" --";
            cout<<output[i].u<<" == ";
        }
        
        cout<<output[i].w<<endl;
    }
    return mst;
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
    int* parent =new int[vtx];
    for(int i=0;i<vtx;i++){
        parent[i]=i;
    }
    int res= kruskals(arr,vtx, edges, parent);
    cout<<"Minimum Cost Spanning Tree: ";
    cout<<res;
}