#include<iostream>
#include<map>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;

#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>
#define INF 10e7

long Roads(int vtx, vvi&dp){
    for(int k=0;k<vtx;k++){
        for(int i=0;i<vtx;i++){
            for(int j=0;j<vtx;j++){
                if(i!=j){
                    if(dp[i][j]> dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] +dp[k][j];
                    }
                }
            }
        }
    }

    long tsum=0;

    for(int i=0;i<vtx;i++){
        for(int j=0;j<vtx;j++){
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<vtx;i++){
        for(int j=i;j<vtx;j++){
            tsum+=dp[i][j];
        }
    }
    return tsum;
}

string ToBinary(long tsum){
    if(tsum==0){
        return "";
    }
    string res="";
    res= ToBinary(tsum/2) + to_string(tsum%2);
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int vtx,edges;
    cin>>vtx>>edges;
    vvi input(vtx, vi(vtx, INF));
    for(int i=0;i<vtx;i++){
        for(int j=0;j<vtx;j++){
            if(i==j){
                input[i][j]=0;
            }
        }
    }    
    for(int i=0;i<edges;i++){
        int a,b,w;
        cin>>a>>b>>w;
        input[a-1][b-1]= pow(2,w);
        input[b-1][a-1]= input[a-1][b-1];
    }
    long tsum=Roads(vtx, input);
    cout<<tsum<<endl;
    cout<<ToBinary(tsum);
}