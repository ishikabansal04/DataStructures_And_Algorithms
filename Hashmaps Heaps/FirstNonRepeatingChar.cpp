#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;

int main(){
    string str;
    cin>>str;
    // cout<<str[872]<<str[932]<<endl;
    int count=0;
    unordered_map<char, int>mymap;
    char res='\0';
    int idx=-1;
    for(int i=0;i<str.length();i++){
        if(mymap.count(str[i]) == 0){
            mymap[str[i]]=i;
        }
        else{
            mymap[str[i]]= -10;
        }
    }

    cout<<count<<endl;
    for(auto i:mymap){
        if( idx==-1 || (i.second <idx && i.second!=-10)){
            idx=i.second;
            res=i.first;
        }
    }
    cout<<idx<<endl;
}