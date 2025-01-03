class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int n = nums.size();
        vector<long long> psum(n);

        psum.front() = nums.front();
        for(int i = 1; i < n; ++i){
            psum[i] = nums[i] + psum[i-1];
        }

        int numValidSplit = 0;
        for(int i = 0; i + 1 < n; ++i){
            if(psum[i] >= psum.back() - psum[i]){
                ++numValidSplit;
            }
        }
        return numValidSplit;
    }
};
