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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node* root = new Node('#');
    WordDictionary() {
        
    }
    
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
        if(word[0]!='.' && root->children[index]==NULL) return false;
        else if(word[0]=='.'){
            bool res = false;
            for(int i=0; i<26; i++){
                if(root->children[i]!=NULL){
                    res = res || helperSearch(word.substr(1), root->children[i]);
                }
            }
            return res;
        }
        else 
            return helperSearch(word.substr(1), root->children[index]);
    }
    
    void addWord(string word) {
        helperInsert(word, root);
    }
    
    bool search(string word) {
        return helperSearch(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */