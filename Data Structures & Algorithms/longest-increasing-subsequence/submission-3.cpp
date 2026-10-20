class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        memo.assign(n, vector<int>(n, -1));
        return LengthOfLISHelper(nums, 0, -1); 
    }

private:
    vector<vector<int>> memo;

    int LengthOfLISHelper(vector<int>& nums, int cur, int prev) {
        if (cur == nums.size()) 
            return 0;

        if (memo[cur][prev + 1] == -1) {
            int skip = LengthOfLISHelper(nums, cur + 1, prev);

            int take = 0;
            if (prev == -1 || nums[cur] > nums[prev])
                take = 1 + LengthOfLISHelper(nums, cur + 1, cur);

            memo[cur][prev+1] = max(take, skip);
        }

        return memo[cur][prev+1];
    }
};
