#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

void GetSubstrings(string ques,unordered_map<string, int>&mymap){
    int n= ques.length();
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++){
            mymap[ques.substr(i, len)]=1;
        }
    }      
}

void getBinary(int n, string &res){
    if(n==0){
        return;
    }
    res= res+ to_string(n%2);
    getBinary(n/2 , res);
}

int main(){
    string str;
    cin>>str;
    unordered_map<string, int>mymap;
    GetSubstrings(str, mymap);
    int n;
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        string binary="";
        getBinary(i, binary);
        if(mymap.count(binary)>0){
            continue;
        }
        else{
            flag = false;
            break;
        }
    }
    cout<<boolalpha<<flag<<endl;
}