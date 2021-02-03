#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    unordered_map<char, int>mymap;
    unordered_map<int, int>vis;
    vector<int>currunique(str.length());
    for(int i=0;i<str.length();i++){
        mymap[str[i]]+=1;
        currunique[i] = mymap.size();
        // if(vis.count(currunique[i])>0){
        //     continue;
        // }
        // else{
            vis[currunique[i]]=i;
        // }
    }
    int currlen=0, maxlen=0;
    vis[0]=-1;
    for(int i=0;i<str.length();i++){
        if(vis.count(currunique[i] - k)>0){
            currlen= i- vis[currunique[i]-k];
            maxlen= max(currlen, maxlen);
        }
    }
    cout<<maxlen<<endl;
}