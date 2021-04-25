// same as Leetcode question 1192... critical connections in a network
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;


int time = 0;
    void helper(int start, unordered_map<int, vector<int>>&mymap, vector<int>&discovery, vector<int>&low, vector<int>&parent, vector<bool>&stk, vector<vector<int>>&critical, vector<bool>&visited){
       if(visited[start]) return;
        visited[start] = true;
        stk[start] = true;
        discovery[start] = time;
        low[start] = time;
        time++;
        
        for(int ngbr:mymap[start]){
            if(ngbr!=parent[start] && !stk[ngbr]){
                parent[ngbr] = start;
                helper(ngbr, mymap, discovery, low, parent, stk, critical, visited);
                low[start] = min(low[ngbr], low[start]);
            }
            else if(ngbr==parent[start]) continue;
            else if(stk[ngbr]){
                low[start] = min(low[start], discovery[ngbr]);
            }
            if(discovery[start] < low[ngbr]){
                vector<int>temparr;
                temparr.push_back(start);
                temparr.push_back(ngbr);
                critical.push_back(temparr);
            }
        }
        stk[start] = false;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>critical;
        unordered_map<int, vector<int>>mymap;
        vector<int>discovery(n, -1);
        vector<int>low(n, -1);
        vector<int>parent(n, -1);
        vector<bool>stk(n, false);
        vector<bool>visited(n, false);
        for(int i=0; i<connections.size(); i++){
            mymap[connections[i][0]].push_back(connections[i][1]);
            mymap[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int time = 0;
                helper(i, mymap, discovery, low, parent, stk, critical, visited);
            }
        }
        return critical;
    }

int main(){
    int n, edges;
    cin >> n >> edges;
    vector<vector<int>>Connections(edges, vector<int>(2));
    for(int i = 0; i < edges ; i++){
        cin >> Connections[i][0] >> Connections[i][1];
    }
    vector<vector<int>>result = criticalConnections(n, Connections);
    for(int i = 0 ; i<result.size() ; i++){
        for(int j = 0 ;  j<result[i].size() ; j++){
            cout << result[i][j] << "    ";
        }
        cout << endl;
    }
    return 0;
}