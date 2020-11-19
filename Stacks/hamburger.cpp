#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<long>leftsmallest(vector<long>&inp){
    vector<long>lsmall(inp.size());
    stack<long>stk;
    lsmall[0]=0;
    stk.push(0);
    for(int i=1;i<inp.size();i++){
        while(stk.size()!=0 && inp[stk.top()]>=inp[i]){
            stk.pop();
        }
        if(stk.size()==0){
            lsmall[i]=0;
        }
        else if(inp[stk.top()]<inp[i]){
            lsmall[i]=stk.top()+1;
        }
        stk.push(i);
    }
    return lsmall;
}


vector<long>rightsmallest(vector<long>&inp){
    vector<long>rsmall(inp.size());
    stack<long>stk;
    rsmall[inp.size()-1]=inp.size()-1;
    stk.push(inp.size()-1);
    for(int i=inp.size()-2;i>=0;i--){
        while(stk.size()!=0 && inp[stk.top()]>=inp[i]){
            stk.pop();
        }
        if(stk.size()==0){
            rsmall[i]=inp.size()-1;
        }
        else if(inp[stk.top()]<inp[i]){
            rsmall[i]=stk.top()-1;
        }
        stk.push(i);
    }
    return rsmall;
}


int main(){
    long tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        unsigned long n;
        cin>>n;
        vector<long>inp(n);
        for(long i=0;i<n;i++){
            cin>>inp[i];
            cout<<inp[i];
        }
        vector<long>lsmall= leftsmallest(inp);
        vector<long>rsmall= rightsmallest(inp);
        
        long maxarea=LONG_MIN;
        for(int i=0;i<n;i++){
            cout<<inp[i]<<endl;
            // cout<<ht<<endl;
            int width=rsmall[i]-lsmall[i]+1;
        
            // long currarea=ht*width;
            // maxarea=max(maxarea, currarea);
            // cout<<currarea<<endl;

            // if(maxarea<currarea){
            //     maxarea=currarea;
            // }
        }
        // cout<<maxarea<<endl;
    }
    return 0;
}

// 1000000000000