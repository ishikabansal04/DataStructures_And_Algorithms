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
    int count=0;
    int sum=0;
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
    mymap[0]=1;
    for(int i=0;i<n;i++){
        if(mymap.count(arr[i])>0){
            count+=mymap[arr[i]];
        }
        
        mymap[arr[i]]+=1;
    }
    cout<<count<<endl;
}