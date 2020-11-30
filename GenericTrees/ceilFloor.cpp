#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<climits>
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

Node* cl=NULL;
Node* fl=NULL;
Node* previous=NULL;
void FloorCeil(Node* root, int key){
    
    if(root==NULL){
        return;
    }
    if(root->data < key){
        if(fl == NULL || root->data > fl->data){
            fl = root;
        }
    }
    else if(root->data > key){
        if(cl == NULL || root->data < cl->data){
            cl = root;
        }
    }
    for(Node*child: root->children){
        FloorCeil(child, key);
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
    int key;
    cin>>key;
    FloorCeil(root, key);
    cout<<"CEIL = ";
    if(cl!=NULL)cout<<cl->data<<endl;
    else{
        cout<<INT_MAX<<endl;
    }
    cout<<"FLOOR = ";
    if(fl!=NULL)cout<<fl->data;
    else{
        cout<<INT_MIN<<endl;
    }
}