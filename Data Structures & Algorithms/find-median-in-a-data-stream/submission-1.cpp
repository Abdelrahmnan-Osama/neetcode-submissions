class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) {
            left.push(num);
            if(left.size() > right.size() + 1) {
                int moved = left.top();
                left.pop();
                right.push(moved);
            }
        } else {
            right.push(num);
            if(right.size() > left.size()) {
                int moved = right.top();
                right.pop();
                left.push(moved);
            }
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) 
            return (float)(left.top() + right.top()) / 2;
        else
            return left.top();
    }
};
