#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int currbest=0;
    int best=INT_MIN;
    for(int i=0;i<n;i++){
        int sum = currbest + arr[i];
        if(arr[i] > sum){
            currbest=arr[i];
        }
        else{
            currbest=sum;
        }
     
        best=max(best, currbest);
       
    }
    cout<<best<<endl;
}