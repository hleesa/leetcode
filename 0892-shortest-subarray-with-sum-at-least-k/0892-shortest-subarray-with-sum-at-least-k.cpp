class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> psum(n+1);
        for(int i = 0; i < n; ++i){
            psum[i+1] = psum[i] + nums[i];
        }

        vector<int> q(n+1);
        int l = 0 , r = 0;
        int minLen = n + 1;

        for(int i = 0; i < psum.size(); ++i){
            while(r > l && psum[i] >= psum[q[l]] + k){
                minLen = min(i - q[l++], minLen);
            }
            while(r > l && psum[i] <= psum[q[r-1]]){
                --r;
            }
            q[r++] = i;
        }
        
        return minLen > n ? -1 : minLen;
    }
};
