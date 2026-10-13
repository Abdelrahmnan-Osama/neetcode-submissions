class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(0, s, wordDict);
    }

private:
    unordered_map<int, bool> memo;
    bool dfs(int i, string s, const vector<string>& wordDict) {
        if(i == s.size())
            return true;

        if(memo.contains(i))
            return memo[i];

        for(const auto& word : wordDict) {
            int n = word.size();
            if(i + n <= s.size() && s.substr(i, n) == word) 
                    if(dfs(i + n, s, wordDict))
                        return memo[i] = true;
        }
        return memo[i] = false;
    }
};
