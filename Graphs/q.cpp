#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
  

pair<int, int> POC(int sr, int sc, int k, vector<vector<int>>&dir, int n, int idx, unordered_map<pair<int, int>, bool, hash_pair>corners){
    // cout<<sr<<" "<<sc<<" "<<idx<<endl;
    if(k==0){
        return make_pair(sr, sc);
    }
    pair<int,int>p1(sr, sc);
    if(corners.count(p1)>0){
        return p1;
    }
    int x=sr, y=sc;
    for(int i=0; (sr+i*dir[idx][0])<=n && (sr+i*dir[idx][0])>=0 && (sc+i*dir[idx][1])<=n && (sc+i*dir[idx][1])>=0;i++){
        x=sr+i*dir[idx][0];
        y=sc+i*dir[idx][1];
    }
    idx=idx+1;
    if(idx==3){
        idx=0;
    }
    pair<int, int>smallpair= POC(x, y, k-1, dir, n, idx, corners);
    return smallpair;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int n,k;
        cin>>n>>k;
        int x,y;
        cin>>x>>y;

        unordered_map<pair<int, int>, bool, hash_pair> corners;
        pair<int, int> p1(0, n); 
        pair<int, int> p2(n, 0);  
        pair<int, int> p3(0, 0); 
        pair<int, int> p4(n, n); 

        corners[p1] = true; 
        corners[p2] = true; 
        corners[p3] = true; 
        corners[p4] = true;

        vector<vector<int>>dir={{1,1}, {-1,1},{-1,-1}, {1,-1}};
        pair<int, int> mypair= POC(x, y, k, dir, n, 0, corners);
        cout<<mypair.first<<" "<<mypair.second<<endl;
    }
}