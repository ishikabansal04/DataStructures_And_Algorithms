#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    else{
        return 2;
    }
}

bool isoperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return true;
    }
    else return false;
}

int operation(int a, int b, char op){
    if(op=='+'){
        return a+b;
    }
    else if(op=='-'){{
        return a-b;
    }}
    else if(op=='*'){
        return a*b;
    }
    else if(op=='/'){
        return a/b;
    }
}
int main(){
    string exp;
    getline(cin,exp);
    stack<char>opstk;
    stack<int>numstk;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        
        if(ch=='('){
            opstk.push(ch);
        }
        else if(ch==')'){
            while(opstk.top()!='('){
                int b=numstk.top();
                numstk.pop();
                int a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation(a,b,op));
            }
            if(opstk.top()=='('){
                opstk.pop();
            }
        }
        else if(!isoperator(ch) && ch!='(' && ch!=')' && ch!=' '){
            numstk.push(ch-'0');
        }
        else if(isoperator(ch)){
            while(opstk.size()>0 && opstk.top()!='(' && precedence(opstk.top())>=precedence(ch)){
                int b=numstk.top();
                numstk.pop();
                int a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation(a,b,op));
            }        
            opstk.push(ch);
        }
    }
    while(opstk.size()!=0){
        int b=numstk.top();
        numstk.pop();
        int a=numstk.top();
        numstk.pop();
        char op=opstk.top();
        opstk.pop();
        numstk.push(operation(a,b,op));
    }
    
    cout<<numstk.top()<<endl;
    return 0;
}