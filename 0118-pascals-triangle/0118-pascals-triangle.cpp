class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows);
        for(int r = 0; r < numRows; ++r){
            vec[r].assign(r+1, 0);
        }

        vec[0][0] = 1;
        for(int r = 1; r < numRows; ++r){
            vec[r][0] = vec[r-1][0];
            vec[r][r] = vec[r-1][r-1];
            for(int c = 1; c < r; ++c){
                vec[r][c] += vec[r-1][c-1] + vec[r-1][c];
            }
        }

        return vec;
    }
};