#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int main(){
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>>que;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        que.push(val);
    }

    unordered_map<int, vector<int>>mymap;
    int idx=0;
    int lastele=que.top();
    que.pop();
    mymap[idx].push_back(lastele);
    while(que.size()!=0){
        int rn=que.top();
        que.pop();
        if(rn==lastele+1){
            mymap[idx].push_back(rn);
            lastele=rn;
        }
        else if(rn==lastele){
            continue;
        }
        else{
            idx++;
            mymap[idx].push_back(rn);
            lastele=rn;
        }
    }
    int maxsize=0;
    int count=0;
    for(auto i:mymap){
        if(maxsize<i.second.size()){
            count=i.first;
            maxsize=i.second.size();
        }
    }

    // for(int i=0;i<mymap.size();i++){
    //     for(int j=0;j<mymap[i].size();j++){
    //         cout<<mymap[i][j]<<"    ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<mymap[count].size();i++){
        cout<<mymap[count][i]<<endl;
    }
    return 0;
}