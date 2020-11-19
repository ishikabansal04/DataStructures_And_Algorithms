#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    int size;
    cin>>size;
    vector<int>stk(size,-1);
    int front=-1;
    int rear=-1;
    string str;
    do{
        cin>>str;
        if(str=="add"){
            int val;
            cin>>val;
            if ((front == 0 && rear == size-1) || ((size!=1)&&(front>=1)&&(rear == (front-1)%(size-1)))) {
                cout<<"Queue overflow"<<endl;
            }
            else if (front == -1){
                front = rear = 0; 
                stk[rear] = val;
            }
            else if (rear == size-1 && front != 0) 
                { 
                    rear = 0; 
                    stk[rear] = val; 
                } 
            else
                { 
                    rear++; 
                    stk[rear] = val; 
                } 
        }
        else if(str=="remove"){
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                int data = stk[front]; 
                stk[front] = -1; 
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
                        cout<<stk[i]<<" "; 
                } 
                else
                { 
                    for (int i = front; i < size; i++) 
                        cout<<stk[i]<<" "; 
            
                    for (int i = 0; i <= rear; i++) 
                        cout<<stk[i]<<" ";
                }
                cout<<endl;
            }
            
        }
        else if(str=="peek"){
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                cout<<stk[front]<<endl;
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