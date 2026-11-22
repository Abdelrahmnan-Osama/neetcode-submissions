class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev_row(n, 1);
        for(int r = 1; r < m; r++) {
            vector<int> cur_row(n, 1);
            for(int c = 1; c < n; c++) {
                cur_row[c] = prev_row[c] + cur_row[c-1];
            }
            prev_row = cur_row;
        }
        return prev_row[n-1];
    }
};
