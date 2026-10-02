class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> exclude_last = vector<int>(nums.begin(), nums.end()-1);
        vector<int> exclude_first = vector<int>(nums.begin()+1, nums.end());
        int exclude_last_max = robHelper(exclude_last, 0);
        memo.clear();
        int exclude_first_max = robHelper(exclude_first, 0);
        return max(exclude_last_max, exclude_first_max);
    }

private:
    unordered_map<int, int> memo;

    int robHelper(const vector<int>& nums, int index) {
        int n = nums.size();
        if(index >= n)
            return 0;
        
        if(!memo.contains(index))
            memo[index] = max(nums[index] + robHelper(nums, index+2), robHelper(nums, index+1));

        return memo[index];
    }
};
