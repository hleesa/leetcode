class Solution {
private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        parent[rootY] = rootX;
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        parent.assign(N, -1);

        for (auto edge : edges) {
            if (!unite(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};
