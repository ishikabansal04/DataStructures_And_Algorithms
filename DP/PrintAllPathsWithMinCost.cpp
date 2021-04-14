#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

class Pair{
    public:
    int x;
    int y;
    string psf;
    int cost;
    Pair(int x, int y, string psf, int cost){
        this->x = x;
        this->y = y;
        this->psf = psf;
        this->cost = cost;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                dp[i][j] = arr[0][0];
            }
            else if(i==0){
                dp[i][j]= dp[i][j-1] + arr[i][j];
            }
            else if(j==0){
                dp[i][j]= dp[i-1][j] + arr[i][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //        cout<<dp[i][j]<<"    ";
    //     }
    //     cout<<endl;
    // }

    queue<Pair>que;
    que.push(Pair(n-1, m-1, "", (dp[n-1][m-1]-arr[n-1][m-1])));
    while(que.size()!=0){
        Pair top= que.front();
        que.pop();
        // cout<<top.x<<"  "<<top.y<<endl;
        if(top.x == 0 && top.y == 0){
            cout<<top.psf<<endl;
            continue;
        }
        if(top.y>0 && dp[top.x][top.y-1] == top.cost){
            que.push(Pair(top.x, top.y-1, "H" + top.psf, top.cost-arr[top.x][top.y-1]));
        }
        if(top.x>0 && dp[top.x-1][top.y] == top.cost){
            que.push(Pair(top.x-1, top.y, "V" + top.psf, top.cost-arr[top.x-1][top.y]));
        }  
    }

    return 0;
}