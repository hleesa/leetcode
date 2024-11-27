class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i = 0; i + 1 < n; ++i){
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(const auto& query : queries){
            adj[query.front()].push_back(query.back());
            ans.push_back(bfs(n));
        }
        return ans;
    }
private:
    vector<int> adj[502];
    
    int bfs(int n){
        queue<int> q;
        q.push(0);
        vector<int> dist(n, 1000);
        dist[0] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto& city : adj[cur]){
                if(dist[cur] + 1 < dist[city]){
                    dist[city] = dist[cur] + 1;
                    q.push(city);
                }
            }
        }
        return dist[n-1];
    }
};