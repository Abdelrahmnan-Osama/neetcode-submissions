class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int exclude_last_max = robHelper(nums, 0, true);
        memo.clear();
        int exclude_first_max = robHelper(nums, 1);
        
        return max(exclude_last_max, exclude_first_max);
    }

private:
    unordered_map<int, int> memo;

    int robHelper(const vector<int>& nums, int index, bool exclude_last = false) {
        int n = nums.size();
        if(index >= n)
            return 0;
        if(exclude_last && index == n-1)
            return 0;
        
        if(!memo.contains(index))
            memo[index] = max(nums[index] + robHelper(nums, index+2, exclude_last), robHelper(nums, index+1, exclude_last));

        return memo[index];
    }
};
