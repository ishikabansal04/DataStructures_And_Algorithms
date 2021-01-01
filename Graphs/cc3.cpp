#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int m,n,s1=0,s2=0,count=0;
        cin>>m>>n;
        vector<int>arr1(m);
        vector<int>arr2(n);
        for(int i=0;i<m;i++){
            cin>>arr1[i];
            s1+=arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
            s2+=arr2[i];
        }
        sort(arr2.begin(), arr2.begin()+n);
        sort(arr1.begin(), arr1.begin()+m);
        while(s1<=s2){  
            if(count>=min(m,n)){
                count=-1;
                break;
            }  
            s1=s1+arr2[n-count-1];
            s1=s1-arr1[count];
            s2=s2-arr2[n-count-1];
            s2=s2+arr1[count];
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}