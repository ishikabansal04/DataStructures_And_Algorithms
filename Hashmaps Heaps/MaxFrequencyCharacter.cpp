#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    unordered_map<char, int>mymap;
    char res='/0'; //maxfreq character
    int high=0; //maxfreq
    for(int i=0;i<str.length();i++){
        mymap[str[i]]+=1;
        if(mymap[str[i]]>high){
            high=mymap[str[i]];
            res=str[i];
        }
    }
    cout<<res<<endl;
}