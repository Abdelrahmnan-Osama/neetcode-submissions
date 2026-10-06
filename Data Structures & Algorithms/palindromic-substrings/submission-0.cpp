class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int totalPals = 0;
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPal(s, i, j))
                    totalPals++;
            }
        }
        return totalPals;
    }

private:
    vector<vector<int>> memo; 
    bool isPal(const string& s, int start, int end) {
        if(start >= end)
            return true;

        if(memo[start][end] == -1)
            memo[start][end] = s[start] == s[end] && isPal(s, start + 1, end - 1);
        
        return memo[start][end];
    }
};
