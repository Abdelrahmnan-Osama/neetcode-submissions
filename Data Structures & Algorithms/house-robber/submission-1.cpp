class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

private:
    unordered_map<int, int> memo;

    int dfs(const vector<int>& nums, int i) {
        if(i >= nums.size())
            return 0;

        if(!memo.contains(i))
            memo[i] = max(nums[i] + dfs(nums, i+2), dfs(nums, i+1));

        return memo[i];
    }
};
