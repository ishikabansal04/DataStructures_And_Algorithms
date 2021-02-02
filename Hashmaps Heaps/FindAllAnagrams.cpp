#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

bool check(unordered_map<char, int>&src, unordered_map<char, int>&dest){
    for(auto s: src){
        if(dest[s.first]!= s.second){
            return false;
        }
    }
    return true;
}
int main(){
    string str1,str2;
    cin>>str1>>str2;
    unordered_map<char, int>src;
    unordered_map<char, int>dest;
    vector<int>idx;
    int i=0;
    for(i=0;i<str2.length();i++){
        dest[str2[i]]+=1;
        src[str1[i]]+=1;
    }
    int j=0, count=0;
    for(;i<str1.length();i++){
        bool compare= check(src, dest);
        if(compare){
            count+=1;
            idx.push_back(j);
        }
        src[str1[j]]-=1;
        src[str1[i]]+=1;
        j++;
    }
    bool compare= check(src, dest);
        if(compare){
            count+=1;
            idx.push_back(j);
        }
   cout<<count<<endl;
   for(int k:idx){
       cout<<k<<" ";
   }
}