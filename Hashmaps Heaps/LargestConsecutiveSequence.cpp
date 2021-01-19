#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;
/*method 1: less optimised*/

/*
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
*/

int main(){
    int n;
    cin>>n;
    unordered_map<int, bool>mymap;
    unordered_map<int, bool>start;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        mymap[val]=true;
        if(start.count(val)==0){
            start[val]=i;
        }
    }

    for(auto i:mymap){
        if(mymap.count(i.first-1)>0){
            mymap[i.first]=false;
        }
    }
    int maxlen=INT_MIN;
    int src=-1;
    unordered_map<int, bool>::iterator it=mymap.begin();
    while(it!=mymap.end()){
        if(it->second==true){
            int currsrc=it->first;
            int currlen=1;
            int next=currsrc+1;
            while(mymap.count(next)>0){
                currlen+=1;
                next=next+1;
            }
            if(currlen>maxlen){
                maxlen=currlen;
                src=currsrc;
            }
            else if(currlen==maxlen){
                if(start[currsrc] <start[src]){
                    src=currsrc;
                }
            }
        }
        it++;
    }
    for(int i=src,j=0;j<maxlen;j++,i++){
        cout<<i<<endl;
    }
}
