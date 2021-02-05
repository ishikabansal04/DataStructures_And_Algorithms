#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<climits>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    unordered_map<char, int>map2;
    unordered_map<char, int>map1;
    for(int i=0;i<str2.size();i++){
        map2[str2[i]]+=1;
    }
    int match_count=0, dmct= str2.length();
    int i=0, j=0;
    string res="";
    bool res=false;
    while(true){
        //acquire
        for(;i<str2.size() && match_count<=dmct; i++){
            if(map1[str1[i]<= map2[str1[i]]]){
                match_count+=1;
                map1[str1[i]]+=1;
            }
            res=true;
        }

        //release
        for(;j<=i && match_count == dmct ; j++){
            
        }

        if(!res){
            break;
        }
    }

}