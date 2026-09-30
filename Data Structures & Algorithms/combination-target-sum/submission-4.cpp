class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int sum = 0;
        vector<int> candidate;
        backtrack(0, nums, target, candidate, result);
        return result;
    }

private:
    void backtrack(int start, const vector<int>& nums, int target,vector<int>& candidate, vector<vector<int>>& comb) {
        if(target < 0)
            return;
        if(target == 0) {
            comb.push_back(candidate);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            target -= nums[i];
            candidate.push_back(nums[i]);
            backtrack(i, nums, target, candidate, comb);
            target+= nums[i];
            candidate.pop_back();
        }
    }
};
