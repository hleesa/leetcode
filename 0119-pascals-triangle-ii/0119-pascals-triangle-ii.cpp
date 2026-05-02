class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1, 1);
        vector<int> curr(2, 1);
        if(rowIndex == 0) return prev;
        if(rowIndex == 1) return curr;
        prev = curr;
        for(int r = 2; r <= rowIndex; ++r){
            curr[0] = 1;
            curr.push_back(1);
            for(int c = 1; c < r; ++c){
                curr[c] = prev[c-1] + prev[c];
            }

            prev = curr;
        }

        return curr;
    }
};