#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
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


void removeLeaf(Node* root){
    
    for(int i=root->children.size()-1;i>=0;i--){
        if(root->children[i]->children.size()==0){
            root->children.erase(root->children.begin()+i);
        }
    }
    for(Node* child: root->children){
        removeLeaf(child);
    }
}

void display(Node* root){
    string str=to_string(root->data)+" -> ";
    for(Node* child:root->children){
        str+=to_string(child->data);
        str+=", ";
    }
    str+=".";
    cout<<str<<endl;
    
    for(Node* child:root->children){
        display(child);
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
    removeLeaf(root);
    display(root);
}