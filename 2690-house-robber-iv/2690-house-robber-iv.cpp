class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            int possible = 0;

            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) {
                    possible++;
                    ++i;
                }
            }

            if (possible >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    };
};