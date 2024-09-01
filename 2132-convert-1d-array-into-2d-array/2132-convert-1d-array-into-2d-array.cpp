class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n));
        int size = original.size();
        if (size != m*n){
            return {};
        }
        for(int i = 0; i < original.size(); ++i){
            ret[i/n][i%n] = original[i];
        }
        return ret;
    }
};