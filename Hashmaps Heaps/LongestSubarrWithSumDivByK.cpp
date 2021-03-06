#include<iostream>
#include<vector>
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
    int k;
    cin>>k;
    int maxlen=0;
    int currlen=0;
    int sum=0;
    unordered_map<int, int>mymap;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        int temp=sum%k;
        if(temp<0){
            temp =temp+k;
        }
        if(mymap.count(temp)>0){
            currlen=i-mymap[temp];
            maxlen= max(currlen, maxlen);
        }
        else if(temp==0){
            currlen= i+1;
            maxlen= max(currlen, maxlen);
        }
        else{
            mymap[temp]=i;
        }
    } 
    cout<<maxlen<<endl;
    return 0;
}