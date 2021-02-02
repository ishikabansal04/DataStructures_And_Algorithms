#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    string str1, str2;
    cin>>str1>>str2;
    bool flag=true;
    unordered_map<char, int>src;
    unordered_map<char, int>dest;
    if(str1.length()!=str2.length()){
        flag=false;
    }
    else{
        for(int i=0;i<str1.length();i++){
            src[str1[i]]+=1;
            dest[str2[i]]+=1;
        }
        for(auto s: src){
            if(dest[s.first]!=s.second){
                flag=false;
                break;
            }
        }
    }
    cout<<boolalpha<<flag<<endl;
}
