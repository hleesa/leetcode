class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for(int num : nums){
            if(num == 1) totalOnes++;
        }

        int currentOnes = 0;
        for(int i = 0; i < totalOnes; ++i){
            if(nums[i] == 1) currentOnes++;
        }

        int maxOnesInWindow = currentOnes;
        for(int i=1; i<n; ++i){
            if(nums[i-1] == 1) currentOnes--;
            if(nums[(i+totalOnes-1)%n] == 1) currentOnes++;
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
    }
};