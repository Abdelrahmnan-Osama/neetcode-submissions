class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int exclude_last_max = robHelper(nums, 0, true);
        dp.clear();
        int exclude_first_max = robHelper(nums, 1);
        
        return max(exclude_last_max, exclude_first_max);
    }

private:
    unordered_map<int, int> dp;

    int robHelper(const vector<int>& nums, int index, bool exclude_last = false) {
        int n = nums.size();
        dp[n] = 0, dp[n+1] = 0;

        int end = (exclude_last) ? n - 2 : n - 1; 
        for(int i = end; i >= index; i--) {
            if(!dp.contains(i))
                dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }

        return dp[index];
    }
};
