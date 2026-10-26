class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        for(int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, pacific, heights[0][c]);
            dfs(heights, ROWS - 1, c, atlantic, heights[ROWS - 1][c]);
        }

        for(int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, pacific, heights[r][0]);
            dfs(heights, r, COLS - 1, atlantic, heights[r][COLS - 1]);
        }

        vector<vector<int>> result;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }

private:
    void dfs(const vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& visited, int prev) {
        if(outOfBounds(heights, row, col) || heights[row][col] < prev || visited[row][col])
            return;

        visited[row][col] = true;

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for(const auto& dir : directions) {
            auto rShift = dir.first;
            auto cShift = dir.second;
            dfs(heights, row + rShift, col + cShift, visited, heights[row][col]);
        }
    }

    bool outOfBounds(const vector<vector<int>>& heights, int row, int col) {
        return row >= heights.size() || row < 0 || col >= heights[0].size() || col < 0;
    }
};
