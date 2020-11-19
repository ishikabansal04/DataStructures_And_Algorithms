#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    bool res=true;
    stack<char>stk;
    for(int i=0;i<str.length();i++){

      
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            stk.push(str[i]);
        }
        else if(str[i]==')') {
            if(!stk.size() || stk.top()!='('){
                res=false; 
                break;
            }
            else if(stk.top()=='('){
                stk.pop();
            }

        }
        else if(str[i]==']') {
            if(!stk.size() || stk.top()!='['){
                res=false; 
                break;
            }
            else if(stk.top()=='['){
                stk.pop();
            }
        }
        else if(str[i]=='}') {
            if(!stk.size() || stk.top()!='{'){
                res=false; 
                break;
            }
            else if(stk.top()=='{'){
                stk.pop();
            }
        }
    }
    if(stk.size()!=0){
        res=false;
    }
    cout<<boolalpha<<res<<endl;
}