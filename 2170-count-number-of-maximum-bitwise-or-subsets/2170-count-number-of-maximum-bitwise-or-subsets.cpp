class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }

        int countMaxOrSubsets = 0;
        const int totalSubsets = 1 << nums.size();
        for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) {
            int currentOr = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if ((1 << i) & subsetMask) {
                    currentOr |= nums[i];
                }
            }
            if (currentOr == maxOrValue) {
                ++countMaxOrSubsets;
            }
        }

        return countMaxOrSubsets;
    }
};
