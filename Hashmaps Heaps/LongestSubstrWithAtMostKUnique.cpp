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
            uniquechar[i]= visited.size();
        }
    }
    int currlen=0;
    int maxlen=0;
    int i=0, j=0;
    int tunique=0;
    for(;i<str.length();i++){
        if(tunique<=k){
            tunique = uniquechar[i];
        }
        if(tunique>k){
            for(;j<=i && tunique>k;j++){
                int currlen=i-j;
                maxlen =  max(currlen, maxlen);
                tunique = tunique- uniquechar[j];
            }
        }
    }
}