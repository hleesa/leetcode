class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k), nums(nums.begin(), nums.end()){
    }
    
    int add(int val) {
        nums.insert(val);
        auto rit = nums.rbegin();
        advance(rit, k - 1);
        return rit == nums.rend() ? 0 : *rit;
    }

private:
    int k;
    multiset<int> nums;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
