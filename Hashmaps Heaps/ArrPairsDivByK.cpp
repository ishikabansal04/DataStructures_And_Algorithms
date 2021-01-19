#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    // unordered_map<int, int>frequency;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    unordered_map<int, int>frequency;
	    // int n=arr.size();
	    for(int i=0;i<n;i++){
        frequency[arr[i]%k]+=1;
    }

    bool res=true;
    unordered_map<int, int>::iterator it=frequency.begin();
    for(; it!=frequency.end() ;){
         int r1=it->first;
         cout<<r1<<"  "<<frequency[r1]<<endl;
        frequency[r1]-=1;
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
        
        if(frequency[r1]==0){
           
            frequency.erase(r1);
         
            cout<<frequency.size()<<endl;
        }
        int r2=k-r1;
      
        if(frequency.count(r2)>0){
            
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
        it++;
    }
    
    cout<<boolalpha<<res<<endl;
}