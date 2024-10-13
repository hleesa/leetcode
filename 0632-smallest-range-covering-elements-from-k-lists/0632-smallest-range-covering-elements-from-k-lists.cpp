class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();
        using Element = pair<int, pair<int,int>>;

        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        int maxVal = numeric_limits<int>::min();

        for(int i = 0; i < k; ++i){
            minHeap.push({nums[i][0], {i,0}});
            maxVal = max(nums[i][0], maxVal);
        }

        int rangeStart = 0, rangeEnd = numeric_limits<int>::max();

        while(true){
            auto [minVal, pos] = minHeap.top();
            minHeap.pop();
            int row = pos.first, col = pos.second;

            if (maxVal - minVal < rangeEnd - rangeStart || (maxVal - minVal == rangeEnd - rangeStart && minVal < rangeStart)){
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            if (col + 1 == nums[row].size()){
                break;
            }

            int nextVal = nums[row][col+1];
            minHeap.push({nextVal, {row, col+1}});
            maxVal = max(nextVal, maxVal);
        }

        return {rangeStart, rangeEnd};
    }
};