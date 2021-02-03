#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
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
    int i=0,j=0, currlen=0, maxlen=0, currzero=0;
    for(;i<n;i++){
        if(currzero<=k){
            if(arr[i]==1){
                continue;
            }
            else{
                currzero+=1;
            }
        }
        
        if(currzero>k){
            currlen = i-j;
            maxlen= max(maxlen, currlen);
            for(;j<=i && currzero>k;j++){
                if(arr[j]==1){
                    continue;
                }
                else{
                    currzero-=1;
                }
            }
            if(currzero==k){
            currlen = i-j;
            maxlen= max(maxlen, currlen);
        }
        }
    }
    if(currzero<=k){
        currlen = i-j;
        maxlen= max(maxlen, currlen);
    }
    cout<<maxlen<<endl;
}