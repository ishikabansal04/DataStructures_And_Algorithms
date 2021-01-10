#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(arr[0]);
    int i;
    for(i=1;i<=k;i++){
        pq.push(arr[i]);
    }
    while(pq.size()){
        cout<<pq.top()<<endl;
        pq.pop();
        if(i<arr.size()){
            pq.push(arr[i]);
            i++;
        }
    }
    return 0;
}