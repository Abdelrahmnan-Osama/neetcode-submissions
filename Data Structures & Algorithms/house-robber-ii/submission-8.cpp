class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int exclude_last_max = robHelper(nums, 0, true);
        int exclude_first_max = robHelper(nums, 1);
        
        return max(exclude_last_max, exclude_first_max);
    }

private:
    int robHelper(const vector<int>& nums, int index, bool exclude_last = false) {
        int n = nums.size();

        int one_forward = 0, two_forward = 0;
        int end = (exclude_last) ? n - 2 : n - 1; 
        for(int i = end; i >= index; i--) {
            int curr = max(nums[i] + two_forward, one_forward);
            two_forward = one_forward;
            one_forward = curr;
        }

        return one_forward;
    }
};
