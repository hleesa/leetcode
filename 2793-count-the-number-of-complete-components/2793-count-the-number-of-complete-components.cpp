
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> degree(n, vector<int>(2));
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            degree[from][0]++;
            degree[from][1]++;
            degree[to][0]++;
            degree[to][1]++;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int ans = 0;
        queue<int> q, path;
        vector<bool> visited(n);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            q.push(i);
            path.push(i);
            visited[i] = true;

            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto next : adj[cur]){
                    if(visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                    path.push(next);
                }
            }
            int numNode = path.size();
            bool complete = true;
            if(numNode > 0){
                while(!path.empty()){
                    int node = path.front(); path.pop();
                    if(degree[node][0] != numNode - 1 || degree[node][1] != numNode - 1){
                        complete = false;
                        break;
                    }
                }
            }
            if(complete) ++ans;
            while(!path.empty()) path.pop();
        }

        return ans;
    }
};