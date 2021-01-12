#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

void getPath(unordered_map<string, vector<string>>&mymap, vector<string>&path, string city){
    if(mymap.find(city)==mymap.end()){
        path.push_back(city);
        return;
    }
    path.push_back(city);
    for(string neighbour:mymap[city]){
        getPath(mymap, path, neighbour);
    }
}

int main(){
    int n;
    cin>>n;
    unordered_map<string, vector<string>>mymap;
    unordered_map<string, bool>visited;
    string head;
    for(int i=0;i<n;i++){
        string s1, s2;
        cin>>s1>>s2;
            mymap[s1].push_back(s2);
            if(visited.find(s1)==visited.end()){
                visited[s1]=true;
            }
            visited[s2]=false;
    }
    for(auto i:visited){
        if(i.second==true)
            head =i.first;
    }
    vector<string>path;

    getPath(mymap, path, head);
    for(int i=0;i<path.size()-1;i++){
        cout<<path[i]<<" -> ";
    } 
    cout<<path[path.size()-1]<<".";

return 0;
}