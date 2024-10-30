class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        vector<int> asc(n), desc(n);
        for(int i = 0; i < n; ++i){
            asc[i] = 1;
            desc[n-1-i] = 1;
            for(int j = 0; j < i; ++j){
                if (nums[i] > nums[j]){
                    asc[i] = max(asc[i], asc[j] + 1);
                }
                if(nums[n-1-i] > nums[n-1-j]){
                    desc[n-1-i] = max(desc[n-1-i], desc[n-1-j] + 1);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i + 1 < n; ++i){
            if(asc[i] > 1 && desc[i] > 1){
                ans = max(asc[i] + desc[i] - 1, ans);
            }
        }
        return n - ans;
    }
};