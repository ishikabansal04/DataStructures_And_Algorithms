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

Node* pred=NULL;
Node* succ=NULL;
Node* previous=NULL;
void PredSucc(Node* root, int key){
    
    if(root==NULL){
        return;
    }
    // cout<<root->data<<"             ";
    // if(previous!=NULL)cout<<previous->data<<endl;
    // else{
    //     cout<<0<<endl;
    // }
    if(root->data==key){
        pred=previous;
        previous=root;
        if(root->children.size()==0) return;
        PredSucc(root->children[0], key);
    }
    else if(previous!=NULL && previous->data==key && succ==NULL){
        succ=root;
        return;
    }
    previous=root;

    for(Node* child: root->children){
        // if(pred==NULL){
        //     cout<<0<<"        ";
        // }
        // else{
        //     cout<<pred->data<<"        ";
        // }
        // if(succ==NULL){
        //     cout<<0<<"         "<<endl;
        // }
        // else{
        //     cout<<succ->data<<"         "<<endl;
        // }
        
        if(pred == NULL || succ==NULL)
        PredSucc(child, key);
        else{
            return;
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
    int key;
    cin>>key;
    PredSucc(root, key);
    cout<<"Predecessor = ";
    if(pred!=NULL)cout<<pred->data<<endl;
    else{
        cout<<"Not found"<<endl;
    }
    cout<<"Successor = ";
    if(succ!=NULL)cout<<succ->data;
    else{
        cout<<"Not found"<<endl;
    }
}