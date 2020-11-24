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

Node* get_tail(Node* root){
    while(root->children.size()==1){
        root=root->children[0];
    }
    return root;
}


void linearize(Node* root){
    if(root->children.size()==0){
        return;
    }
    for(Node* child: root->children){
        linearize(child);
    }
    while(root->children.size()>1){
        Node* temp_head=root->children[root->children.size()-1];
        root->children.erase(root->children.begin()+root->children.size()-1);
        Node* temp_tail=get_tail(root->children[root->children.size()-1]);

        temp_tail->children.push_back(temp_head);
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

//efficient approach for same problem.
Node* linearise2(Node* root){
    if(root->children.size()==0){
        return root;
    }
    Node* final_tail=linearise2(root->children[root->children.size()-1]);
    while(root->children.size()>1){
        Node* temp_head=root->children[root->children.size()-1];
        root->children.erase(root->children.begin()+root->children.size()-1);
        Node* temp_tail=linearise2(root->children[root->children.size()-1]);
        temp_tail->children.push_back(temp_head);
    }
    return final_tail;
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
    linearize(root);
    linearise2(root);
    display(root);
}