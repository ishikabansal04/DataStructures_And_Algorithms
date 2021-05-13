#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
    char data;
    vector<Node*>children;
    bool isTerminal;

    Node(char data){
        this->data = data;
        children = vector<Node*>(26, NULL);
        isTerminal = false;
    }
};

class TrieNode{
    Node* root = new Node('#');

    void helperInsert(string word, Node* root){
        if(word.size()==0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';
        Node* newnode = new Node(word[0]);
        
        if(root->children[index]==NULL){
            root->children[index] = newnode;
        }
        helperInsert(word.substr(1), root->children[index]);
    }

    bool helperSearch(string word, Node* root){
        if(word.size() == 0) {
            return (root->isTerminal);
        }

        int index = word[0]-'a';
        if(root->children[index]==NULL) return false;
        return helperSearch(word.substr(1), root->children[index]);
    }

    void helperRemove(string word, Node* root){
        if(word.size()==0) return;

        int index = word[0]-'a';
        if(root->children[index]==NULL){
            cout << "Word doesn't exist" << endl;
            return;
        }
        if(word.size()==1){
            root->children[index]->isTerminal = false;
        } 
        helperRemove(word.substr(1), root->children[index]);
    }

    void helperDisplay(Node* root, string word){
        if(root == NULL) return;
        if(root->isTerminal){
            string temp = word + root->data;
            cout << temp << endl;
        }

        for(int i=0; i<26; i++){
            string temp = word + root->data ;
            helperDisplay(root->children[i], temp);
        }
    }

    public:
    void Insert(string word){
        helperInsert(word, root);
    }

    bool Search(string word){
        return helperSearch(word, root);
    }

    void Remove(string word){
        helperRemove(word, root);
    }

    void Display(){
        helperDisplay(root, "");
    }
};

int main(){
    TrieNode* obj = new TrieNode();
    cout << "Menu: \n1. Insert \n2. Search \n3. Remove \n4. Display Trie \n5. Quit \n";
    cout << "Enter operation number: ";
    int op;
    cin >> op;
    while(op<=4 && op>=1){
        string str;
        if(op!=4){
            cout << "Enter String: ";
            cin >> str;
        }
        if(op == 1){
            obj->Insert(str);
        }
        else if(op == 2){
            cout << boolalpha << obj->Search(str) << endl;
        }
        else if(op == 3){
            obj->Remove(str);
        }
        else if(op == 4){
            obj->Display();
        }
        else{
            break;
        }
        cout << "Enter operation number: ";
        cin >> op;
    }
    return 0;
}