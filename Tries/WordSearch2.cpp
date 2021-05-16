#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
#include<unordered_set>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

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
        bool flag = false;

        for(int i=0; i<26; i++){
            if(root->children[index]->children[i]!=NULL){
                flag = true;
                break;
            }
        }
        if(!flag && root->children[index]->isTerminal== false){
            root->children[index] = NULL;
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
    
    void dfs(int sr, int sc, int m, int n, vector<vector<bool>>&visited, vector<vector<char>>& board, vector<vector<int>>directions, vector<string>&result, Node* root, string ans, unordered_map<string, bool>&mymap){
        if(sr<0 || sc<0 || sr>=m || sc>=n || visited[sr][sc]) return;
       
        char curr = board[sr][sc];
        if(root->children[curr-'a']==NULL) return;
        
        if(root->children[curr-'a']->isTerminal){
            string base = ans+curr;
            root->children[curr-'a']->isTerminal = false;
            // return;
            // Remove(base);
            // if(mymap.count(base)==0){
            //     mymap[base] = true;
                result.push_back(base);
            // }
            // else{
            //     return;
            // }
        }
        
        visited[sr][sc] = true;
        for(int i=0; i<4; i++){
            int newx = sr + directions[i][0];
            int newy = sc + directions[i][1];
            dfs(newx, newy, m, n, visited, board, directions, result, root->children[curr-'a'], ans+curr, mymap);
        }
            
        visited[sr][sc] = false;
    }
    
    
    vector<string> findwords_helper(vector<vector<char>>& board, vector<string>& words){
        int m = board.size(), n = board[0].size();
        vector<string>result;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        vector<vector<int>>directions = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
        unordered_map<string, bool>mymap;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = board[i][j]-'a';
                if(root->children[idx]!=NULL){
                    dfs(i, j, m, n, visited, board, directions, result, root, "", mymap);
                    if(result.size() == words.size()) return result;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* obj= new TrieNode();
        for(int i=0; i<words.size(); i++){
            obj->Insert(words[i]);
        }
        
        return obj->findwords_helper(board, words);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<char> > matrix(n, vector<char>(m));
    vector<string> words(l);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < l; i++){
        cin >> words[i];
    }
    Solution s;
    vector<string> found_words = s.findWords(matrix, words);
    for(int i = 0; i < (int) found_words.size(); i++){
        cout << found_words[i] << " ";
    }
    cout << '\n';
}