#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> gmap;
    public:
    
    void addEdge(T u, T v, bool bidir=false){
        gmap[u].push_back(v);
        if(bidir){
            gmap[v].push_back(u);
        }
    }
    
    map<T, list<T>> Tmap;
    void addEdge2(T u, T v, bool bidir=false){
        Tmap[u].push_back(v);
        if(bidir){
            Tmap[v].push_back(u);
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

    void display2(){
        for(auto vtx: Tmap){
            cout<<vtx.first<<"=> ";
            for(auto i: vtx.second){
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }
   
    void transpose(){
        for(auto vtx:gmap){
            for(auto i:vtx.second){
                addEdge2(i, vtx.first);
            }
        }
    }

    void DFS(T st, vector<T>&stk, unordered_map<T,bool>&vis){
        if(vis.count(st)>0){
            return;
        }
        vis[st]=true;
        
        for(auto i: gmap[st]){
                if(vis.count(i)>0){
                    continue;
                }
                else{
                    
                    DFS(i, stk, vis);
                }
        }
        
        stk.push_back(st);
    }

    void DFS2(T st, vector<T>&stk, unordered_map<T,bool>&vis2){
        if(vis2[st]){
            return;
        }
        cout<<st<<"  ";
        vis2[st]=true;
        
        for(auto i: Tmap[st]){
                if(vis2.count(i)>0){
                    continue;
                }
                else{
                    DFS2(i, stk, vis2);
                }
            }
    }


    int KosaRaju(int vtx){
        vector<T>stk;
  
        unordered_map<T,bool>vis;
        for(auto vtx:gmap){
           
                if(vis.count(vtx.first)>0){
                    continue;
                }
                else{

                    DFS(vtx.first, stk, vis);
                }
                
            
        }
        transpose();
        display2();
        int count=0;
        unordered_map<T,bool>vis2;
        for(int i=stk.size()-1;i>=0;i--){
            if(vis2.count(stk[i])>0){
                
                continue;
            }
            else{
                T rn=stk[i];
                count++;
                DFS2(rn, stk, vis2);
                
            }
          
        }
        return count;
    }
};

int main(){
    int vtx,edges;
    cin>>vtx>>edges;
    Graph<char> g;
    for(int i=0;i<edges;i++){
        char a,b,c;
        cin>>a>>b;
        g.addEdge(a,b,false);
    }
    
    cout<<g.KosaRaju(vtx);
}