#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int, int>mymap;
    int sum=0;

    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        sum=sum+val;
        arr[i]=sum;
    }
    int k;
    cin>>k;
    int count=0;
    for(int i=0;i<n;i++){
        if(mymap.count(arr[i])>0 && arr[i]!=k){
            mymap[arr[i]]+=1;
            continue;
        }
        else if(mymap.count(k-arr[i])>0){
            count+=mymap[k-arr[i]];
            mymap[k-arr[i]]+=1;
        }
        else if(mymap.count(arr[i]-k)>0){
            count+=mymap[arr[i]-k];
            mymap[arr[i]-k]+=1;
        }
        else if(arr[i]==k){
            count+=1;
            // mymap[arr[i]]+=1;
        }
        mymap[arr[i]]+=1;
    }
    cout<<count<<endl;
}