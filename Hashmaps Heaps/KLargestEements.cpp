#include<iostream>
#include<queue>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        pq.push(val);
    }
    int k;
    cin>>k;
    vector<int>arr;
    while(pq.size()!=0 && k>0){
        arr.push_back(pq.top());
        pq.pop();
        k--;
    }

    for(int i=arr.size()-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
    return 0;
}