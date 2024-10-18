class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums){
            maxOr |= num;
        }
        int numSubset = 0;
        const int n = 1 << nums.size();
        for(int subset = 0; subset < n; ++subset){
            int sub = 0;
            for(int i = 0; i < nums.size(); ++i){
                if ((1 << i) & subset){
                    sub |= nums[i];
                }
            }
            if (maxOr == sub){
                ++numSubset;
            }
        }
        return numSubset;
    }
};