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

Node* temp=NULL;
int maxsum=INT_MIN;

int MaxTreeSum(Node* root){
    if(root==NULL){
        return 0;
    }
    // else if(root->children.size()==0){           this condition is not req as it will simplely return from leaf node
    //     return root->data;                       & wll not consider the case when leaf node has max sum.
    // }       
    int smallsum=0;
    for(Node* child:root->children){
        smallsum+=MaxTreeSum(child);
    }
    smallsum+=root->data;
    if(smallsum > maxsum){
        maxsum=smallsum;
        temp=root;
    }
    return smallsum;
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
    MaxTreeSum(root);
    cout<<temp->data<<"@"<<maxsum<<endl;
}