class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> numSet(nums.begin(),nums.end());
        if(*numSet.begin() < k) return -1;
        numSet.erase(k);
        return numSet.size();
    }
};