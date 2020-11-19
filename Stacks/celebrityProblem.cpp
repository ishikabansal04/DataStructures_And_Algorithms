#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int>stk;
    vector<string>inp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
        stk.push(i);
    }
    bool flag=false;
    while(stk.size()>1){
        int r1=stk.top();
        stk.pop();
        int r2=stk.top();
        stk.pop();   

        if(inp[r1][r2]=='0'){
            if(inp[r2][r1]=='1'){
                stk.push(r1);
            }
            else if(inp[r2][r1]=='0'){
                flag=true;
                break;
            }
        }
        else if(inp[r2][r1]=='0'){
            if(inp[r1][r2]=='1'){
                stk.push(r2);
            }
            else if(inp[r1][r2]=='0'){
                flag=true;
                break;
            }
        }
    }
    int rn;
    if(stk.size()==1){
        rn=stk.top();
        stk.pop();
    }

    for(int j=0;j<inp[rn].size();j++){
        if(inp[j][rn]=='0'){
            flag=true;
            break;
        }
        else{
            continue;
        }
    }
    if(stk.size()==0 || flag){
        cout<<"none"<<endl;
    }
    else{
        cout<<stk.top()<<endl;
    }

    stack<string>stk;
    
return 0;
}


// 0111
// 1010
// 0000
// 1110


//    0 1 2 3 
// 0  0 1 0 1
// 1  0 0 0 0
// 2  1 1 0 0
// 3  0 0 1 0