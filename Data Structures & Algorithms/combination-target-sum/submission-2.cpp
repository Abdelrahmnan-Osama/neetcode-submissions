class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int sum = 0;
        vector<int> candidate;
        backtrack(0, nums, target, sum, candidate, result);
        return result;
    }

private:
    void backtrack(int start, const vector<int>& nums, int target, int sum,vector<int>& candidate, vector<vector<int>>& comb) {
        if(sum > target)
            return;
        if(sum == target) {
            comb.push_back(candidate);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            sum += nums[i];
            candidate.push_back(nums[i]);
            backtrack(i, nums, target, sum, candidate, comb);
            sum-= nums[i];
            candidate.pop_back();
        }
    }
};
