// Question
// 1. You are given a string exp representing an expression.
// 2. Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// 3. But, some of the pair of brackets maybe extra/needless. 
// 4. You are required to print true if you detect extra brackets and false otherwise.

// e.g.'
// ((a + b) + (c + d)) -> false
// (a + b) + ((c + d)) -> true



#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int count=0;
    bool res=false;
    stack<char>stk;
    for(int i=0;i<str.length();i++){
        if(str[i]!=')' && str[i]!='}' && str[i]!=']' && str[i]!='(' && str[i]!='{' && str[i]!='['){
            stk.push(str[i]);
            count++;
        }
        else if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            stk.push(str[i]);
        }
        else if(str[i]==')'){
            if(count==0 || stk.top()=='('){
                res=true;
                break;
            }
            else{
                while(stk.top()!='(' && stk.size()){
                    stk.pop();
                    count--;
                }
                if(stk.top()=='('){
                    stk.pop();
                }
                else{
                    res=true;
                    break;
                }
            }
        }
        else if(str[i]=='}'){
            if(count==0 || stk.top()=='{'){
                res=true;
                break;
            }
            else{
                while(stk.top()!='{' && stk.size()){
                    stk.pop();
                    count--;
                }
                if(stk.top()=='{'){
                    stk.pop();
                }
                else{
                    res=true;
                    break;
                }
            }
        }
        else if(str[i]==']'){
            if(count==0 || stk.top()=='['){
                res=true;
                break;
            }
            else{
                while(stk.top()!='[' && stk.size()){
                    stk.pop();
                    count--;
                }
                if(stk.top()=='['){
                    stk.pop();
                }
                else{
                    res=true;
                    break;
                }
            }
        }
        
    }
    cout<<boolalpha<<res<<endl;
}