#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int tunique=0;
    unordered_map<int, int>visited;
    unordered_map<int, int>mymap;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(visited.count(arr[i])>0){
            continue;
        }
        else{
            visited[arr[i]]=1;
            tunique+=1;
        }
    }
    int i=0, j=0, count=0;

    for(;i<n;i++){
        if(mymap.size()< tunique){
            mymap[arr[i]]+=1;
        }
        if(mymap.size() ==  tunique){
            // count += n-i-1;
            for(;j<=i && mymap.size() == tunique;j++){
                count+=n-i;
                mymap[arr[j]]-=1;
                if(mymap[arr[j]] == 0){
                    mymap.erase(arr[j]);
                }
            }
        }
    }
    cout<< count;
}