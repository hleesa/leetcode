class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curMax = nums[0];
        int maxSum = nums[0];
        int curMin = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(curMax, maxSum);
            curMin = min(nums[i], curMin + nums[i]);
            minSum = min(curMin, minSum);
        }
        return max(maxSum, abs(minSum));
    }
};