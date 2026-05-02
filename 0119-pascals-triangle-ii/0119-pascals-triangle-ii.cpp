class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1, 1);
        if(rowIndex == 0) return prev;

        vector<int> curr = prev;
        for(int r = 1; r <= rowIndex; ++r){
            curr.push_back(1);
            for(int c = 1; c < r; ++c){
                curr[c] = prev[c-1] + prev[c];
            }

            prev = curr;
        }

        return curr;
    }
};