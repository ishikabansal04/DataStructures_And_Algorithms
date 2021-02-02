#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    string str1, str2;
    int k;
    cin>>str1>>str2>>k;
    
    bool flag=true;
    if(str1.length()!=str2.length()){
        flag=false;
    }
    else{
        unordered_map<char, int>src;
        unordered_map<char, int>dest;
        unordered_map<int, int>vis;
        for(int i=0;i<str1.length();i++){
            src[str1[i]]+=1;
            dest[str2[i]]+=1;
        }
        int freqdiff=0;
        for(auto s:src){
            if(dest[s.first]!=s.second){
                if(dest[s.first] > src[s.first])
                freqdiff+=dest[s.first]- src[s.first];
            }
            // vis[s.first]=true;
        }
        if(freqdiff > k){
            flag=false;
        }
    }
    cout<<boolalpha<<flag;
}