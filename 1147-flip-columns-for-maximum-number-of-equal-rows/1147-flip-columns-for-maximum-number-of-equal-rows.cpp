class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        sort(matrix.begin(), matrix.end());
        const int m = matrix.size();
        if(matrix.front().size() == 1){
            return m;
        }

        int ans = 0;
        for(int y = 0; y < m; ++y){
            ans = max(maxRows(matrix, y),ans);
        }
        return ans;
    }

private:
    int maxRows(const vector<vector<int>>& matrix, int y){
        int same = 0;
        int invert = 0;
        for(int dy = y + 1; dy < matrix.size(); ++dy){
            if(sameRow(matrix[dy], matrix[y])) ++same;
            if(invertRow(matrix[dy], matrix[y])) ++invert;
        }
        return same + invert + 1;
    }

    bool sameRow(const vector<int>& lhs, const vector<int>& rhs){
        for(int x = 0; x < lhs.size(); ++x){
            if(lhs[x] != rhs[x]) return false;
        }
        return true;
    }

    bool invertRow(const vector<int>& lhs, const vector<int>& rhs){
        for(int x = 0; x < lhs.size(); ++x){
            if(!(lhs[x] ^ rhs[x])) return false;
        }
        return true;
    }
};
