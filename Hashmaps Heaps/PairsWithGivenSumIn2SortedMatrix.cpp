#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr1(n, vector<int>(n));
    vector<vector<int>>arr2(n, vector<int>(n));
    priority_queue<int, vector<int>, greater<int>>pq1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }
    unordered_map<int, int>mymap;
    int countpairs=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
        }
    }
}