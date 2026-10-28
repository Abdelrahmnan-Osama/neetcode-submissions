class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(graph, i, visited);
                count++;
            }
        }
        return count;
    }

private:
    void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
        if(visited[node])
            return;

        visited[node] = true;

        for(auto nb : graph[node])
            dfs(graph, nb, visited);
    }
};
