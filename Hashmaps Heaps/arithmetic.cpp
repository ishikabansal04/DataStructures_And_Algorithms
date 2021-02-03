#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int min_ = INT_MAX, max_= INT_MIN;
    unordered_map<int, int>mymap;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        min_= min(min_, arr[i]);
        max_= max(max_, arr[i]);
        mymap[arr[i]]+=1;
    }
    bool res=true;
    if(n==1){
        res=true;
    }
    else{
        int d = (max_ - min_)/(n-1);
    
        for(int i=1; i<=n; i++){
            if(mymap.count(min_ + (i-1)*d)>0){
                continue;
            }
            else{
                res=false;
                break;
            }
        }
    }
    
    cout<<boolalpha<<res<<endl;
}