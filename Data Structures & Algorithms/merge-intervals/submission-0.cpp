class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged = {intervals[0]};

        for(int i = 1; i < intervals.size(); i++) {
            int& curStart = merged.back()[0];
            int& curEnd = merged.back()[1];

            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];

            if(newStart <= curEnd) {
                curEnd = max(newEnd, curEnd);
            } else {
                merged.push_back(intervals[i]);
            }  
        }
        return merged;
    }
};
