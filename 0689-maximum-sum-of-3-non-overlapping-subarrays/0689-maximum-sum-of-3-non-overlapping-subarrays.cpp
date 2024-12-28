class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> window_sum(n - k + 1);

        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        window_sum[0] = sum;
        for (int i = 1; i <= n - k; ++i) {
            sum += nums[i + k - 1] - nums[i - 1];
            window_sum[i] = sum;
        }

        vector<int> left(n - k + 1);
        int best = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (window_sum[i] > window_sum[best]) {
                best = i;
            }
            left[i] = best;
        }

        vector<int> right(n - k + 1);
        best = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (window_sum[i] >= window_sum[best]) {
                best = i;
            }
            right[i] = best;
        }

        vector<int> result(3);
        int max_sum = 0;
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = window_sum[l] + window_sum[mid] + window_sum[r];
            if (total > max_sum) {
                max_sum = total;
                result = {l, mid, r};
            }
        }

        return result;
    }
};