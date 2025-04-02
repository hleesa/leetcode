class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    long long candi = static_cast<long long>(nums[i] - nums[j]) * nums[k];
                    if(candi > ans) ans = candi;
                }
            }
        }
        if(ans < 0) ans = 0;
        return ans;
    }
};