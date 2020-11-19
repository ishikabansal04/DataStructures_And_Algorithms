#include<iostream>
#include<utility>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> leftsmallest(vector<int>&inp){
    vector<int>lsmall(inp.size());

    stack<int>stk;
    stk.push(0);
    lsmall[0]=0;
    for(int i=1;i<inp.size();i++){
        while(stk.size() && inp[stk.top()]>=inp[i]){
            stk.pop();
        }
        if(stk.size()==0){
            lsmall[i]=0;
        }
        else{
            lsmall[i]=stk.top()+1;
        }
        stk.push(i);
    }
    return lsmall;
}

vector<int>rightsmallest(vector<int>&inp){
    vector<int>rsmall(inp.size());

    stack<int>stk;
    stk.push(inp.size()-1);
    rsmall[inp.size()-1]=inp.size()-1;
    for(int i=inp.size()-2;i>=0;i--){
        while(stk.size() && inp[stk.top()]>=inp[i]){
            stk.pop();
        }
        if(stk.size()==0){
            rsmall[i]=inp.size()-1;
        }
        else{
            rsmall[i]=stk.top()-1;
        }
        stk.push(i);
    }
    return rsmall;

}


int main(){
    int n;
    cin>>n;
    vector<int>inp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    vector<int>lsmall= leftsmallest(inp);
    vector<int>rsmall= rightsmallest(inp);

    int maxarea=0;
    for(int i=0;i<n;i++){
        int ht=inp[i];
        int width=rsmall[i]-lsmall[i]+1;
        int currarea=ht*width;
        maxarea=max(maxarea, currarea);
    }
    cout<<maxarea<<endl;
        return 0;
}