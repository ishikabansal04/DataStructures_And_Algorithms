#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int tunique=0;
    vector<int>arr(n);
    unordered_map<int, int>unique;
    unordered_map<int, int>visited;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(unique.count(arr[i])>0){
            continue;
        }
        else{
            unique[arr[i]]=1;
        }
    }
    tunique=unique.size();
    int i=0, j=0, match_count=0, count=0;
    for(;i<n;i++){
        if(i<n && match_count<tunique){
            if(visited[arr[i]]<unique[arr[i]]){
                match_count++;
            }
            visited[arr[i]]+=1;
        }
        if(match_count==tunique){
            for(;j<i && match_count==tunique;j++){
                count+=1;
                if(visited[arr[j]]>unique[arr[j]]){
                    visited[arr[j]]-=1;
                }
                else{
                    visited[arr[j]]-=1;
                    match_count-=1;
                }
            }
        }
    }
  
    cout<<count<<endl;
}