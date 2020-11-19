#include<iostream>
#include<stack>
#include<string>
using namespace std;


int operation(int a, int b, char op){
    if(op=='+'){
        return a+b;
    }
    else if(op=='-'){
        return a-b;
    }
    else if(op=='*'){
        return a*b;
    }
    else if(op=='/'){
        return a/b;
    }
}

int prefixEvaluation(string exp){
    stack<int>numstk;
    for(int i=exp.length()-1;i>=0;i--){
        if(exp[i]-'0' <=9 && exp[i]-'0' >=1){
            numstk.push(exp[i]-'0');
        }
        else{
            int a=numstk.top();
            numstk.pop();
            int b=numstk.top();
            numstk.pop();
            numstk.push(operation(a, b, exp[i]));
        }
    }
    return numstk.top();
}




string operation2(string a, string b, char op){
    string res="";
    if(op=='+'){
        res=res+'(' + a+ '+' + b +')';
    }
    else if(op=='-'){
        res=res+'(' + a+ '-' + b +')';
    }
    else if(op=='*'){
        res=res+'(' + a+ '*' + b +')';
    }
    else if(op=='/'){
        res=res+'(' + a+ '/' + b +')';
    }
    return res;
}

string prefixToInfix(string exp){
    stack<string>numstk;
    for(int i=exp.length()-1;i>=0;i--){
        if(exp[i]-'0' <=9 && exp[i]-'0' >=1){
            string res="";
            res=res+exp[i];
            numstk.push(res);
        }
        else{
            string a=numstk.top();
            numstk.pop();
            string b=numstk.top();
            numstk.pop();
            numstk.push(operation2(a, b, exp[i]));
        }
    }
    return numstk.top();
}






string operation3(string a, string b, char op){
    string res="";
    if(op=='+'){
        res=res+ a+ b +'+';
    }
    else if(op=='-'){
        res=res+ a+ b +'-';
    }
    else if(op=='*'){
        res=res+ a+ b +'*';
    }
    else if(op=='/'){
        res=res+ a+ b +'/';
    }
    return res;
}

string prefixToPostfix(string exp){
    stack<string>numstk;
    for(int i=exp.length()-1;i>=0;i--){
        if(exp[i]-'0' <=9 && exp[i]-'0' >=1){
            string res="";
            res=res+exp[i];
            numstk.push(res);
        }
        else{
            string a=numstk.top();
            numstk.pop();
            string b=numstk.top();
            numstk.pop();
            numstk.push(operation3(a, b, exp[i]));
        }
    }
    return numstk.top();
}


int main(){
    string exp;
    cin>>exp;

    cout<<prefixEvaluation(exp)<<endl;
    cout<<prefixToInfix(exp)<<endl;
    cout<<prefixToPostfix(exp)<<endl;
    return 0;
}