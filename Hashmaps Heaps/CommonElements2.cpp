#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2;
    cin>>n1;
    vector<int>arr1(n1);
    unordered_map<int, int>mymap;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
        mymap[arr1[i]]+=1;
    }
    int n2;
    cin>>n2;
    vector<int>arr2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<n2;i++){
        if(mymap.count(arr2[i])>0){
            cout<<arr2[i]<<endl;
            mymap[arr2[i]]-=1;
            if(mymap[arr2[i]]==0){
                mymap.erase(arr2[i]);
            }
        }
    }
    return 0;
}