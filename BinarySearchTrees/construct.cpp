#include<iostream>
using namespace std;

class Node{
    public:
    int data=0;
    Node* left=NULL;
    Node* right=NULL;
};


Node* construct(Node* root, int data){
    if(root==NULL){
        Node* newnode=new Node;
        newnode->data=data;
        root= newnode;
        return root;
    }
    if(root->data<data){
        root->right= construct(root->right, data);
    }
    else if(root->data >data){
        root->left= construct(root->left, data);
    }
    return root;
}

void display(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"=> ";
    if(root->left!=NULL){
        cout<<root->left->data;
    }
    else{
        cout<<".";
    }
    cout<<", ";
    if(root->right!=NULL){
        cout<<root->right->data;
    }
    else{
        cout<<".";
    }
    cout<<endl;
    display(root->left);
    display(root->right);
}

int main(){
    Node* root=construct(NULL, 5);
    root= construct(root, 4);
    root= construct(root, 3);
    root= construct(root, 8);
    root= construct(root, 2);
    root= construct(root, 9);
    root= construct(root, 1);
    root= construct(root, 0);
    root= construct(root, 6);
    root= construct(root, 7);
    display(root);
}