#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<climits>
#include<string>
using namespace std;

int main(){
    string str1;
    cin>>str1;
    string str2="";
    unordered_map<char, int>mymap;
    for(int i=0;i<str1.size();i++){
        if(mymap.count(str1[i])==0){
            str2+=str1[i];
            mymap[str1[i]]+=1;
        }
    }
  
    unordered_map<char, int>visited;
    int minlen= INT_MAX;
    string res="";
    int currlen=0, j=0, match_count=0;
    // string currstr="";
    for(int i=0;i<str1.length();i++){
        // cout<<match_count<<"    "<<str1[i]<<endl;
        if(visited[str1[i]]< mymap[str1[i]]){
            match_count+=1;
            // 
        }
        visited[str1[i]]+=1;
        if(match_count==str2.size()){
            for(;j<i;j++){
                // cout<<j<<"     "<<str1[j]<<"     "<<visited[str1[j]]<<endl;
                if(visited[str1[j]]>mymap[str1[j]]){
                    visited[str1[j]]--;
                    currlen=i-j;
                    if(currlen< minlen){
                        res= str1.substr(j+1, i-j);
                        minlen= currlen;
                    }
                }
                
                else{
                    visited[str1[j]]--;
                    match_count--;
                    j++;
                    // cout<<str1[j]<<visited[str1[j]]<<endl;
                }
                if(match_count<str2.size()){
                    break;
                }
            }
        }
    }
    cout<<res.length()<<endl;
}