#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int m,k,count=0;
        cin>>m>>k;
        vector<int>arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        int sum2=2*k;   
        sort(arr.begin(), arr.begin()+m);
        for(int i=m-1;i>=0;i--){
            sum2=sum2-arr[i];
            count++;
            if(sum2<0){
                break;
            }
        }
        if(sum2>0){
            count=-1;
        }
        cout<<count<<endl;
    }
    return 0;
}