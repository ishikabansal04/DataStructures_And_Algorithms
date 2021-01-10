#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<list>
using namespace std;

#define mp make_pair

int main(){
    int k;
    cin>>k;
    vector<list<int>>inp(k);
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        for(int j=0;j<size;j++){
            int val;
            cin>>val;
            inp[i].push_back(val);
        }
    }
    list<int>output;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    for(int i=0;i<k;i++){
        pq.push(mp(inp[i].front(), i));
        inp[i].pop_front();
    }

    while(pq.size()!=0){
        pair<int, int>top = pq.top();
        pq.pop();
        output.push_back(top.first);
        if(inp[top.second].size()>0){
            pq.push(mp(inp[top.second].front(), top.second));
            inp[top.second].pop_front();
        }
    }


for(auto i:output){
    cout<<i<<" ";
}
return 0;
}