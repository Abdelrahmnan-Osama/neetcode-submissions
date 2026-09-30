class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        unordered_map<int, int> dp;
        for(int i = n - 1; i >= 0; i--)
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);

        return dp[0];
    }
};
