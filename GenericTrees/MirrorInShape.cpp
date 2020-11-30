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

bool AreTreesSimilar(Node* root1, Node* root2){
    if((root1==NULL && root2!=NULL)||(root2==NULL && root1!=NULL)){
        return false;
    }
    else if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1->children.size()!=root2->children.size()){
        return false;
    }
    bool smallres=true;
    for(int i=0;i<root1->children.size();i++){
        // cout<<root1->children[i]->data<<"   "<<root1->children[root2->children.size()-i-1]->data<<endl;
        smallres=smallres && AreTreesSimilar(root1->children[i], root2->children[root2->children.size()-i-1]);
        if(smallres==false){
            break;
        }
    }
    return smallres;
}

int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    Node* root1=construct(arr);

    int size2;
    cin>>size2;
    vector<int>arr2(size);
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }

    Node* root2=construct(arr2);
    cout<<boolalpha<<AreTreesSimilar(root1, root2);
}