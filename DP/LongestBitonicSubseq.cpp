#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>incr(n, 1);
    vector<int>decr(n, 1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    incr[0]=1;
    decr[n-1]=1;
    int maximum=INT_MIN;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j]<=arr[i]){
                incr[i]= max(incr[i],incr[j]+1);
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(arr[j]<=arr[i]){
                decr[i]= max(decr[i], decr[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        maximum= max(maximum, incr[i]+decr[i]-1);
    }
    cout<<maximum<<endl;
}