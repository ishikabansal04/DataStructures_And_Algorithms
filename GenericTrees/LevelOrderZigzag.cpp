#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

class Node{
    public:
    int data=0;
    vector<Node*>children;  
};

Node* construct(vector<int>arr){
    stack<Node*>stk;
        Node* root;

    for(int i=0;i<arr.size();i++){
        Node* node=new Node;
        node->data=arr[i];
        if(arr[i]==-1){
            stk.pop();
        }
        else{
            if(stk.size()>0){
                Node *rn= stk.top();
                rn->children.push_back(node);
            }
            else{
                root=node;
            }
            stk.push(node);
        }
    }
    return root;
}

void display(Node* root){
    string str=to_string(root->data)+" => { ";
    for(Node* child:root->children){
        str+=to_string(child->data);
        str+=", ";
    }
    str+=". }";
    cout<<str<<endl;
    
    for(Node* child:root->children){
        display(child);
    }
}



void levelOrderZigzag(Node* root){
    if(root==NULL){
        return;
    }
    vector<int>arr;
    queue<Node*>que;
    int dir=0;
    que.push(root);
    int level=1;
    while(que.size()!=0){
        Node* rn= que.front();
        arr.push_back(rn->data);
        level--;
        que.pop();
        for(Node* child: rn->children){
            que.push(child);
        }
        if(level==0){
            level=que.size();
            if(dir==0){
                for(int i=0;i<arr.size();i++){
                    cout<<arr[i]<<" ";
                }
                arr.clear();
                cout<<endl;
                dir=1;
            }
            else if(dir==1){
                for(int i=arr.size()-1;i>=0;i--){
                    cout<<arr[i]<<" ";
                }
                arr.clear();
                cout<<endl;
                dir=0;
            }
        }
    }
}

int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    Node* root=construct(arr);
    // display(root);
    levelOrderZigzag(root);

}