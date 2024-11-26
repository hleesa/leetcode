class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        for(const auto& edge : edges){
            ++inDegree[edge.back()];
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(inDegree[i] == 0){
                ans.push_back(i);
            }
        }
        return ans.size() == 1 ? ans.front() : -1;
    }
    
};