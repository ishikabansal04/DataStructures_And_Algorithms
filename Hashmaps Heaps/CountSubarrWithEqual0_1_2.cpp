#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<utility>
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

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<pair<int, int>, int, hash_pair>mymap;
    int sum=0;
    int zeroes=0, ones=0, twos=0;
    int count=0;
    pair<int, int>zeropair(0, 0);
    mymap[zeropair]=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0){
            zeroes+=1;
        }
        else if(arr[i]==1){
            ones+=1;
        }
        else{
            twos+=1;
        }
        pair<int, int>newpair(ones-zeroes, twos-ones);
      
        if(mymap.count(newpair)>0){
            count = count+ mymap[newpair];
        }
        mymap[newpair]+=1;
    }
    cout<<count<<endl;
    return 0;
}