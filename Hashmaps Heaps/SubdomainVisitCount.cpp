#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<string, int>mymap;
    for(int i=0;i<n;i++){
        int num;
        string str;
        cin>>num>>str;
        string temp="";
        for(int j=0;j<str.length();j++){
            if(str[j]!='.'){
                temp= temp+str[j];
            }
            else{
                
            }
        }
    }
}