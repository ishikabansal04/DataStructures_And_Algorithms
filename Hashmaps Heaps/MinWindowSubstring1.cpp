#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    unordered_map<char, int>mymap;
    unordered_map<char, int>visited;
    for(int i=0;i<str2.length();i++){
        mymap[str2[i]]+=1;
    }
    int i=0, j=0;
    int match_count=0;
    int minlen=INT_MAX;
    string res="";
    int currlen=0;
    for(;i<str1.length();i++){
        if(mymap.count(str1[i]) > 0 && visited[str1[i]]<mymap[str1[i]]){
            match_count+=1;
        }
        visited[str1[i]]+=1;
        // cout<<match_count<<endl;
        if(match_count==str2.length()){
            for(;j<=i && match_count==str2.length();j++){

                currlen=i-j;
                if(minlen>currlen){
                    minlen=currlen;
                    string temp=str1;
                    res=temp.substr(j, i-j+1);
                }
                visited[str1[j]]-=1;
                if(visited[str1[j]]<mymap[str1[j]]){
                    match_count-=1;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}