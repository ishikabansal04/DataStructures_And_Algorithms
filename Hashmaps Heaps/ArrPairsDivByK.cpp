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
    for(;frequency.size()!=0 || it!=frequency.end() ;){
        auto it1=frequency.find(it->first);
        
        frequency[it->first]-=1;
         int r1=it->first;

         it++;
        if(frequency[r1]==0){
           
            frequency.erase(it1);
            cout<<frequency.size()<<endl;
        }
        int r2=k-r1;
      
        if(frequency.count(r2)>0){
            auto it2=frequency.find(r2);
            frequency[r2]-=1;
            if(frequency[r2]==0){
                frequency.erase(it2);
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