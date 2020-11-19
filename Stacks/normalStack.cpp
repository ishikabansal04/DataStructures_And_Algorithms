#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    int size;
    cin>>size;
    vector<int>stk(size,-1);
    int top=0;
    string str;
    do{
        cin>>str;
        if(str=="push"){
            int val;
            cin>>val;
            if(top==size){
                cout<<"Stack overflow"<<endl;
            }
            else{
                stk[top]=val;
                top++;
            }
        }
        else if(str=="pop"){
            if(top==0){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<stk[top-1]<<endl;
                stk[top-1]=-1;
                top--;
            }
            
        }
        else if(str=="display"){
            for(int i=top-1;i>=0;i--){
                cout<<stk[i]<<" ";
            }
            cout<<endl;
        }
        else if(str=="top"){
            if(top==0){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<stk[top-1]<<endl;
            }
            
        }
        else if(str=="size"){
            cout<<top<<endl;
        }
    }while(str!="quit");
    return 0;
}