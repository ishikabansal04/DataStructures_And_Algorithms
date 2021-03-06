#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

    void Snakes_Ladders(vector<vector<int>>&ladders){
        vector<int>distance(31, 0);
        for(int i=0;i<ladders.size();i++){
            distance[ladders[i][0]]+=(ladders[i][1]-ladders[i][0]);
        }
        int count=0;
        queue<int>que;
        que.push(1);
        vector<int>moves(31,INT_MAX);
        bool res=false;
        moves[1]=0;
        for(int i=2;i<7;i++){
            moves[i+distance[i]]=1;
        }
        while(que.size()!=0){

            int rn=que.front();
            que.pop();
            if(rn==30){
                res=true;
                break;
            }

            for(int i=1;i<=6;i++){
                int x=rn+i;
                x=x+ distance[x];
                if(x<=30 && x>=1){
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
            cout<<moves[30]<<endl;
        }
    }


int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int nl;
        cin>>nl;
        vector<vector<int>>ladders(nl, vector<int>(2));
        for(int i=0;i<nl;i++){
            cin>>ladders[i][0]>>ladders[i][1];
        } 
        Snakes_Ladders(ladders);
    }
}
