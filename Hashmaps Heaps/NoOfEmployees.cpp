#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<utility>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<pair<string, string>, vector<pair<string, string>>, greater<pair<string, string>> >pq;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        pq.push(make_pair(s2, s1));
    }
    vector<int>arr(n, 0);
    while(pq.size()!=0){
        pair<string, string> top=pq.top();
        pq.pop();
        arr[top.first[0]-'A']+=1;
        arr[top.first[0]-'A']+=arr[top.second[0]-'A'];
    }
    char ch='A';
    for(int i=0;i<n;i++){
        cout<<ch<<" "<<arr[i]<<endl;
        ch=ch+1;
    }
    return 0;
}