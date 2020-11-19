#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    int size;
    cin>>size;
    vector<int>* stk=new vector<int>(size);
    int top=0;
    string str;
    do{
        cin>>str;
        if(str=="push"){
            int val;
            cin>>val;
            if(top==size){
                vector<int>* newstk=new vector<int>(size);
                for(int i=0;i<size;i++){
                    newstk->at(i)=stk->at(i);
                }
                stk= new vector<int>(size*2);
                for(int i=0;i<size;i++){
                    stk->at(i)=newstk->at(i);
                }
                size=size*2;
                stk->at(top)=val;
                top++;
            }
            else{
                // (*stk).at(top)=val;
                // OR
                stk->at(top)=val;
                top++;
            }
        }
        else if(str=="pop"){
            if(top==0){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<stk->at(top-1)<<endl;
                stk->at(top-1)=-1;
                top--;
            }
            
        }
        else if(str=="display"){
            for(int i=top-1;i>=0;i--){
                cout<<stk->at(i)<<" ";
            }
            cout<<endl;
        }
        else if(str=="top"){
            if(top==0){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<stk->at(top-1)<<endl;
            }
            
        }
        else if(str=="size"){
            cout<<top<<endl;
        }
    }while(str!="quit");
    return 0;
}