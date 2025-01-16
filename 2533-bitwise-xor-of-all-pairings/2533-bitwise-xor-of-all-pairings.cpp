class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bits(32);
        countBits(bits, nums1, nums2.size() % 2);
        countBits(bits, nums2, nums1.size() % 2);
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            if(bits[i] == 0 || bits[i] % 2 == 0) continue;
            ans |= (1 << i);
        }
        return ans;
    }
private:
    void countBits(vector<int>& bits, const vector<int>& nums, int val){
        for(int num : nums){
            for(int j = 0; j < 32; ++j){
                if(num & (1 << j)){
                    bits[j] += val;
                }
            }
        }
        return ;
    }
};