#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int, int>mymap;
    bool res=false;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int pairsum= arr[i]+ arr[j];
            if(mymap.count(pairsum)>0){
                res=true;
                break;
            }
            mymap[pairsum]=1;
        }
        if(res){
            break;
        }
    }
    cout<<boolalpha<<res<<endl;
}