#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int, int>mymap;
    int maxpts=0;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        float slope= y/x;
        if(mymap.count(slope)>0){
            mymap[slope]+=1;
        }
        else{
            mymap[slope]=1;
        }
        maxpts =max(maxpts, mymap[slope]);
    }
    cout<<maxpts<<endl;
}