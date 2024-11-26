class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inOrder(n);
        for(const auto& edge : edges){
            ++inOrder[edge.back()];
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(inOrder[i] == 0){
                ans.push_back(i);
            }
        }
        return ans.size() == 1 ? ans.front() : -1;
    }
    
};