class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int& newStart = newInterval[0];
        int& newEnd = newInterval[1];
        vector<vector<int>> out;

        for(int i = 0; i < n; i++) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            if(curEnd < newStart) {
                out.push_back(intervals[i]);
            } else if (curStart > newEnd) {
                out.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(out));
                return out;
            } else {
                newStart = min(curStart, newStart);
                newEnd = max(curEnd, newEnd);
            }
        }

        out.push_back(newInterval);

        return out;
    }
};
