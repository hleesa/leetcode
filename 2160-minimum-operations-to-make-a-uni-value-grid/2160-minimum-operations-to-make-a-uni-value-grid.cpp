class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> diffs;
        int base = grid.front().front();
        for(const auto& rows : grid){
            for(const auto& val : rows){
                int diff = val - base;
                if (diff % x != 0){
                    return -1;
                }
                diffs.push_back(diff/x);
            }
        }
        sort(diffs.begin(), diffs.end());
        int median = diffs[diffs.size()/2];
        int minOp = 0;
        for(auto diff : diffs){
            minOp += abs(diff - median);
        }
        return minOp;
    }
};