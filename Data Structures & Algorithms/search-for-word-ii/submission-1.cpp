class TrieNode {
private:
    unordered_map<char, TrieNode*> children;
    string word;
public:
    void addWord(const string& word) {
        TrieNode* cur = this;
        for(const auto& c : word) {
            if(!cur->children.contains(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = word;
    }
    
    friend class Solution;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(const auto& word : words)
            root->addWord(word);

        int rows = board.size(), cols = board[0].size();
        vector<string> res;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                    dfs(board, i, j, root, res);
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& res) {
        if(outOfBounds(board, row, col)
            || !node->children.contains(board[row][col]))
            return;
        
        char temp = board[row][col];
        node = node->children[temp];
        board[row][col] = '#';
        if(!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }

        dfs(board, row + 1, col, node, res);
        dfs(board, row - 1, col, node, res);
        dfs(board, row, col + 1, node, res);
        dfs(board, row, col - 1, node, res);

        board[row][col] = temp;
    }

    bool outOfBounds(const vector<vector<char>>& board, int row, int col) {
        return row < 0 or row >= board.size() or col < 0 or col >= board[0].size();
    }
};
