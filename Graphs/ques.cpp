#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int findMinVtx(vector<int>&distance, vector<int>&visited, int v){
    int minvtx=-1;
    
    for(int i=0;i<v;i++){
        if(!visited[i] && (minvtx==-1 || distance[i]<distance[minvtx])){
           
            minvtx=i;
        }
    }
    return minvtx;
} 

void dijkstra(vector<vector<int>> &edges, int vtx){

    vector<int>distance(vtx, INT_MAX);
    vector<int>visited(vtx, false);
    distance[0]=0;

    for(int i=0;i<vtx-1;++i){
         int currvtx= findMinVtx(distance, visited, vtx);
         
         visited[currvtx]=true;
         for(int j=0;j<vtx;++j){
              
             if(edges[currvtx][j]!=0 && !visited[j]){
                 int dist=distance[currvtx]+edges[currvtx][j];
                 if(dist<distance[j]){
                     distance[j]=dist;
                 }
             }
         }
    }
    for(int i=0;i<vtx;++i){
        cout<<i<<" "<<distance[i]<<"\n";
    }
    
}
int main(){
    int vtx,edge;
    cin>>vtx>>edge;
    
    vector<vector<int>> edges(vtx ,vector<int>(vtx,0));
    
    for(int i=0, s, d, w;i<edge;++i){
      
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }

    cout<<endl;
    dijkstra(edges,vtx);
}