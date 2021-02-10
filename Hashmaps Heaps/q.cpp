#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Pair{
    public:
    int x,y,z;
};

void Subsequences(string str, string res, int idx, vector<int>arr, unordered_map<string, Pair>&mymap, int n){
    if(str.length()==0){
        if(res.length() ==n){
            sort(arr.begin(), arr.begin()+ arr.size());
            cout<<res<<"=>";
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            Pair mypair;
            mypair.x=arr[0];
            mypair.y=arr[1];
            mypair.z=arr[2];
            mymap[res]=mypair;
        }
        return;
    }
    Subsequences(str.substr(1), res, idx+1, arr, mymap, n);
    arr.push_back(idx);
    Subsequences(str.substr(1), res+str[0], idx+1, arr, mymap, n);
}

void reverse(string & str){
    int n= str.length();
    for(int i=0;i<n/2;i++){
        char a = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = a;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string str;
    cin>>str;
    unordered_map<string, Pair>mymap;
    vector<int>arr;
    int count=0;
    Subsequences(str,"", 0, arr, mymap, str.length()/2);
    for(auto element:mymap){
        // cout<<element.first<<"  ";
        string p= element.first;
        string q= element.first;
        reverse(q);
        // cout<<q<<endl;
        if(mymap.count(q)>0){
            
            vector<bool>visited(6, false);

            visited[mymap[p].x]=true;
            // cout<<mymap[p].x<<" "<<mymap[p].y<<"  "<<mymap[p].z<<endl;
            // cout<<mymap[q].x<<" "<<mymap[q].y<<"  "<<mymap[q].z<<endl;
            visited[mymap[p].y]=true;
            visited[mymap[p].z]=true;
            visited[mymap[q].x]=true;
            visited[mymap[q].y]=true;
            visited[mymap[q].z]=true;
            bool flag=true;
            for(int i=0;i<6;i++){
                if(visited[i]==false){
                    cout<<visited[i]<<i<<endl;
                    flag=false;
                    break;
                }
            }
            if(flag){
                count+=1;
                // cout<<p<<"  "<<q<<endl;
            }
        }
    }
    cout<<count<<endl;;
    return 0;
}