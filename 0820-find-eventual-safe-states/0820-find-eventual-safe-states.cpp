class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> safeNode(n, -1);
        for(int node = 0; node < n; ++node){
            if(safeNode[node] == -1){
                vector<bool> visited(n, false);
                safeNode[node] = findSafeNode(graph, safeNode, visited, node);
            }
        }

        vector<int> safeNodes;
        for(int node = 0; node < n; ++node){
            if(safeNode[node] == 1){
                safeNodes.push_back(node);
            }
        }
        return safeNodes;
    }

private:
    int findSafeNode(const vector<vector<int>>& graph, vector<int>& safeNode, vector<bool>& visited, int node){
        if(safeNode[node] != -1) return safeNode[node];
        else if(graph[node].empty()) return 1;
        else if(visited[node]) return 0;
        visited[node] = true;
        for(int adjNode : graph[node]){
            if (safeNode[adjNode] == -1){
                safeNode[adjNode] = findSafeNode(graph, safeNode, visited, adjNode);
            }
            if (safeNode[adjNode] == 0){
                return 0;
            }
        }
        return 1;
    }
};