#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr1(n);
    vector<int>arr2(n);
    unordered_map<int, vector<int>>mymap;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
        mymap[arr2[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        cout<<mymap[arr1[i]][0]<<" ";
        if(mymap[arr1[i]].size()>1){
            mymap[arr1[i]].erase(mymap[arr1[i]].begin());
        }
    }
}