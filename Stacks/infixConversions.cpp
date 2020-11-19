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

string operation(string a, string b, char op){
    string res="";
    res=res+a+b;
    if(op=='+'){
        res= '+' +res;
        // return "+"+res;
    }
    else if(op=='-'){
        res= '-' +res;
        // return "-"+res;
    }
    else if(op=='*'){
        res= '*' +res;
        // return "*"+res;
    }
    else if(op=='/'){
        res= '/' +res;
        // return "/"+res;
    }
    return res;
}



string operation2(string a, string b, char op){
    string res="";
    res=res+a+b;
    if(op=='+'){
        res= res + '+';
        // return "+"+res;
    }
    else if(op=='-'){
        res= res + '-';
        // return "-"+res;
    }
    else if(op=='*'){
        res= res + '*';
        // return "*"+res;
    }
    else if(op=='/'){
        res= res + '/';
        // return "/"+res;
    }
    return res;
}


string infixToprefix(string exp){
    stack<string>numstk;
    stack<char>opstk;

    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        
        if(ch=='('){
            opstk.push(ch);
        }
        else if(ch==')'){
            while(opstk.top()!='('){
                string b=numstk.top();
                numstk.pop();
                string a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation(a,b,op));
            }
            if(opstk.top()=='('){
                opstk.pop();
            }
        }    
        else if(isoperator(ch)){
            while(opstk.size()>0 && opstk.top()!='(' && precedence(opstk.top())>=precedence(ch)){
                string b=numstk.top();
                numstk.pop();
                string a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation(a,b,op));
            }        
            opstk.push(ch);
        }
        else{
            string res="";
            res=res+ch;
            numstk.push(res);
        }
    }
    while(opstk.size()!=0){
        string b=numstk.top();
        numstk.pop();
        string a=numstk.top();
        numstk.pop();
        char op=opstk.top();
        opstk.pop();
        numstk.push(operation(a,b,op));
    }
    
    return numstk.top();
}


string infixTopostfix(string exp){
    stack<string>numstk;
    stack<char>opstk;

    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        
        if(ch=='('){
            opstk.push(ch);
        }
        else if(ch==')'){
            while(opstk.top()!='('){
                string b=numstk.top();
                numstk.pop();
                string a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation2(a,b,op));
            }
            if(opstk.top()=='('){
                opstk.pop();
            }
        }    
        else if(isoperator(ch)){
            while(opstk.size()>0 && opstk.top()!='(' && precedence(opstk.top())>=precedence(ch)){
                string b=numstk.top();
                numstk.pop();
                string a=numstk.top();
                numstk.pop();
                char op=opstk.top();
                opstk.pop();
                numstk.push(operation2(a,b,op));
            }        
            opstk.push(ch);
        }
        else{
            string res="";
            res=res+ch;
            numstk.push(res);
        }
    }
    while(opstk.size()!=0){
        string b=numstk.top();
        numstk.pop();
        string a=numstk.top();
        numstk.pop();
        char op=opstk.top();
        opstk.pop();
        numstk.push(operation2(a,b,op));
    }   
    return numstk.top();
}


int main(){

    string exp;
    cin>>exp;


    cout<<infixTopostfix(exp)<<endl;
    cout<<infixToprefix(exp);
    
    return 0;
}