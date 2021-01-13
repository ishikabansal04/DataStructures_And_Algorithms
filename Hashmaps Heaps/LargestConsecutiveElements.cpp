#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxLen=INT_MIN;
    for(int i=0;i<n-1;i++){
        unordered_map<int, int>mymap;
        int min_=arr[i];
        int max_=arr[i];
        mymap[arr[i]]=i;
        for(int j=i+1;j<n;j++){
            if(mymap.count(arr[j])>0){
                break;
            }
            min_=min(min_, arr[j]);
            max_=max(max_, arr[j]);
            if((max_-min_)==(j-i)){
                maxLen=max(maxLen, (j-i)+1);
            }
            mymap[arr[j]]=j;
        }
    }
    cout<<maxLen<<endl;
}