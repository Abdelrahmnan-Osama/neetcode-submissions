class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int start = 0;
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
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
    vector<vector<int>> memo;
    bool is_pal(const string& s, int start, int end) {
        if(start >= end)
            return true;
        if(memo[start][end] == -1)
            memo[start][end] = s[start] == s[end] && is_pal(s, start + 1, end - 1);
        return memo[start][end];
    }
};
