#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;


int main(){
    string str;
    cin>>str;
    unordered_map<char, int>mymap;
    for(int i=0;i<str.length();i++){
        mymap[str[i]]+=1;
    }
    string res="YES";
    unordered_map<int, int>map2;
    for(auto i:mymap){
        map2[i.second]+=1;
    }
    if(map2.size()>2){
        res="NO";
    }
    else if(map2.size()==2){
        int min_=INT_MAX, key=0;
        for(auto i:map2){
            if(i.second <min_){
                key=i.first;
                min_= i.second;
            }
        }
        if(map2[key]>=2){
            res="NO";
        }

    }
    cout<<res<<endl;
}