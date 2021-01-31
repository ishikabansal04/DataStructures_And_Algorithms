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
    int maxlength=0;
    int currlength=0;
    int zeroes=0, ones=0, twos=0;
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
        pair<int, int>zeropair(0, 0);
        if(mymap.count(newpair)>0){
            currlength=i-mymap[newpair];
            maxlength = max(maxlength, currlength);
        }
        else if(newpair == zeropair){
            currlength= i+1;
            maxlength = max(maxlength, currlength);
        }
        else{
            mymap[newpair]=i;
        }
    }
    cout<<maxlength;
    return 0;
}