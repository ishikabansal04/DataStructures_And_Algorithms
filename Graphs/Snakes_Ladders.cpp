#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

    void Snakes_Ladders(vector<vector<int>>&ladders, vector<vector<int>>&snakes){
        vector<int>distance(101, 0);
        for(int i=0;i<ladders.size();i++){
            distance[ladders[i][0]]+=(ladders[i][1]-ladders[i][0]);
        }
        for(int i=0;i<snakes.size();i++){
            distance[snakes[i][0]]+=(snakes[i][1]- snakes[i][0]);
        }
        int count=0;
        queue<int>que;
        que.push(1);
        vector<int>moves(101,INT_MAX);
        bool res=false;
        moves[1]=0;
        for(int i=2;i<7;i++){
            moves[i+distance[i]]=1;
        }
        while(que.size()!=0){

            int rn=que.front();
            que.pop();
            if(rn==100){
                res=true;
                break;
            }

            for(int i=1;i<=6;i++){
                int x=rn+i;
                x=x+ distance[x];
                if(x<=100 && x>=1){
                    if(moves[x]>=moves[rn]+1){
                        moves[x]=moves[rn]+1;
                        que.push(x);
                    }
                }
            }
        }
        if(!res){
            cout<<-1<<endl;
        }
        else{
            cout<<moves[100]<<endl;
        }
    }


int main(){
    int nl, ns;
    cin>>nl;
    vector<vector<int>>ladders(nl, vector<int>(2));
    for(int i=0;i<nl;i++){
        cin>>ladders[i][0]>>ladders[i][1];
    }
    cin>>ns;
    vector<vector<int>>snakes(ns, vector<int>(2));
    for(int i=0;i<ns;i++){
        cin>>snakes[i][0]>>snakes[i][1];
    }
    Snakes_Ladders(ladders, snakes);
}
