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

class Pair{
    public:
    Node* node=NULL;
    int state=-1;
    Pair(Node* root){
        this->node=root;
        this->state=-1;
    }
};

void Traversal(Node* root){
    vector<Node*>preorder;
    vector<Node*>postorder;
    stack<Pair*>stk;
    Pair* mypair=new Pair(root);
    stk.push(mypair);
    while(stk.size()!=0){
        Pair* rpair=stk.top();
        stk.pop();
        if(rpair->state==-1){
            preorder.push_back(rpair->node);
            rpair->state+=1;
            stk.push(rpair);
        }
        else if(rpair->state==rpair->node->children.size()){
            postorder.push_back(rpair->node);
        }
        else{
            Pair* newpair= new Pair(rpair->node->children[rpair->state]);
            rpair->state+=1;
            stk.push(rpair);
            stk.push(newpair);
        }
    }

    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]->data<<" ";
    }
    cout<<endl;
     for(int i=0;i<preorder.size();i++){
        cout<<postorder[i]->data<<" ";
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
    Traversal(root);
}