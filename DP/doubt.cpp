#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
#include<unordered_set>
using namespace std;
        
    int BFS(int src, int dest, int n, vector<vector<int>>&adj){
        if(src==dest){
            return 0;
        }
        queue<int>que;
        int dist=-1;
        vector<bool>visited(n, false);
        que.push(src);
        visited[src]=true;
        int count=0;
        int size=1;
        while(que.size()!=0){
            int top=que.front();
			// cout<<top<<"=> ";
            que.pop();
            if(adj[top][dest]){
                dist=count+1;
                break;
            }
			visited[top]=true;
            for(int j=0; j<n; j++){
				// cout<<j<<"	";
                if(!visited[j] && j!=top && adj[top][j]){
					// cout<<"Selected: "<<j;
                    que.push(j);
                }
            }
			// cout<<endl;
            size--;
            if(size==0){
                count+=1;
                size= que.size();
            }
        }
        return dist;
    }


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();
    int tc;
    cin>>tc;
    for(int i=0;i<tc; i++){
        int N, M, X, Y;
        cin>>N>>M>>X>>Y;
    	vector<vector<int>>adj(N, vector<int>(N, 0));
        for(int i=0;i<M;i++){
            int A, B, C, D;
            cin>>A>>B>>C>>D;
            adj[A-1][C-1]=1;
			adj[A-1][D-1]=1;
			adj[B-1][C-1]=1;
			adj[B-1][D-1]=1;
			adj[C-1][A-1]=1;
			adj[D-1][A-1]=1;
			adj[C-1][B-1]=1;
			adj[D-1][B-1]=1;
        }

		// for(int i=0; i<N;i++){
		// 	for(int j=0;j<N; j++){
		// 		cout<<adj[i][j]<<"	";
		// 	}
		// 	cout<<endl;
		// }
        int res =BFS( X-1, Y-1, N, adj);
        cout<<res<<endl;
    }
}