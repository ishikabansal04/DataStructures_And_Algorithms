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

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root = new Node('#');
    Trie() {
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
        if(root->children[index]==NULL) return false;
        return helperSearch(word.substr(1), root->children[index]);
    }
    
    bool helperPrefix(string word, Node* root){
        if(word.size() == 0) {
            return true;
        }
        
        int index = word[0]-'a';
        if(root->children[index]==NULL) return false;
        return helperPrefix(word.substr(1), root->children[index]);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        helperInsert(word, root);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return helperSearch(word, root);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return helperPrefix(prefix, root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */