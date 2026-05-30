class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIdx;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(lastIdx.find(num) != lastIdx.end() && i - lastIdx[num] <= k) return true;
            lastIdx[num] = i;
        }

        return false;
    }
};