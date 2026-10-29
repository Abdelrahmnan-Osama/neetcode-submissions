class DSU {
private:
    vector<int> parent;
    vector<int> size;
    int connectedComponents;

public: 
    DSU(int numNodes) : parent(numNodes), size(numNodes, 1), connectedComponents(numNodes) {
        for(int i = 0; i < numNodes; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(parent[node] == node)  
            return node;

        parent[node] = find(parent[node]);

        return parent[node];
    }

    void Union(int nodeA, int nodeB) {
        int repA = find(nodeA), repB = find(nodeB);
        if(repA == repB)
            return;
            
        if(size[repA] > size[repB]) {
            parent[repB] = repA;
            size[repA] += size[repB];
        }      
        else {
            parent[repA] = repB;
            size[repB] += size[repA];
        }

        connectedComponents--;
    }

    int getConnetedCompenents() {
        return connectedComponents;
    }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0)
            return 0;

        DSU dsu(n);
        for(const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            dsu.Union(a, b);
        }

        return dsu.getConnetedCompenents();
    }
};
