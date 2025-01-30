class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        parent.resize(n+2, -1);
        for(const auto& edge : edges){
            if (!unite(edge.front(), edge.back())){
                return edge;
            }
        }

        return {};
    }

private:
    vector<int> parent;

    int find(int x){
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;

        parent[rootY] = rootX;
        return true;
    }
};