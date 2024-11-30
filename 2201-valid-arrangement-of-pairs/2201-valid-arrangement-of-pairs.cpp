class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;

        for(auto& pair : pairs){
            int begin = pair[0];
            int end = pair[1];
            graph[begin].push_back(end);
            outDegree[begin]++;
            inDegree[end]++;
        }

        int beginNode = pairs[0][0];
        for(auto& [node, _] : graph){
            if(outDegree[node] > inDegree[node]){
                beginNode = node;
                break;
            }
        }

        stack<int> stk;
        deque<int> result;
        stk.push(beginNode);

        while(!stk.empty()){
            int node = stk.top();
            if(!graph[node].empty()){
                int next = graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            }
            else{
                result.push_front(node);
                stk.pop();
            }
        }

        vector<vector<int>> ans;
        for(auto it = result.begin(); it + 1 != result.end(); ++it){
            ans.push_back({*it, *(it+1)});
        }
        return ans;
    }
};