#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int, int>mymap;
    int sum=0;
    int maxlength=0;
    int currlength=0;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val){
            sum=sum+val;
            arr[i]=sum;
        }
        else{
            sum=sum-1;
            arr[i]=sum;
        }
    }
    for(int i=0;i<n;i++){
        
        if(arr[i]==0){
            currlength=i+1;
            maxlength=max(maxlength, currlength);
        }
        else if(mymap.count(arr[i])>0){
            currlength=i-mymap[arr[i]];
            maxlength=max(maxlength, currlength);
        }
        else{
            mymap[arr[i]]=i;
        }
    }
    cout<<maxlength<<endl;
}