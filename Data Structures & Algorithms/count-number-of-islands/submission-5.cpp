class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

   private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto d : directions) {
                int newR = r + d[0];
                int newC = c + d[1];
                if (!outOfBounds(grid, newR, newC) && grid[newR][newC] == '1') {              
                    q.push({newR, newC});
                    grid[newR][newC] = '0';
                }
            }
        }
    }

    bool outOfBounds(vector<vector<char>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        return row < 0 || row >= n || col < 0 || col >= m;
    }
};
