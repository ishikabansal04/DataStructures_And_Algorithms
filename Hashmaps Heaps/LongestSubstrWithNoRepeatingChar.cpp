#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;

int main(){
    string str;
    cin>>str;
    unordered_map<char, int>mymap;
    int i=0, j=0, currlen=0, maxlen=0;
    char Repeatingchar ='\0';
    string res="", temp="";
    for(;i<str.length();i++){
        if(Repeatingchar=='\0'){
            mymap[str[i]]+=1;
            if(mymap[str[i]]>1){
                Repeatingchar = str[i];
            }
            currlen=i-j;
            if(currlen> maxlen){
                maxlen= currlen;
                res= str.substr(j, i-j);
            }
        }
        if(Repeatingchar != '\0'){
            for(;j<=i && Repeatingchar!='\0'; j++){
                currlen=i-j;
                if(currlen> maxlen){
                    maxlen= currlen;
                    res= str.substr(j, i-j);
                }
                mymap[str[j]]-=1;
                if(str[j] == Repeatingchar && mymap[str[j]]<=1){
                    Repeatingchar ='\0';
                }
            }
        }   
    }
    if(Repeatingchar == '\0'){
            currlen=i-j;
            if(currlen> maxlen){
                maxlen= currlen;
                res= str.substr(j, i-j);
            }
        }
    cout<<maxlen<<endl;
}