#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    unordered_map<char, bool>visited;
    unordered_map<int, int>mymap;
    vector<int>uniquechar(str.length());
    for(int i=0;i<str.length();i++){
        if(!visited[str[i]]){
            visited[str[i]]=true;
            
        }
        mymap[visited.size()]=i;
        uniquechar[i]= visited.size();
    }
    int currlen=0;
    int maxlen=0;
    int i=0, j=0;
    int tunique=0;
    for(;i<str.length();i++){
        if(tunique<=k){
            if(j==0)
                tunique = uniquechar[i];
            else{
                tunique = uniquechar[i] - uniquechar[j];
            }
        }
        if(tunique>k){
            for(;j<=i && tunique>k;j++){
                int currlen=i-j;
                maxlen =  max(currlen, maxlen);
                if(j< mymap[uniquechar[j]]){
                    continue;
                }
                tunique = tunique- uniquechar[j];
            }
        }
    }
    cout<<maxlen<<endl;
}