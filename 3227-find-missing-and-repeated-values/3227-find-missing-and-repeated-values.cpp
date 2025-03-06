class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> counter(n*n+2);
        for(auto row : grid){
            for(int val : row){
                counter[val]++;
            }
        }
        vector<int> ans;
        for(int i = 1; i <= n*n; ++i){
            if(counter[i] != 1){
                ans.push_back(i);
            }
        }
        if(counter[ans.front()] == 0){
            swap(ans.front(), ans.back());
        }
        return ans;
    }
};