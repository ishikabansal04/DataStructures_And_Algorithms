#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>arr(m);
    unordered_map<int,int>vis;
    for(int i=0;i<m;i++){
        cin>>arr[i];
        vis[arr[i]]+=1;
    }
    vector<int>s1;
    vector<int>s2;
    int idx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(idx%2==0){
                s1.push_back(i);
            }
            else{
                s2.push_back(i);
            }
             idx++;
        }
    }
    for(int i=0;i< s1.size();i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i< s2.size();i++){
        cout<<s2[i]<<" ";
    }
    cout<<endl;
}