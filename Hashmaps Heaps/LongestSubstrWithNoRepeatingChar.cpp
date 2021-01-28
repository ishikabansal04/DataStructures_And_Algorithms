#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;

int main(){
    string str;
    cin>>str;
    unordered_map<char, int>mymap;
    for(int i=0;i<str.length();i++){
        if(mymap.count(str[i])>0){
            continue;
        }
        else{
            mymap[str[i]]=1;
        }
    }
    unordered_map<char, int>visited;
    int i=0, j=0, match_count=0, currlen=0, maxlen=0;
    string res="";
    for(;i<str.length();i++){
        if(match_count != mymap.size()){
            if(visited[str[i]]<mymap[str[i]]){
                match_count+=1;
            }
            visited[str[i]]+=1;
        }
        if(match_count == mymap.size()){
            for(;j<i;j++){
                if(visited[str[j]]>mymap[str[j]]){
                    visited[str[j]]-=1;
                }
                
            }
        }
    }
}