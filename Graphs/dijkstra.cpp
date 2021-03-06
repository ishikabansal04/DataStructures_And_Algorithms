//using Adjacency Matrix

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int findMinVtx(int *weights, bool*visited, int size){
    int minvtx=-1;
    int minwt=INT_MAX;
    for(int i=0;i<size;i++){
        if(!visited[i] && weights[i]<minwt){
            minwt=weights[i];
            minvtx=i;
        }
    }
    return minvtx;
}

void dijkstra(int **arr, int vtx){


    int* parent =new int[vtx];
    for(int i=0;i<vtx;i++){
        parent[i]=i;
    }
    int* weights =new int[vtx];
    for(int i=0;i<vtx;i++){
        weights[i]=INT_MAX;
    }
    bool* visited =new bool[vtx];
    for(int i=0;i<vtx;i++){
        visited[i]=false;
    }
    parent[0]=-1;
    weights[0]=0;
    int count=0;
    while(count<vtx){
         int currvtx= findMinVtx(weights, visited, vtx);
         if(currvtx==-1){
             count++;
             
             continue;
         }
         visited[currvtx]=true;
         for(int i=0;i<vtx;i++){
              
             if(arr[currvtx][i]!=-1 && !visited[i]){
                 if(weights[i]>arr[currvtx][i]){
                     
                     parent[i]=currvtx;
                     weights[i]=weights[currvtx]+arr[currvtx][i];
                     
                 }
             }
         }
        count++; 
    }
    for(int i=0;i<vtx;i++){
        cout<<i<<"      "<<parent[i]<<"      "<<weights[i]<<endl;
    }


}
int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    
    int **arr=new int*[vtx];
    for(int i=0;i<vtx;i++){
        arr[i]=new int[vtx];
    }
    for(int i=0;i<vtx;i++){
        for(int j=0;j<vtx;j++){
            arr[i][j]=-1;
        }
    }
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        cin>> arr[a][b];
        arr[b][a]=arr[a][b];
    }

    cout<<endl;
    dijkstra(arr,vtx);


}