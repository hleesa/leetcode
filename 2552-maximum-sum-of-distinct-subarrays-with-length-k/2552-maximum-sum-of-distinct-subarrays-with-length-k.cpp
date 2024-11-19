class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int dup = 0;
        map<int, int> counter;
        for (int i = 0; i + 1 < k; ++i) {
            int num = nums[i];
            sum += num;
            ++counter[num];
            if (counter[num] > 1) {
                ++dup;
            }
        }
        long long ans = 0;
        for (int i = k -1; i< nums.size(); ++i) {
            int num = nums[i];
            sum += num;
            ++counter[num];
            if (counter[num] > 1) {
                ++dup;
            }
            if (dup == 0 && sum > ans) {
                ans = sum;
            }
            int prev = nums[i - k + 1];
            sum -= prev;
            --counter[prev];
            if (counter[prev] > 0) {
                --dup;
            }
        }
        return ans;
    }
};