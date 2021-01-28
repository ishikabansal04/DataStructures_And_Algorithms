#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    string str1;
    cin>>str1;
    int n=str1.length();
    bool flag=true;
    unordered_map<string, char>mymap;
    vector<int>visited(26, false);
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(mymap.count(str)>0){
            if(str1[i]==mymap[str]){
                continue;
            }
            else {
                flag=false;
            }
        }
        else if(visited[str1[i]-'a']){
            flag=false;
        }
        else{
            mymap[str]=str1[i];
        }
    }
    cout<<boolalpha<<flag<<endl;
}