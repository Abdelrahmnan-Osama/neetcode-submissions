class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(backtrack(row, col, board, 0, word))
                    return true;
            }
        }
        return false;
    }

private:
    bool backtrack(int row, int col, vector<vector<char>>& board, int i, const string& word) {
        if(i == word.size())
            return true;
        if(outOfBounds(row, col, board) || word[i] != board[row][col])
            return false;

        board[row][col] = '#';

        bool res = backtrack(row + 1, col, board, i + 1, word) ||
              backtrack(row - 1, col, board, i + 1, word) ||
              backtrack(row, col + 1, board, i + 1, word) ||
              backtrack(row, col - 1, board, i + 1, word);
                
        board[row][col] = word[i];

        return res;
    }

    bool outOfBounds(int row, int col, const vector<vector<char>>& board) {
        return row < 0 or row >= board.size() or col < 0 or col >= board[0].size();
    }
};
