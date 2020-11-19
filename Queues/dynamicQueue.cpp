#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    int size;
    cin>>size;
    vector<int>* stk=new vector<int>(size);
    int front=-1;
    int rear=-1;
    string str;
    do{
        cin>>str;
        if(str=="add"){
            int val;
            cin>>val;
            if ((front == 0 && rear == size-1) || ((size!=1)&&(front>=1)&&(rear == (front-1)%(size-1)))) {
                vector<int>* newstk=new vector<int>(size);
                for(int i=0;i<size;i++){
                    newstk->at(i)=stk->at(i);
                }
                stk= new vector<int>(size*2);
                for(int i=0;i<size;i++){
                    stk->at(i)=newstk->at(i);
                }
                size=size*2;
                rear++;
                stk->at(rear)=val;
                
            }
            else if (front == -1){
                front = rear = 0; 
                stk->at(rear) = val;
            }
            else if (rear == size-1 && front != 0) 
                { 
                    rear = 0; 
                    stk->at(rear) = val; 
                } 
            else
                { 
                    rear++; 
                    stk->at(rear) = val; 
                } 
        }
        else if(str=="remove"){
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                int data = stk->at(front); 
                stk->at(front) = -1; 
                if (front == rear) 
                { 
                    front = -1; 
                    rear = -1; 
                } 
                else if (front == size-1) 
                    front = 0; 
                else
                    front++; 
                cout<<data<<endl;
            }
            
        }
        else if(str=="display"){
            if(front==-1){
                cout<<endl;
            }
            else{
                if (rear >= front) 
                { 
                    for (int i = front; i <= rear; i++) 
                        cout<<stk->at(i)<<" "; 
                } 
                else
                { 
                    for (int i = front; i < size; i++) 
                        cout<<stk->at(i)<<" "; 
            
                    for (int i = 0; i <= rear; i++) 
                        cout<<stk->at(i)<<" ";
                }
                cout<<endl;
            }
        }
        else if(str=="peek"){
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                cout<<stk->at(front)<<endl;
            }
            
        }
        else if(str=="size"){
            if(front==-1){
                cout<<0<<endl;
            }
            else if(front<=rear){
                cout<<rear-front+1<<endl;
            }
            else{
                cout<<size-front+rear<<endl;
            }
        }
    }while(str!="quit");
    return 0;
}