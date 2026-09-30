class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

private:
    unordered_map<int, int> dp;

    int dfs(const vector<int>& nums, int index) {
        int n = nums.size();
        if(index >= n)
            return 0;

        for(int i = n - 1; i >=index; i--)
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);

        return dp[index];
    }
};
