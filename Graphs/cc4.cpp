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
        int sum1=0;
        int sum2=0;   
        sort(arr.begin(), arr.begin()+m);
        int idx=m-1;
        while(idx>=0 && sum1<k && sum2<k){
            if(count%2==0){
                sum1=sum1+arr[idx];
                idx--;
            }
            else{
                sum2=sum2+arr[idx];
                idx--;
            }
            count++;
            // cout<<sum1<<"       "<<sum2<<endl;
        }
        while(idx>=0 && sum1<k){
            sum1=sum1+arr[idx];
                idx--;
                count++;
                // cout<<sum1<<"       "<<sum2<<endl;
        }
        while(idx>=0 && sum2<k){
            sum2=sum2+arr[idx];
                idx--;
                count++;
                // cout<<sum1<<"       "<<sum2<<endl;
        }
        if(sum1<k || sum2<k){
            cout<<-1<<endl;
        }
        else{
            cout<<count<<endl;
        }


    }
    return 0;
}