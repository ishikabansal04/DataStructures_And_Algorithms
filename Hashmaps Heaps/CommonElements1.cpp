#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n1,n2;
    
    unordered_map<int, int>mymap1;
    unordered_map<int, int>mymap2;
    cin>>n1;
    vector<int>arr1(n1);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
        mymap1[arr1[i]]+=1;
    }
    cin>>n2;
    vector<int>arr2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
        mymap2[arr2[i]]+=1;
    }
    unordered_map<int, bool>vis;
    for(int i=0;i<n2;i++){
        if(mymap1.count(arr2[i])>0){
            if(vis.count(arr2[i])>0){
                continue;
            }
            else{
                cout<<arr2[i]<<endl;
                vis[arr2[i]]=true;
            }
        }
    }
    return 0;
}