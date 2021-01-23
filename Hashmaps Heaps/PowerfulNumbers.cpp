#include<iostream>
#include<unordered_map>
#include<vector>
#include<math.h>
#include<queue>
#include<string>
using namespace std;

int main(){
    int a,b,x;
    cin>>a>>b>>x;
    unordered_map<int, int>mymap;
    vector<int> arr;
    for(int i=0;;i++){
        if(pow(a,i)<= x){
            arr.push_back(pow(a, i));
            mymap[pow(a,i)]+=1;
        }
        if(pow(b,i)<= x){
            arr.push_back(pow(b, i));
            mymap[pow(b,i)]+=1;
        }
    }

    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<arr.size();i++){
        
    }
}