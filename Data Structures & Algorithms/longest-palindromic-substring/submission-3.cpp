class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int start = 0;
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(is_pal(s, i, j) && j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLength);
    }

private:
    vector<vector<int>> dp;
    bool is_pal(const string& s, int start, int end) {
        if(start >= end)
            return true;
        if(dp[start][end] == -1)
            dp[start][end] = s[start] == s[end] && dp[start + 1][end - 1];
        return dp[start][end];
    }
};