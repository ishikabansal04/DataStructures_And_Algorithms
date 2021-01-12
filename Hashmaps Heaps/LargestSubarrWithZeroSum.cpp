#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int, int>mymap;
    int maxlength=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(mymap.count(sum)>0){
            int length=i-mymap[sum];
            maxlength=max(maxlength, length);
        }
        else{
            mymap[sum]=i;
        }
    }
    if(maxlength==INT_MIN){
        cout<<0<<endl;
    }
    else{
        cout<<maxlength<<endl;
    }
}