// Reference: https://leetcode.com/problems/word-search-ii/



// Given an m x n board of characters and a list of strings words, return all words on the 
// board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent 
// cells are horizontally or vertically neighboring. The same letter cell may not be used more 
// than once in a word.

 

// Example 1:
// ==========
// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]

// Example 2:
// ==========
// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 


// Constraints:
// ============
// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 10^4
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.





class Node {
public:
    string word;
    vector<Node*> child;

    Node() {
        word = "";
        child.resize(26, NULL);
    }
};

class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    void insert(Node* root, string& word) {
        for (char ch: word) {
            if (root->child[ch - 'a'] == NULL)
                root->child[ch - 'a'] = new Node();
            root = root->child[ch - 'a'];
        }
        root->word = word;
    }

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    void dfs(int x, int y, int row, int col, vector<vector<char>>& board, Node* root, unordered_set<string>& found, vector<vector<bool>>& visited) {
        int childIdx = board[x][y] - 'a';
        if (root->child[childIdx] != NULL) {
            if (root->child[childIdx]->word != "")
                found.insert(root->child[childIdx]->word);
            for (int i = 0; i < X.size(); ++i) {
                int nextX = x + X[i], nextY = y + Y[i];
                if (isValid(nextX, nextY, row, col) && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    dfs(nextX, nextY, row, col, board, root->child[childIdx], found, visited);
                    visited[nextX][nextY] = false;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* trie = new Node();
        for (string word: words)
            insert(trie, word);
        
        unordered_set<string> found;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                visited[i][j] = true;
                dfs(i, j, row, col, board, trie, found, visited);
            }
        }
        return vector<string>(found.begin(), found.end());
    }
};
