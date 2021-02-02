#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    string str1, str2;
    bool res=true;
    cin>>str1>>str2;
    unordered_map<char, char>mymap;
    vector<bool>vis(26);
    for(int i=0;i<str1.length();i++){
        if(mymap.count(str1[i])>0){
            if(mymap[str1[i]]!= str2[i]){
                res=false;
                break;
            }
        }
        else if(vis[str2[i]-'a']){
            res=false;
            break;
        }
        else{
            mymap[str1[i]]=str2[i];
            vis[str2[i]-'a']=true;
        }
    }

    for(auto i:mymap){
        cout<<i.first<<"    "<<i.second<<endl;
    }
    cout<<boolalpha<<res;
}