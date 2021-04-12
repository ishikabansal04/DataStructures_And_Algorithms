#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int i=0, j=0, maxsum=INT_MIN, currsum=0;
    for(;i<k; i++){
        currsum+=arr[i];
    }
    maxsum= max(maxsum, currsum);
    for(;i<n; i++){
        maxsum= max(maxsum, currsum);
        int tempsum = currsum+arr[i];
        if(currsum<tempsum){
            currsum = tempsum;
        }
        else if(arr[i] > tempsum){
            currsum = arr[i];
            j=i;
        }
        else{
            for(;(i-j)>=k;j++){
                tempsum = tempsum-arr[j];
                if(tempsum>currsum){
                    currsum= tempsum;
                }
            }
        }
    }
    maxsum= max(maxsum, currsum);
    cout<<maxsum<<endl;
}