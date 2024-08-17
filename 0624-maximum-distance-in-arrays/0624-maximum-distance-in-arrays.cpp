class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minVal = arrays.front().front();
        int maxVal = arrays.front().back();

        for(int i=1; i < arrays.size(); ++i){
            ans = max({arrays[i].back() - minVal, maxVal - arrays[i].front(), ans});
            minVal = min(arrays[i].front(), minVal);
            maxVal = max(arrays[i].back(), maxVal);
        }

        return ans;
    }
};