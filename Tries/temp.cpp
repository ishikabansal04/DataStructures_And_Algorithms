// * Class for nodes used in trie
class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    
    Node(char data){
        this-> data = data;
        this-> terminal = false;
    }
};

//* Trie Class
class Trie{
public:
    Node *root;
    
    Trie(){
        root = new Node('#');
    }
private:
    void insert_helper(Node *root, string word){
        if(word.size() == 0){
            root-> terminal = true;
            return;
        }
        if(root-> children.count(word[0]) == 0){
            Node *child = new Node(word[0]);
            root-> children[word[0]] = child;
        }
        insert_helper(root-> children[word[0]], word.substr(1));
    }
    
    int prefix_helper(Node *root, string prefix){
        if(prefix.size() == 0){
            if(root-> terminal)
                return 2;
            else
                return 1;
        } 
        
        if(root-> children.count(prefix[0]) == 0)
            return 0;
       
         int recursive_ans = prefix_helper(root-> children[prefix[0]], prefix.substr(1));
        return recursive_ans;
    }
    
    void remove_helper(Node *root, string word){
        if(word.size() == 0){
            root-> terminal = false;
            return;
        }
        Node *child = NULL;
        if(root-> children.count(word[0]) == 0)
            return;
        
        else{
            child = root-> children[word[0]];
            remove_helper(child, word.substr(1));
        }
        if(child != NULL && !child-> terminal && child-> children.size() == 0){
            delete child;
            root-> children.erase(word[0]);
        }
    }
    
public: 
    // To insert a word in trie
    void insert(string &word){
        insert_helper(root, word);
    }
    
   // To search for prefix of a word in trie 
    int prefix(string &prefix){
        return prefix_helper(root, prefix);
    }
    
    // To remove a word from trie
    void remove(string &word){
        remove_helper(root, word);
    }
};


class Solution {
public:
    
    void traversal(int sx, int sy, string path, vector<vector<char> > &board, Trie &t, vector<string> &found, int found_words){
        // * To check matrix limits and visited cells
        if(sx < 0 || sx >= (int) board.size() || sy < 0 || sy >= (int) board[0].size() || board[sx][sy] == '#')
            return;
        
        // * If we have found all the words, then just return
        if(found_words == 0)
            return;
        
        // * Added the current cell char to path variable
        path += board[sx][sy];
        
        // * To check if we are exploring a wrong cell, like if there is no word with this prefix, we just return
        // * prefix status variable maintains what is the status of path variable right now
        // * prefix status = 0 // There is no word in the trie with this prefix
        // * prefix status = 1 // Path is a proper prefix of a word in the trie, so we search for the word further
        // * prefix status = 2 // Path is equal to some word which is present in the trie
        int prefix_status = t.prefix(path);
        
        if(prefix_status == 0)
            return;
        else{
            if(prefix_status == 2){
            // Found the word, so we delete it from trie, and push the word in found vector and decrement the counts of words which we have to find
                t.remove(path);
                found.emplace_back(path);
                found_words--;
            }
        }
       
       // * Marked the cell visited; 
        board[sx][sy] = '#';
        
       // * Calls in 4 directions  
        traversal(sx - 1, sy, path, board, t, found, found_words);
        traversal(sx + 1, sy, path, board, t, found, found_words);
        traversal(sx, sy - 1, path, board, t, found, found_words);
        traversal(sx, sy + 1, path, board, t, found, found_words);
        
       // * Unmarked the previously marked cell after backtracking, so that we can explore it from other cells
        board[sx][sy] = path[path.size() - 1];
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // To store the words which we have to find
        Trie t;
        
        // To store the words we found in the matrix
        vector<string> found;
        
        // To maintain the count of words which we have to find in the matrix
        int found_words = words.size();
        
        for(int i = 0; i < (int) words.size(); i++)
                t.insert(words[i]);
        for(int i = 0; i < (int) board.size(); i++){
            
           // Path variable to maintain the current status of the word during DFS traversal 
            string path = "";
            for(int j = 0; j < (int) board[0].size(); j++){
                traversal(i, j, path, board, t, found, found_words);
            }
        }
        // After traversal of the matrix, we return the found vector
        return found;
    }
};