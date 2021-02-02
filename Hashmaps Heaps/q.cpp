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
        cout<<"Map1"<<endl;
        for(auto s:src){
           cout<<s.first<<" "<<s.second<<endl;
        }
        cout<<"Map2"<<endl;
        for(auto s:dest){
           cout<<s.first<<" "<<s.second<<endl;
        }
        int freqdiff=0;
        for(auto s:src){
            if(dest[s.first]!=s.second){
                freqdiff+=dest[s.first]- src[s.first];
                cout<<s.first<<"    "<<dest[s.first]- src[s.first]<<endl;
            }
            // vis[s.first]=true;
        }
        if(freqdiff > k){
            flag=false;
        }
    }
    cout<<boolalpha<<flag;
}