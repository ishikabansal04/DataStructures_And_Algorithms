#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class myclass{
    public:
        vector<int>stk;
        vector<int>minstk;
        int top=0;
        

        void push(int data){
            stk.push_back(data);
            top++;
            minstk.push_back(top-1);
            for(int i=top-2;i>=0 && stk[minstk[i]]<data; i--){
                int temp=minstk[i];
                minstk[i]=minstk[i+1];
                minstk[i+1]=temp;
            }
        }

        int pop(){
            if(top==0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int rn=top-1;
            int val=stk[top-1];
            stk.erase(stk.begin()+ top-1);
            for(int i=0;i<top;i++){
                if(minstk[i]==rn){
                    minstk.erase(minstk.begin()+i);
                    break;
                }
            }
            top--;
            return val;
        }

        int min(){
            if(!minstk.size()){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            else{
                return stk[minstk[top-1]];
            }
        }
        int size(){
            return top;
        }

        int peek(){
            if(!stk.size()){
                cout<<"Stack underflow"<<endl;
                return -1;
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