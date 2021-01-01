#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int n,k,d;
        cin>>n>>k>>d;
        vector<int>arr(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum=sum+arr[i];
        }

        int days=sum/k;
        if(days>=d){
            cout<<d<<endl;
        }
        else{
            cout<<days<<endl;
        }
    }
    return 0;
}