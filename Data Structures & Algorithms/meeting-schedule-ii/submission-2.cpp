/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;

        for(auto interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int count = 0;
        int numRooms = 0;
        for(int s = 0, e = 0; s < starts.size();) {
            if(starts[s] < ends[e]) {
                count++;
                s++;
            } else {
                count--;
                e++;
            }
            numRooms = max(numRooms, count);
        }
        return numRooms;
    }
};
