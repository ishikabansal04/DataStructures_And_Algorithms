#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>


void Knights(int sr, int sc, vvi &chess, int count, vvi dir, int n){
    if(sr<0 || sc<0 || sr>=chess.size() || sc>=chess[0].size() || chess[sr][sc]>0){
        return;
    }
    else if(count==n){
        chess[sr][sc]=count;
        for(int i=0;i<chess.size();i++){
            for(int j=0;j<chess[0].size();j++){
                cout<<chess[i][j]<<" ";
            }
            // cout<<chess[i][chess[0].size()-1];
            cout<<endl;
        }
        cout<<endl;
        chess[sr][sc]=0;
        return;
    }
    // cout<<"Hello"<<endl;
    chess[sr][sc]=count;
    // int index= sr*chess.size() + sc;
    
   
    for(int i=0;i<dir.size();i++){
        int x=sr+dir[i][0];
        int y=sc+dir[i][1];
        // int tmpidx= x*chess.size() + y;
        // if(x>=0 && y>=0 && x<chess.size() && y<chess[0].size() && vis.count(tmpidx)>0){
            // cout<<index<<"         "<<chess[sr][sc]<<"      "<<x<<"        "<<y<<endl;
            Knights(x, y, chess, count+1, dir, n);
        // }
    }
    chess[sr][sc]=0;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, row, col;
    cin>>n>>row>>col;
    // unordered_map<int, bool>visited;
    // for(int i=0;i<n*n;i++){
    //     visited[i]=true;
    // }
    vvi chess(n, vi(n, 0));
    vvi dir={{-2,1}, {-1,2}, {1,2}, {2, 1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
    Knights(row, col, chess, 1, dir, n*n);
    return 0;
}
