class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(int num : nums){
            sum = (sum + num) % p;
        }
        if (sum == 0){
            return 0;
        }

        int targetRem = sum;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = -1;

        int curSum = 0;
        int minLen = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            curSum = (curSum + nums[i]) % p;
            int rem = (curSum - targetRem + p) % p;

            if (prefixSum.find(rem) != prefixSum.end()){
                minLen = min(minLen, i - prefixSum[rem]);
            }
            prefixSum[curSum] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};