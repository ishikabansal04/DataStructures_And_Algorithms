#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<map>
using namespace std;

int getsizeHelper(unordered_map<string, vector<string>>&tree , map<string, int>&res, string emp){
    if(!tree.count(emp)){
        res[emp]=0;
        return 1;
    }
    for(int j=0;j<tree[emp].size();j++){
            res[emp]+= getsizeHelper(tree, res, tree[emp][j]);
        }
    return res[emp]+1;
}
void getSize(unordered_map<string, vector<string>>&tree , map<string, int>&res, string ceo){
        getsizeHelper(tree, res, ceo);
}
int main(){
    int n;
    cin>>n;
    unordered_map<string, string>inp;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
       
        inp[s1]=s2;
    }
    unordered_map<string, vector<string>>tree;
    string ceo;
    for(auto i:inp){
        string emp=i.first;
        string man=i.second;
        if(emp==man){
            ceo=man;
        }
        else if(tree.count(man)>0){
            tree[man].push_back(emp);
        }
        else{
            tree[man].push_back(emp);
        }
    }

    map<string, int>res;
    getSize(tree, res, ceo);
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}