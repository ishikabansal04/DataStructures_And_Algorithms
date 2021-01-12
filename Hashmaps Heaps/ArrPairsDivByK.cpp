#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int, int>frequency;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        frequency[arr[i]%k]+=1;
    }

    bool res=true;
    unordered_map<int, int>::iterator it=frequency.begin();
    for(;frequency.size()!=0 || it!=frequency.end() ;it++){
        int r1=it->first;
        cout<<r1<<" =>"<<frequency[r1]<<"   "<<frequency.size();
        // for(auto i:frequency){
        //     cout<<i.first<<"    "<<frequency[i.first]<<endl;
        // }
        it->second=it->second-1;
        if(frequency[it->first]==0){
            cout<<"Entered r1 "<<r1<<"  "<<frequency[r1]<<"  ";
            frequency.erase(it->first);
            cout<<frequency.size()<<endl;
        }
        int r2=k-r1;
        
        if(frequency.count(r2)>0){
            cout<<"Entered r2 "<<r2<<"  "<<frequency[r2]<<" ";
            frequency[r2]-=1;
            if(frequency[r2]==0){
                frequency.erase(r2);
                cout<<frequency.size()<<endl;
            }            
        }
        else{  
            res=false;
            break;
        }
    }
    cout<<boolalpha<<res<<endl;
}