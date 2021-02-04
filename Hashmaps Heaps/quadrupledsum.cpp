#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    unordered_map<int, vector<int>>mymap;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            mymap[arr[i] + arr[j]].push_back(arr[i]);
            mymap[arr[i] + arr[j]].push_back(arr[j]);
        }
    }
    for(auto sum:mymap){
        if(mymap.count(x- sum.first)>0){
            cout<< sum.second[0];
        }
    }

}