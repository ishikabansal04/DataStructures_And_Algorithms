#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
    
    int binary(int left, int right, vector<int>&dp, int key){
            if(left>=right){
                return left;
            }
            if(left<right){
                int mid= (left+right)/2;
                if(dp[mid]<key){
                    left= mid+1;
                }
                else{
                    right=mid;
                }
            }
            return binary(left, right, dp, key);
    }
    
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>dp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]>dp[dp.size()-1]){
            dp.push_back(arr[i]);
        }
        else{
            cout<<arr[i]<<"=> ";
            int idx = binary(0, dp.size()-1, dp, arr[i]);
            dp[idx]= arr[i];
        }
    }
    cout<<dp.size()<<endl;
}