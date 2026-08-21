class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        int n = nums.size();
        for(int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;
            if(k && nums[k] == nums[k-1])
                continue;
            while(i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0)
                    j--;
                else if(sum < 0)
                    i++;
                else {
                    triplets.push_back({nums[k], nums[i], nums[j]});
                    i++; 
                    j--;
                    while(i < j && nums[i] == nums[i - 1])
                        i++;
                    while(i < j && nums[j] == nums[j + 1])
                        j--;
                }
            }
        }
        return triplets;
    }
};
