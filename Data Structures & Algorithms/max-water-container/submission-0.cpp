class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int maxx = INT_MIN;
        while (i < j) {
                int area = (j - i) * min(heights[i], heights[j]);
                maxx = max(maxx, area);
                if(heights[i] < heights[j])
                    i++;
                else
                    j--;
        }
        return maxx;
    }
};
