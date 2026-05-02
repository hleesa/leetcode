class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        for(int r = 1; r <= rowIndex; ++r){
            vector<int> next(r+1, 1);
            for(int c = 1; c < r; ++c){
                next[c] = row[c-1] + row[c];
            }

            row = next;
        }

        return row;
    }
};