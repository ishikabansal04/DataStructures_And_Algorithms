#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    string exp;
    cin>>exp;
    stack<int>stk;
    int idx=1;
    for(int i=0;i<exp.size();i++){              
        if(exp[i]=='d'){              
            stk.push(idx);
            idx++;
        }
        else{
            stk.push(idx);
            idx++;
            while(stk.size()){
                cout<<stk.top();  
                stk.pop();
            }
        }
    }
    stk.push(idx);
    while(stk.size()){
        cout<<stk.top();
        stk.pop();
    }
        return 0;
}