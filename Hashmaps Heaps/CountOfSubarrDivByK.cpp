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
    int count=0;
    int currlen=0;
    int sum=0;

    unordered_map<int, int>mymap;
    mymap[0] =1;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        int temp=sum%k;
        if(temp<0){
            temp =temp+k;
        }
        if(mymap.count(temp)>0){
            count+=mymap[temp];
        }
        mymap[temp]+=1;
    }
    cout<<count<<endl;
}