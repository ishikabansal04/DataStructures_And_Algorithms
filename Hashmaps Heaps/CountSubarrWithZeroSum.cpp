#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int, vector<int>>mymap;
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(mymap.count(sum)>0){
            count=count+mymap[sum].size();
        }
        mymap[sum].push_back(i);
    }
    cout<<count<<endl;
    return 0;
}