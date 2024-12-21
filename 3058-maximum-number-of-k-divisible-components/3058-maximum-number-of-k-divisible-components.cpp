class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n, vector<int>());
        for(const auto& edge : edges){
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }
        vector<int> outDegree(n, 0);
        getOutDegree(outDegree, adj);

        queue<int> q;
        for(int node = 0; node < n; ++node){
            if(outDegree[node] == 0){
                q.push(node);
            }
        }

        int numComponents = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(const auto& nextNode : adj[node]){
                if(outDegree[nextNode] == 0) continue;
                outDegree[nextNode]--;
                values[nextNode] = (values[nextNode] +values[node]) % k;
                if(outDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
            if (values[node] % k == 0){
                ++numComponents;
            }
        }

        return numComponents;
    }

    void getOutDegree(vector<int>& outDegree, const vector<vector<int>>& adj){
        vector<bool> visited(outDegree.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(const auto& nextNode : adj[node]){
                if(visited[nextNode]) continue;
                visited[nextNode] = true;
                outDegree[node]++;
                q.push(nextNode);
            }
        }
        return ;
    }

};