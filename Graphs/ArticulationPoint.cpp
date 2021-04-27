#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

int time = 0;
void helper(int start, unordered_map<int, vector<int>>&gmap, vector<int>&parent, vector<bool>&stack, vector<bool>&visited, vector<int>&children, vector<int>&discovery, vector<int>&LowLink, vector<bool>&ArticulationPts){
    visited[start] = true;
    stack[start] = true;
    discovery[start] = time;
    LowLink[start] = time;
    time++;

    for(int ngbr:gmap[start]){
        if(ngbr!=parent[start] && !visited[ngbr]){
            children[start]+=1;
            parent[ngbr] = start;
            helper(ngbr, gmap, parent, stack, visited, children, discovery, LowLink, ArticulationPts);
            LowLink[start] = min(LowLink[start], LowLink[ngbr]);
        }
        else if(ngbr == parent[start]){
            continue;
        }
        else if(stack[ngbr]) {
            LowLink[start] = min(LowLink[start], discovery[ngbr]);
        }

        if(parent[start] == -1 && children[start]>1){
            ArticulationPts[start] = true;
        }
        else if(parent[start] != -1 && children[start]>1){
            ArticulationPts[start] = true;
        }
        else if(parent[start] != -1 && LowLink[start]>=discovery[start] && children[start]==1){
            ArticulationPts[start] = true;
        }
    }

    stack[start] = false;
}

vector<bool> ArticulationPoints(int n, vector<vector<int>>&Connections){
    unordered_map<int, vector<int>>gmap;
    for(int i=0; i<Connections.size(); i++){
        gmap[Connections[i][0]].push_back(Connections[i][1]);
        gmap[Connections[i][1]].push_back(Connections[i][0]);
    }

    for(auto i:gmap){
        cout<< i.first <<"=>" << i.second.size()<<endl;
    }
    vector<int>parent(n, -1);
    vector<bool>stack(n, false);
    vector<bool>visited(n, false);
    vector<int>children(n, 0);
    vector<int>discovery(n, -1);
    vector<int>LowLink(n, -1);
    vector<bool>ArticulationPts(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            time = 0;
            helper(i, gmap, parent, stack, visited, children, discovery, LowLink, ArticulationPts);
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " Discovery:" << discovery[i] << " Low:" << LowLink[i] << " Parent:" << parent[i] << " Children:" << children[i] << " Articulation:" 
        << ArticulationPts[i] << endl;
    }

    return ArticulationPts;
}

int main(){
    int n, edges;
    cin >> n >> edges;
    vector<vector<int>>Connections(edges, vector<int>(2));
    for(int i = 0; i < edges ; i++){
        cin >> Connections[i][0] >> Connections[i][1];
    }
    vector<bool>result = ArticulationPoints(n, Connections);
    for(int i = 0 ; i<result.size() ; i++){
        if(result[i]) cout << i << "    ";
    }

    return 0;
}