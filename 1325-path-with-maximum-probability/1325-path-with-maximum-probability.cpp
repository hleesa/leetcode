class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i = 0; i < edges.size(); ++i){
            int from = edges[i].front();
            int to = edges[i].back();
            double prob = succProb[i];
            adj[from].push_back({to,prob});
            adj[to].push_back({from,prob});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
        vector<double> probability(n+1);
        probability[start_node] = 1.0;

        while(!pq.empty()){
            double prob; int edge; 
            tie(prob,edge) = pq.top();
            pq.pop();
            for(const auto& next : adj[edge]){
                double nextProb = prob * next.second;
                int nextEdge = next.first;
                if (nextProb <= probability[nextEdge]) continue;
                pq.push({nextProb, nextEdge});
                probability[nextEdge] = nextProb;
            }
        }

        return probability[end_node];
    }
private:
    vector<pair<int,double>> adj[10002];
};