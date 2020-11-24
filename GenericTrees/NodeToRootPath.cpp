#include<iostream>
#include<vector>
#include<stack>
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

void NodeToRootPath(Node* root, int key, vector<Node*>&path){
    if(root==NULL){
        return;
    }
    if(root->data == key){
        path.push_back(root);
        return;
    }
    for(Node* child: root->children){
        NodeToRootPath(child, key, path);
        if(path.size()!=0){
            break;
        }
    }
    if(path.size()!=0){
        path.push_back(root);
        return;
    }
}
int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    Node* root=construct(arr);
    // display(root);
    vector<Node*>res;
    NodeToRootPath(root, key,res);
    cout<<"[";
    if(res.size()!=0){
        for(int i=0;i<res.size()-1;i++){
            cout<<res[i]->data<<",";
        }
        cout<<res[res.size()-1]->data<<"]"<<endl;
    }
    else{
        cout<<"]"<<endl;
    }
    
}