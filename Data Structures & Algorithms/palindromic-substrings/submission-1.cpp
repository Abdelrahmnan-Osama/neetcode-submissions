class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int totalPals = 0;
        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            totalPals++;
            dp[i][i] = true;
        }

        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) {
                totalPals++;
                dp[i][i+1] = true;
            }
        }

        for(int len = 3; len < n + 1; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    totalPals++;
                    dp[i][j] = true;
                }
            }
        }
        return totalPals;
    }
};
