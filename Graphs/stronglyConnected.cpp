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

    void DFS(T st, stack<T>* stk, unordered_map<T,bool>&vis){
        // cout<<st<<endl;
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
        
        stk->push(st);
        // cout<<stk->top()<<endl;
    }

    void DFS2(T st, stack<T>* stk, unordered_map<T,bool>&vis2){
        if(vis2[st]){
            return;
        }
        cout<<st<<"         ";
        vis2[st]=true;
        
        for(auto i: Tmap[st]){
                if(vis2.count(i)>0){
                    continue;
                }
                else{
                    cout<<stk->top()<<endl;
                    if(stk->top()==i){
                      stk->pop();
                    DFS2(i, stk, vis2);
                }
            }
        }
        
    }


    int KosaRaju(int vtx){
        stack<T>*stk=new stack<T>;
        
        // for(int i=0;i<vtx;i++){
        //     if(!vis[i]){
        //         // cout<<i<<endl;
        //         DFS(i, stk, vis);
        //     }
        // }
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
        while(stk->size()!=0){
            // cout<<stk->top()<<endl;
            T rn=stk->top();
            stk->pop();
            
            DFS2(rn, stk, vis2);
            // cout<<count<<endl;
            count++;
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