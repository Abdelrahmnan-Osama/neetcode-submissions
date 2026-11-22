class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev_row(n + 1, 0);
        for(int r = m - 1; r >= 0; r--) {
            vector<int> cur_row(n + 1, 0);
            for(int c = n - 1; c >= 0; c--) {
                if(text1[c] == text2[r]) 
                    cur_row[c] = 1 + prev_row[c+1];
                else
                    cur_row[c] = max(prev_row[c], cur_row[c+1]);
            }
            prev_row = cur_row;
        }
        return prev_row[0];
    }
};
