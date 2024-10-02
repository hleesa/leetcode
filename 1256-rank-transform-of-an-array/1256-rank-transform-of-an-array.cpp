class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j){
            return arr[i] < arr[j];
        });

        int val = 1;
        vector<int> rank(n);
        for(int i = 0; i < n; ++i){
            if (i > 0 && arr[indices[i -1]] != arr[indices[i]]){
                ++val;
            }
            rank[indices[i]] = val;
        }
        return rank;
    }
};