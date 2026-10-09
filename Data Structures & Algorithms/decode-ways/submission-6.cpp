class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);

        dp[0] = (s[0] == '0') ? 0 : 1;
        if(n == 1)
            return dp[0];

        dp[1] = (s[1] != '0') ? dp[0] : 0;
        if(s[0] == '1' || (s[0] == '2' && s[1] < '7'))
                dp[1]++;

        for(int i = 2; i < n; i++) {
            dp[i] = (s[i] != '0') ? dp[i - 1] : 0;

            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};
