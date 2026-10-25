class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            inDegree[p[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        int finished = 0;
        while(!q.empty()) {
            auto course = q.front();
            q.pop();
            finished++;
            for(auto neighbor : graph[course]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return finished == numCourses;
    }
};
