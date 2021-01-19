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

    // for(auto pair:frequency){
    //     cout<<pair.first<<" "<<pair.second<<endl;
    // }

    bool res=true;
    for(auto pair: frequency){
        int r1=pair.first;
        // cout<<r1<<endl;
        if(r1==0){
            if(frequency[r1]%2==0){
                frequency[r1]-=2;
                if(frequency[r1]==0){
                    frequency.erase(r1);
                }
                continue;
            }
            else{
                res=false;
                break;
            }
        }
        frequency[r1]-=1;
        
        if(frequency[r1]==0){
            frequency.erase(r1);
        }
        int r2=k-r1;
        if(frequency.count(r2)>0){
            frequency[r2]-=1;
            if(frequency[r2]==0){
                frequency.erase(r2);
            }            
        }
        else{  
            res=false;
            break;
        }
    }
    cout<<boolalpha<<res<<endl;
}