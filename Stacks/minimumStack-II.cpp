#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class myclass{
    public:
        vector<int>stk;
        int minelement=0;
        int top=0;

        void push(int data){
           
            if(!stk.size()){
                minelement=data;
                stk.push_back(data);
            }
            else{
                if(data>minelement){
                    stk.push_back(data);
                }
                else{
                    int temp=data+ data-minelement;
                    stk.push_back(temp);
                    minelement=data;
                }
            }
            top++;
        }

        int pop(){
            if(top==0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            // int rn=top-1;
            // int val=stk[top-1];
            // stk.erase(stk.begin()+ top-1);
            int val;
            if(minelement <= stk[top-1]){
                val=stk[top-1];
                stk.erase(stk.begin()+ top-1);
                top--;
            }
            else{
                val=minelement;
                int rn=stk[top-1];
                minelement= ((2*val) -rn);
                stk.erase(stk.begin()+ top-1);
                top--;
            }
            return val;
        }

        int min(){
            return minelement;
        }
        int size(){
            return top;
        }

        int peek(){
            if(!stk.size()){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            else if(stk[top-1]<minelement){
                return minelement;
            }
            else{
                return stk[top-1];
            }
        }
};



int main(){
    myclass obj;
    string str;
    do{
        cin>>str;
        if(str=="push"){
            int val;
            cin>>val;
            obj.push(val);
        }

        else if(str=="pop"){
            cout<<obj.pop()<<endl;
        }

        else if(str=="min"){
            cout<<obj.min()<<endl;
        }

        else if(str=="top"){
            cout<<obj.peek()<<endl;
            
        }

        else if(str=="size"){
            cout<<obj.size()<<endl;
        }

    }while(str!="quit");
    return 0;
}