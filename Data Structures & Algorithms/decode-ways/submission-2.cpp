class Solution {
public:
    int numDecodings(string s) {
        return dfs(s);
    }

private:
    unordered_map<int, int> memo;
    int dfs(const string& s, int i = 0) {
        int n = s.size();
        if(i == n)
            return 1;

        if(s[i] == '0')
            return 0;

        if(!memo.contains(i)) {
            memo[i] = dfs(s, i + 1);
            if(i < n - 1) {
                if(s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))
                    memo[i] += dfs(s, i + 2);
            }
            
        }
        return memo[i];
    }
};
