class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), left = 0, right = n - 1;
        int minn = INT_MAX;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[left] <= nums[mid]) {
                minn = min(nums[left], minn);
                left = mid + 1;
            } else {
                minn = min(nums[mid], minn);
                right = mid - 1;
            }

        }
        return (minn == INT_MAX) ? -1 : minn;
    }
};
