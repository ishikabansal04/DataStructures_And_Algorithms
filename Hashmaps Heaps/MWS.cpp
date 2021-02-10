#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<climits>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    unordered_map<char, int>map2;
    unordered_map<char, int>map1;
    for(int i=0;i<str2.size();i++){
        map2[str2[i]]+=1;
    }
    int match_count=0, i=0, j=-1;
    int maxlen=INT_MAX, currlen=0, startidx=-1;

    for(int i=0;i<str1.length();i++){
        map1[str1[i]]+=1;
        if(map1[str1[i]]<=map2[str1[i]]){
            match_count++;
        }

        if(match_count == str2.length()){
            for(;j<i && match_count==str2.length();){
                    currlen = i-j;
                    if(maxlen>currlen){
                        maxlen=currlen;
                        startidx = j+1;
                    }
                    j++;
                if(map1[str1[j]]>map2[str1[j]]){
                    map1[str1[j]]-=1;
                    
                }
                else{
                    map1[str1[j]]-=1;
                    match_count--;
                }
            }
        }
    }
    if(maxlen!=INT_MAX)
        cout<<str1.substr(startidx, maxlen);
    
}