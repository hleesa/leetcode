class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int,int>> indexdNums;

        for(int i = 0; i < n; ++i){
            indexdNums.emplace_back(nums[i], i);
        }
        
        sort(indexdNums.begin(), indexdNums.end());
        int minIndex = indexdNums.front().second;
        int maxWidth = 0;

        for(int i = 1; i < n; ++i){
            int currentIndex = indexdNums[i].second;
            maxWidth = max(currentIndex - minIndex, maxWidth);
            minIndex = min(currentIndex, minIndex);
        }

        return maxWidth;
    }
};