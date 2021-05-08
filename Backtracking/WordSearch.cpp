#include<iostream>
#include<vector>
#include<string>
using namespace std;

    bool helper(int sr, int sc, int er, int ec, string word, vector<vector<bool>>&visited, vector<vector<char>>& board, vector<vector<int>>directions){
        cout << sr << "    "<<sc << endl;
        if(sr<0 || sc<0 || sr>=er || sc>=ec || visited[sr][sc] || board[sr][sc] != word[0]){
            return false;
        }
        if(word.size()==1){
            if(word[0] == board[sr][sc]) return true;
            else return false;
        }
        visited[sr][sc] = true;
        bool smallres = false;
        for(int i=0; i<directions.size(); i++){
            int newx = sr+directions[i][0];
            int newy = sc+directions[i][1];
            
            smallres = smallres || helper(newx, newy, er, ec, word.substr(1), visited, board, directions);
        }
        visited[sr][sc] = false;
        return smallres;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int sr = 0, er = 0, sc = 0, ec = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    sr = i;
                    sc = j;
                    cout<<"Call:" << sr << "  "<< sc<<endl;
                bool res = helper(sr, sc, m, n, word, visited, board, directions);
                if(res) return res;
                }
            }
        }
        return false;
    }

    int main(){
        int m, n;
        cin>>m>>n;
        vector<vector<char>>board(m, vector<char>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>> board[i][j];
            }
        }
        string word;
        cin>>word;
        cout << exist(board, word);
    }