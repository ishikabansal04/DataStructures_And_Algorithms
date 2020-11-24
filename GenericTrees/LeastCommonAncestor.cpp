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

Node* LeastCommonAncestor(Node* root, int val1, int val2){
    vector<Node*>path1, path2;
    NodeToRootPath(root, val1, path1);

    NodeToRootPath(root, val2, path2);

bool flag=false;
    Node* LCA=NULL;
    for(int i=0;i<path1.size();i++){
        for(int j=0;j<path2.size();j++){
            if(path1[i]->data == path2[j]->data){
                LCA=path1[i];
                flag=true;
                break;
            }
        }
        if(flag==true){
            break;
        }
    }
    return LCA;
}
int main(){
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int val1, val2;
    cin>>val1>>val2;

    Node* root=construct(arr);
    // display(root);
    
    Node* lca=LeastCommonAncestor(root, val1, val2);
    cout<<lca->data<<endl;
    
}