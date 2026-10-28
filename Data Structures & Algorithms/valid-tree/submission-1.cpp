class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n ==  0)
            return false;

        vector<vector<int>> adj(n);
        vector<bool> visited(n, 0);
        for(auto edge : edges) 
        {
            int node = edge[0];
            int neighbor = edge[1];
            adj[node].push_back(neighbor);
            adj[neighbor].push_back(node);
        }

        return dfs(adj, 0, visited, -1) && count(visited.begin(), visited.end(), 1) == n;
    }

private:
    bool dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited, int parent) {

        if(visited[node])
            return false;

        visited[node] = true;

        for(auto neighbor : graph[node]) {
            if(neighbor == parent)
                continue;
            if(!dfs(graph, neighbor, visited, node))
                return false;
        }

        return true;
    }
};
